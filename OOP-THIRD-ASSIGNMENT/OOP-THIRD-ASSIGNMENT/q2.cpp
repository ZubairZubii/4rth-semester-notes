#include<iostream>
#include<string>
using namespace std;

class Creature {
public:
    string name;
    int level;
    int health_points;
    int force;
    int position;

    Creature() {
        level = 0;
        health_points = 0;
        force = 0;
        position = 0;
    }

    Creature(const string n, int l, int h, int f, int p) {
        name = n;
        level = l;
        health_points = h;
        force = f;
        position = p;
    }

    bool alive() {
        if (health_points > 0)
            return true;
        else
            return false;
    }

    int AttackPoints() {
        if (alive())
            return level * force;
        else
            return 0;
    }

    void Move(int pos) {
        position += pos;
    }

    void GoodBye() {
        cout << name << "is no more!" << endl;
    }

    void Weak(int point) {
        if (alive()) {
            health_points -= point;
        }
        if (!alive()) {
            health_points = 0;
            GoodBye();
        }

    }

    void display() {
        cout << name << ", " << "level:" << level << ", " << "health_status:" << health_points << ", " << "force:" << force << ", " << "Attacking_point:" << AttackPoints() << ", " << "postion:" << position << "" << endl;
    }


};

class Dragon : public Creature {
public:
    int range_of_flame;
    Dragon() {
        range_of_flame = 0;
    }

    Dragon(string n, int l, int h, int f, int rof, int p = 0) : Creature(n, l, h, f, p) {
        range_of_flame = rof;
    }

    void Fly(int pos) {
        Move(pos);
    }

    void BlowFlame(Creature& another) {
        if (!alive() || !another.alive())
            return;

        int distanceDragoncreature = 0;
        if (position > another.position) {
            distanceDragoncreature = position - another.position;
        }
        else
            distanceDragoncreature = another.position - position;


        if (distanceDragoncreature <= range_of_flame) {
            int attackpoint = AttackPoints();
            int dragonweakness = distanceDragoncreature;
            another.Weak(attackpoint + dragonweakness);
            Weak(dragonweakness);

            if (!another.alive()) {
                level++;
            }

        }
    }

};

class Ichneumon : public Creature {
public:
    int neck_length;
    int poison_dose;
    Ichneumon() {
        neck_length = 0;
        poison_dose = 0;
    }


    Ichneumon(string n, int l, int h, int f, int nl, int pd, int p) : Creature(n, l, h, f, p) {
        neck_length = nl;
        poison_dose = pd;
    }

    void InjectPoison(Creature& another) {
        if (!alive() || !another.alive())
            return;

        int distanceIchneumoncreature = 0;
        if (position > another.position) {
            distanceIchneumoncreature = position - another.position;
        }
        else
            distanceIchneumoncreature = another.position - position;


        if (distanceIchneumoncreature <= neck_length) {
            int Dragonattackpoint = AttackPoints();
            another.Weak(Dragonattackpoint + poison_dose);


            if (!another.alive()) {
                level++;
            }

        }
    }



};

void Fight(Dragon& dragon, Ichneumon& ichneumon) {
    ichneumon.InjectPoison(dragon);
    dragon.BlowFlame(ichneumon);
}



int main()
{
    Dragon dragon("Dragon red", 2, 10, 3, 20);
    Ichneumon  ichneumon("ichneumon evil", 2, 10, 1, 10, 1, 42);

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
    dragon.Fly(ichneumon.position - 1);
    dragon.display();

    cout << endl;
    cout << "ichneumon moves :" << endl;
    ichneumon.Move(1);
    ichneumon.display();

    cout << endl;
    cout << "2nd Fight :" << endl;
    cout << ""
        << "+ ichneumon inflicts a 3-point attack on dragon\n"
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
