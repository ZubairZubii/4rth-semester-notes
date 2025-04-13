/*-------------------------Main----------------------------------*/
#include <iostream>
using namespace std;
int main()
{
  Dragon dragon("Dragon red"   , 2, 10, 3, 20         );
  Ichneumon  ichneumon ("ichneumon evil", 2, 10, 1, 10, 1,  42 );

  dragon.display();
  cout << "is preparing for fight with :" << endl;
  ichneumon.display();

  cout << endl;
  cout << "1st Fight :" << endl;
  cout << "    the creature-s are not within range, so can not Attacke."
       << endl;
  Fight(dragon, ichneumon);

  cout << "After the Fight :" << endl;
  dragon.display();
  ichneumon.display();

  cout << endl;
  cout << "Dragon has flown close to ichneumon :" << endl;
  dragon.Fly(ichneumon.position() - 1);
  dragon.display();

  cout << endl;
  cout << "ichneumon moves :" << endl;
  ichneumon.Move(1);
  ichneumon.display();

  cout << endl;
  cout << "2nd Fight :" << endl;
  cout << ""
  <<"+ ichneumon inflicts a 3-point attack on dragon\n"
     " [ level (2) * force (1) + poison (1) = 3 ] ;\n"
  "+ Dragon inflicts a 6-point attack on ichneumon\n"
      "[ level (2) * force (3) = 6 ] ;\n"
  "+ during his attack, dragon loses two additional points\n"
"      [ corresponding to the distance between dragon and ichneumon : 43 - 41 = 2 ]." << endl;
  Fight(dragon, ichneumon);

  cout << "After the Fight :" << endl;
  dragon.display();
  ichneumon.display();

  cout << endl;
  cout << "Dragon moves by one step " << endl;
  dragon.Move(1);
  dragon.display();

  cout << endl;
  cout << "3rd Fight :" << endl;
  cout << "  + ichneumon inflicts a 3-point attack on dragon \n "
  "    [ level (2) * force (1) + poison (1) = 3 ] ; \n "
  "+ Dragon inflicts a 6-point attack on ichneumon \n "
"      [ level (2) * force (3) = 6 ] ; \n"
  "+ during his attack, dragon lost 1 additional life point.\n"
       "[ corresponding to the distance between dragon and ichneumon : 43 - 42 = 1 ] ;\n"
  "+ ichneumon is defeated and the dragon rises to level 3" << endl;
  Fight(dragon, ichneumon);

  cout << "After the Fight :" << endl;
  dragon.display();
  ichneumon.display();

  cout << endl;
  cout << "4th Fight :" << endl;
  cout << "    when one creatures is defeated, nothing happpens" << endl;
  Fight(dragon, ichneumon);

  cout << "After the Fight :" << endl;
  dragon.display();
  ichneumon.display();

  return 0;
}


#include <iostream>
#include <string>
#include <cmath>

class Creature {
protected:
    const std::string name_;
    int level_;
    int health_;
    int force_;
    int position_;

public:
    Creature(const std::string& name, int level, int health, int force, int position = 0)
        : name_{ name }, level_{ level }, health_{ health }, force_{ force }, position_{ position }
    {}

    bool alive() const {
        return health_ > 0;
    }

    int AttackPoints() const {
        if (alive())
            return level_ * force_;
        else
            return 0;
    }

    void Move(int distance) {
        position_ += distance;
    }

    void GoodBye() const {
        std::cout << name_ << " is no more!" << std::endl;
    }

    void Weak(int points) {
        if (alive()) {
            health_ -= points;
            if (!alive())
                GoodBye();
        }
    }

    void Display() const {
        std::cout << name_ << ", level: " << level_ << ", health_status: " << health_
            << ", force: " << force_ << ", Attacking Points: " << AttackPoints()
            << ", position: " << position_ << std::endl;
    }

    int getPosition() const {
        return position_;
    }
};

class Dragon : public Creature {
    int flame_range_;

public:
    Dragon(const std::string& name, int level, int health, int force, int flame_range, int position = 0)
        : Creature{ name, level, health, force, position }, flame_range_{ flame_range }
    {}

    void Fly(int position) {
        Move(position - position_);
    }

    void BlowFlame(Creature& creature) {
        if (!alive() || !creature.alive())
            return;

        int distance = std::abs(position_ - creature.getPosition());

        if (distance <= flame_range_) {
            int attack_points = AttackPoints();
            int dragon_damage = distance;
            int creature_damage = attack_points + dragon_damage;

            creature.Weak(creature_damage);
            Weak(dragon_damage);

            if (!creature.alive()) {
                level_++;
            }
        }
    }
};

class Ichneumon : public Creature {
    int neck_length_;
    int poison_dose_;

public:
    Ichneumon(const std::string& name, int level, int health, int force, int neck_length, int poison_dose, int position = 0)
        : Creature{ name, level, health, force, position }, neck_length_{ neck_length }, poison_dose_{ poison_dose }
    {}

    void InjectPoison(Creature& creature) {
        if (!alive() || !creature.alive())
            return;

        int distance = std::abs(position_ - creature.getPosition());

        if (distance <= neck_length_) {
            int attack_points = AttackPoints();
            int creature_damage = attack_points + poison_dose_;

            creature.Weak(creature_damage);

            if (!creature.alive()) {
                level_++;
            }
        }
    }
};

void Fight(Dragon& dragon, Ichneumon& ichneumon) {
    ichneumon.InjectPoison(dragon);
    dragon.BlowFlame(ichneumon);
}

