#include "Team.hpp"

using namespace std;

namespace ariel
{

    Team::Team() : leader(new Character())
    {
    }

    Team::Team(Character *lead)
    {
        this->leader = lead;
        this->add(lead);
    }
    //Copy assignment operator
    Team &Team::operator=(const Team &other) {
    if (this != &other) {
        this->leader = other.leader;
        for (Character *c : other.team_v) {
            this->add(c);
        }
    }
    return *this;
}

//Move constructor
Team::Team(Team &&other) noexcept : leader(other.leader), team_v(move(other.team_v)) {
    other.leader = nullptr;
}

//Move assignment operator
Team &Team::operator=(Team &&other) noexcept {
    if (this != &other) {
        for (Character *c : team_v) {
            delete c;
        }
        team_v.clear();

        leader = other.leader;
        team_v = move(other.team_v);
        other.leader = nullptr;
    }
    return *this;
}



    Team::~Team()
    {
        for (Character *c : this->team_v)
        {
            delete c;
        }
        team_v.clear();
        leader = nullptr;
        // for (Character *n : this->Ninja_team)
        // {
        // delete n;
        //}
        // Ninja_team.clear();
        // //leader = nullptr;
        // for (Character *c : this->Cowboy_team)
        // {
        // delete c;
        // }
        // Cowboy_team.clear();
        // leader = nullptr;
    }

    // void Team::creat_team(){}
    void Team::add(Character *player)
    {
        if (team_v.size() < 10)
        {
            if (player->get_playing())
                __throw_runtime_error("The player is already playing!!");
            if (Ninja *n = dynamic_cast<Ninja *>(player))
            {
                Ninja_team.push_back(n);
            }
            if (Cowboy *c = dynamic_cast<Cowboy *>(player))
            {
                Cowboy_team.push_back(c);
            }
            team_v.push_back(player);
            player->change();
        }
        else
            __throw_runtime_error(" The team is full");
    }

    Character *Team::new_leader(Team *team)
    {
        // double min;
        double closest = numeric_limits<double>::max();
        Character *temp_ch = team->team_v[0];
        for (size_t i = 0; i < team->team_v.size(); i++)
        {
            if (team->team_v[i]->isAlive())
            {
                double temp = team->leader->distance(team->team_v[i]);
                if (temp < closest)
                {
                    closest = temp;
                    temp_ch = team->team_v[i];
                }
            }
        }

        return temp_ch;
    }

    Character *Team::new_target(Team *enemy)
    {
        double closest = numeric_limits<double>::max();
        Character *temp_en = enemy->team_v[0];
        for (size_t i = 0; i < enemy->team_v.size(); i++)
        {
            if (enemy->team_v[i]->isAlive())
            {
                double temp = this->leader->distance(enemy->team_v[i]);
                if (temp < closest)
                {
                    closest = temp;
                    temp_en = enemy->team_v[i];
                }
            }
        }
        return temp_en;
    }

    void Team::attack(Team *enemy)
    { // not finish
        if (enemy == nullptr)
        {
            __throw_invalid_argument("Enemy is NULL");
        }
        if (enemy->stillAlive() == 0)
        {
            __throw_runtime_error("Dead enemy team");
        }
        if (!this->leader->isAlive())
        {
            this->leader = new_leader(this);
        }
        Character *enemy_target = new_target(enemy);
        // enemy_target = new_target(enemy);
        if (this->stillAlive())
        {
            for (size_t i = 0; i < this->Cowboy_team.size(); i++)
            {
                if (!this->Cowboy_team[i]->isAlive())
                {
                    continue;
                }
                if (enemy_target->isAlive())
                {
                    if (this->Cowboy_team[i]->hasboolets())
                    {
                        cout << "Enemy hp = " << enemy_target->getPoints() << endl;

                        this->Cowboy_team[i]->shoot(enemy_target);
                    }
                    else
                    {
                        this->Cowboy_team[i]->reload();
                    }
                }
                if (enemy->stillAlive())
                {
                    enemy_target = new_target(enemy);
                }
            }
            for (size_t j = 0; j < Ninja_team.size(); j++)
            {
                if (!this->Ninja_team[j]->isAlive())
                {
                    continue;
                }
                if (enemy_target->isAlive())
                {
                    if (this->Ninja_team[j]->distance(enemy_target) < 1)
                    {
                        cout << "Enemy hp = " << enemy_target->getPoints() << endl;
                        Ninja_team[j]->slash(enemy_target);
                    }
                    else
                    {
                        Ninja_team[j]->move(enemy_target);
                    }
                }
                if (enemy->stillAlive())
                {
                    enemy_target = new_target(enemy);
                }
            }
            // if(!enemy_target->isAlive())
            // {
            //     enemy_target = new_target(enemy);
            // }
        }
    }

    int Team::stillAlive()
    {
        team_counter = 0;
        for (size_t i = 0; i < team_v.size(); i++)
        {
            if (this->team_v[i]->isAlive())
            {
                team_counter++;
            }
        }
        return team_counter;
    }

    void Team::print()
    {
        for (auto i : team_v)
            cout << i->print() << "\n"
                 << endl;
    }

    Team2::Team2(Character *leader) : Team(leader) {}

    void Team2::print()
    {
        for (auto i : team_v)
            cout << i->print() << "\n"
                 << endl;
    }

    void Team2::attack(Team *enemy)
    {
        if (enemy == nullptr)
        {
            __throw_invalid_argument("Enemy is NULL");
        }
        if (enemy->stillAlive() == 0)
        {
            __throw_runtime_error("Dead enemy team");
        }
        if (!this->leader->isAlive())
        {
            this->leader = new_leader(this);
        }
        Character *enemy_target = new_target(enemy);
        if (this->stillAlive())
        {
            for (size_t j = 0; j < team_v.size(); j++)
            {
                if (!this->team_v[j]->isAlive())
                {
                    continue;
                }
                if (enemy_target->isAlive())
                {
                    if (Ninja *n = dynamic_cast<Ninja *>(this->team_v[j]))
                    {
                        if (n->distance(enemy_target) < 1)
                        {
                            n->slash(enemy_target);
                        }
                        else
                        {
                            n->move(enemy_target);
                        }
                    }
                    if (Cowboy *n = dynamic_cast<Cowboy *>(this->team_v[j]))
                    {
                        if (n->hasboolets())
                        {
                            n->shoot(enemy_target);
                        }
                        else
                        {
                            n->reload();
                        }
                    }
                }
                if (enemy->stillAlive())
                {
                    enemy_target = new_target(enemy);
                }
            }
        }
    }

    SmartTeam::SmartTeam(Character *leader) : Team(leader)
    {
    }

    // SmartTeam::~SmartTeam(){}
    void SmartTeam::print()
    {
        for (auto i : team_v)
            cout << i->print() << "\n"
                 << endl;
    }
};
