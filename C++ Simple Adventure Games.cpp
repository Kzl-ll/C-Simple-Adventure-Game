#include <iostream>
#include <string>

using namespace std;

// Struktur untuk pemain
struct Pemain {
    string nama;
    int hp;
    int attack;
    int defense;
    int level;
    int xp;
    int potion;
};

// Struktur untuk musuh
struct Musuh {
    string nama;
    int hp;
    int attack;
    int defense;
};

// Fungsi untuk membuat musuh
Musuh Goblin() {
    string musuh = "Goblin";
    return {musuh, 50, 10, 5};
}
Musuh GoblinKing() {
    string musuh = "Goblin King";
    return {musuh, 300, 98, 34};
}
Musuh Serigala() {
    string musuh = "Serigala";
    return {musuh, 72, 15, 5};
}
Musuh Slime() {
    string musuh = "Slime";
    return {musuh, 30, 5, 3};
}
Musuh Orc() {
    string musuh = "Orc";
    return {musuh, 250, 50, 90};
}
Musuh Wyvern() {
    string musuh = "Wyvern";
    return {musuh, 829, 219, 105};
}
Musuh Naga() {
    string musuh = "Naga";
    return {musuh, 1000, 542, 234};
}
Musuh Bandit(){
    string musuh = "Bandit";
    return {musuh, 500, 374, 293};
}
Musuh Petinggi1(){
    string musuh = "Komandan Prajurit Ras Cahaya";
    return {musuh, 1500, 524, 433};
}
Musuh Petinggi2(){
    string musuh = "Eksekutif Ras Cahaya";
    return {musuh, 2000, 826, 397};
}
Musuh Petinggi3(){
    string musuh = "Kepala Negara Ras Cahaya";
    return {musuh, 3000, 1500, 900};
}
Musuh PetinggiKegelapan1(){
    string musuh = "Komandan Prajurit Ras Kegelapan";
    return {musuh, 1289, 749, 340};
}
Musuh PetinggiKegelapan2(){
    string musuh = "Ekskutif Ras Kegelapan";
    return {musuh, 2297, 673, 500};
}
Musuh PetinggiKegelapan3(){
    string musuh = "Kepala Negara Ras Kegelapan";
    return {musuh, 2893, 1700, 800};
}
Musuh Lyvia(){
    string musuh = "Lyvia";
    return {musuh, 9273729, 872732, 232864};
}
// Fungsi untuk melawan musuh

void lawanPetinggiKegelapan1(Pemain &pemain) {
    Musuh musuh = PetinggiKegelapan1();
    cout << "Anda bertemu " << musuh.nama << "! HP Musuh: " << musuh.hp << endl;
    while (musuh.hp > 0 && pemain.hp > 0) {
        cout << "\nAksi Anda:\n";
        cout << "1. Serang\n2. Bertahan\n3. Gunakan Potion\n";
        cout << "Pilihan: ";
        int aksi;
        int Aksi;
        cin >> aksi;
        int damage;
        if (aksi == 1) {
            damage = pemain.attack - musuh.defense;
            if (damage <= 0) {
                damage = 1;
            }
            musuh.hp -= damage;
            cout << "Anda menyerang " << musuh.nama << " dengan damage: " << damage << endl;
        } else if (aksi == 2) {
            cout << "Anda bertahan, mengurangi damage musuh.\n";
            pemain.defense += 10;
            Aksi = 2;
        } else if (aksi == 3) {
            if (pemain.potion > 0) {
                pemain.hp += 25;
                pemain.potion--;
                cout << "Anda menggunakan potion.\n" << " Potion anda tersisa : " << pemain.potion << ". HP Anda sekarang: " << pemain.hp << endl;
            } else {
                cout << "Anda tidak memiliki potion!\n";
            }
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    
        // Serangan musuh
        int damageMusuh = musuh.attack - pemain.defense;
            if (damageMusuh <= 0) {
                damageMusuh = 1;
            }
        pemain.hp -= damageMusuh;
        cout << musuh.nama << " menyerang Anda dengan damage: " << damageMusuh << endl;
        if (Aksi == 2) {
            pemain.defense -= 10;
            Aksi = 1;
        }
            
        if (musuh.hp <= 0) {
            musuh.hp = 0;
        }
        if (pemain.hp <= 0) {
            pemain.hp = 0;
        }
        cout << "HP Anda: " << pemain.hp << " | HP " << musuh.nama << ": " << musuh.hp << endl;
        
        if (pemain.hp <= 0) {
            cout << "Anda kalah dalam pertempuran...\n";
            return;
        }
    }
    
    if (musuh.hp <= 0) {
        cout << musuh.nama << " dikalahkan!\n";
        pemain.xp += 1000;
        cout << "Anda mendapatkan 1000 XP. Total XP: " << pemain.xp << endl;

        // Level up
        if (pemain.xp >= pemain.level * 50) {
            pemain.level+=20;
            pemain.hp += 1000;
            pemain.attack += 500;
            pemain.defense += 300;
            cout << "Selamat! Anda naik level ke " << pemain.level << "!\n";
        }
    }
}

void lawanPetinggi1(Pemain &pemain) {
    Musuh musuh = Petinggi1();
    cout << "Anda bertemu " << musuh.nama << "! HP Musuh: " << musuh.hp << endl;
    while (musuh.hp > 0 && pemain.hp > 0) {
        cout << "\nAksi Anda:\n";
        cout << "1. Serang\n2. Bertahan\n3. Gunakan Potion\n";
        cout << "Pilihan: ";
        int aksi;
        int Aksi;
        cin >> aksi;
        int damage;
        if (aksi == 1) {
            damage = pemain.attack - musuh.defense;
            if (damage <= 0) {
                damage = 1;
            }
            musuh.hp -= damage;
            cout << "Anda menyerang " << musuh.nama << " dengan damage: " << damage << endl;
        } else if (aksi == 2) {
            cout << "Anda bertahan, mengurangi damage musuh.\n";
            pemain.defense += 10;
            Aksi = 2;
        } else if (aksi == 3) {
            if (pemain.potion > 0) {
                pemain.hp += 25;
                pemain.potion--;
                cout << "Anda menggunakan potion.\n" << " Potion anda tersisa : " << pemain.potion << ". HP Anda sekarang: " << pemain.hp << endl;
            } else {
                cout << "Anda tidak memiliki potion!\n";
            }
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    
        // Serangan musuh
        int damageMusuh = musuh.attack - pemain.defense;
            if (damageMusuh <= 0) {
                damageMusuh = 1;
            }
        pemain.hp -= damageMusuh;
        cout << musuh.nama << " menyerang Anda dengan damage: " << damageMusuh << endl;
        if (Aksi == 2) {
            pemain.defense -= 10;
            Aksi = 1;
        }
            
        if (musuh.hp <= 0) {
            musuh.hp = 0;
        }
        if (pemain.hp <= 0) {
            pemain.hp = 0;
        }
        cout << "HP Anda: " << pemain.hp << " | HP " << musuh.nama << ": " << musuh.hp << endl;
        
        if (pemain.hp <= 0) {
            cout << "Anda kalah dalam pertempuran...\n";
            return;
        }
    }
    
    if (musuh.hp <= 0) {
        cout << musuh.nama << " dikalahkan!\n";
        pemain.xp += 1000;
        cout << "Anda mendapatkan 1000 XP. Total XP: " << pemain.xp << endl;

        // Level up
        if (pemain.xp >= pemain.level * 50) {
            pemain.level+=20;
            pemain.hp += 1000;
            pemain.attack += 500;
            pemain.defense += 300;
            cout << "Selamat! Anda naik level ke " << pemain.level << "!\n";
        }
    }
}

void lawanPetinggiKegelapan2(Pemain &pemain) {
    Musuh musuh = PetinggiKegelapan2();
    cout << "Anda bertemu " << musuh.nama << "! HP Musuh: " << musuh.hp << endl;
    while (musuh.hp > 0 && pemain.hp > 0) {
        cout << "\nAksi Anda:\n";
        cout << "1. Serang\n2. Bertahan\n3. Gunakan Potion\n";
        cout << "Pilihan: ";
        int aksi;
        int Aksi;
        cin >> aksi;
        int damage;
        if (aksi == 1) {
            damage = pemain.attack - musuh.defense;
            if (damage <= 0) {
                damage = 1;
            }
            musuh.hp -= damage;
            cout << "Anda menyerang " << musuh.nama << " dengan damage: " << damage << endl;
        } else if (aksi == 2) {
            cout << "Anda bertahan, mengurangi damage musuh.\n";
            pemain.defense += 10;
            Aksi = 2;
        } else if (aksi == 3) {
            if (pemain.potion > 0) {
                pemain.hp += 25;
                pemain.potion--;
                cout << "Anda menggunakan potion.\n" << " Potion anda tersisa : " << pemain.potion << ". HP Anda sekarang: " << pemain.hp << endl;
            } else {
                cout << "Anda tidak memiliki potion!\n";
            }
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    
        // Serangan musuh
        int damageMusuh = musuh.attack - pemain.defense;
            if (damageMusuh <= 0) {
                damageMusuh = 1;
            }
        pemain.hp -= damageMusuh;
        cout << musuh.nama << " menyerang Anda dengan damage: " << damageMusuh << endl;
        if (Aksi == 2) {
            pemain.defense -= 10;
            Aksi = 1;
        }
            
        if (musuh.hp <= 0) {
            musuh.hp = 0;
        }
        if (pemain.hp <= 0) {
            pemain.hp = 0;
        }
        cout << "HP Anda: " << pemain.hp << " | HP " << musuh.nama << ": " << musuh.hp << endl;
        
        if (pemain.hp <= 0) {
            cout << "Anda kalah dalam pertempuran...\n";
            return;
        }
    }
    
    if (musuh.hp <= 0) {
        cout << musuh.nama << " dikalahkan!\n";
        pemain.xp += 2000;
        cout << "Anda mendapatkan 2000 XP. Total XP: " << pemain.xp << endl;

        // Level up
        if (pemain.xp >= pemain.level * 50) {
            pemain.level+=40;
            pemain.hp += 2000;
            pemain.attack += 1000;
            pemain.defense += 600;
            cout << "Selamat! Anda naik level ke " << pemain.level << "!\n";
        }
    }
}

void lawanPetinggi2(Pemain &pemain) {
    Musuh musuh = Petinggi2();
    cout << "Anda bertemu " << musuh.nama << "! HP Musuh: " << musuh.hp << endl;
    while (musuh.hp > 0 && pemain.hp > 0) {
        cout << "\nAksi Anda:\n";
        cout << "1. Serang\n2. Bertahan\n3. Gunakan Potion\n";
        cout << "Pilihan: ";
        int aksi;
        int Aksi;
        cin >> aksi;
        int damage;
        if (aksi == 1) {
            damage = pemain.attack - musuh.defense;
            if (damage <= 0) {
                damage = 1;
            }
            musuh.hp -= damage;
            cout << "Anda menyerang " << musuh.nama << " dengan damage: " << damage << endl;
        } else if (aksi == 2) {
            cout << "Anda bertahan, mengurangi damage musuh.\n";
            pemain.defense += 10;
            Aksi = 2;
        } else if (aksi == 3) {
            if (pemain.potion > 0) {
                pemain.hp += 25;
                pemain.potion--;
                cout << "Anda menggunakan potion.\n" << " Potion anda tersisa : " << pemain.potion << ". HP Anda sekarang: " << pemain.hp << endl;
            } else {
                cout << "Anda tidak memiliki potion!\n";
            }
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    
        // Serangan musuh
        int damageMusuh = musuh.attack - pemain.defense;
            if (damageMusuh <= 0) {
                damageMusuh = 1;
            }
        pemain.hp -= damageMusuh;
        cout << musuh.nama << " menyerang Anda dengan damage: " << damageMusuh << endl;
        if (Aksi == 2) {
            pemain.defense -= 10;
            Aksi = 1;
        }
            
        if (musuh.hp <= 0) {
            musuh.hp = 0;
        }
        if (pemain.hp <= 0) {
            pemain.hp = 0;
        }
        cout << "HP Anda: " << pemain.hp << " | HP " << musuh.nama << ": " << musuh.hp << endl;
        
        if (pemain.hp <= 0) {
            cout << "Anda kalah dalam pertempuran...\n";
            return;
        }
    }
    
    if (musuh.hp <= 0) {
        cout << musuh.nama << " dikalahkan!\n";
        pemain.xp += 2000;
        cout << "Anda mendapatkan 2000 XP. Total XP: " << pemain.xp << endl;

        // Level up
        if (pemain.xp >= pemain.level * 50) {
            pemain.level+=40;
            pemain.hp += 2000;
            pemain.attack += 1000;
            pemain.defense += 600;
            cout << "Selamat! Anda naik level ke " << pemain.level << "!\n";
        }
    }
}

void lawanPetinggiKegelapan3(Pemain &pemain) {
    Musuh musuh = PetinggiKegelapan3();
    cout << "Anda bertemu " << musuh.nama << "! HP Musuh: " << musuh.hp << endl;
    while (musuh.hp > 0 && pemain.hp > 0) {
        cout << "\nAksi Anda:\n";
        cout << "1. Serang\n2. Bertahan\n3. Gunakan Potion\n";
        cout << "Pilihan: ";
        int aksi;
        int Aksi;
        cin >> aksi;
        int damage;
        if (aksi == 1) {
            damage = pemain.attack - musuh.defense;
            if (damage <= 0) {
                damage = 1;
            }
            musuh.hp -= damage;
            cout << "Anda menyerang " << musuh.nama << " dengan damage: " << damage << endl;
        } else if (aksi == 2) {
            cout << "Anda bertahan, mengurangi damage musuh.\n";
            pemain.defense += 10;
            Aksi = 2;
        } else if (aksi == 3) {
            if (pemain.potion > 0) {
                pemain.hp += 25;
                pemain.potion--;
                cout << "Anda menggunakan potion.\n" << " Potion anda tersisa : " << pemain.potion << ". HP Anda sekarang: " << pemain.hp << endl;
            } else {
                cout << "Anda tidak memiliki potion!\n";
            }
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    
        // Serangan musuh
        int damageMusuh = musuh.attack - pemain.defense;
            if (damageMusuh <= 0) {
                damageMusuh = 1;
            }
        pemain.hp -= damageMusuh;
        cout << musuh.nama << " menyerang Anda dengan damage: " << damageMusuh << endl;
        if (Aksi == 2) {
            pemain.defense -= 10;
            Aksi = 1;
        }
            
        if (musuh.hp <= 0) {
            musuh.hp = 0;
        }
        if (pemain.hp <= 0) {
            pemain.hp = 0;
        }
        cout << "HP Anda: " << pemain.hp << " | HP " << musuh.nama << ": " << musuh.hp << endl;
        
        if (pemain.hp <= 0) {
            cout << "Anda kalah dalam pertempuran...\n";
            return;
        }
    }
    
    if (musuh.hp <= 0) {
        cout << musuh.nama << " dikalahkan!\n";
        pemain.xp += 4000;
        cout << "Anda mendapatkan 50 XP. Total XP: " << pemain.xp << endl;

        // Level up
        if (pemain.xp >= pemain.level * 50) {
            pemain.level+=80;
            pemain.hp += 4000;
            pemain.attack += 2000;
            pemain.defense += 1200;
            cout << "Selamat! Anda naik level ke " << pemain.level << "!\n";
        }
    }
}


void lawanPetinggi3(Pemain &pemain) {
    Musuh musuh = Petinggi3();
    cout << "Anda bertemu " << musuh.nama << "! HP Musuh: " << musuh.hp << endl;
    while (musuh.hp > 0 && pemain.hp > 0) {
        cout << "\nAksi Anda:\n";
        cout << "1. Serang\n2. Bertahan\n3. Gunakan Potion\n";
        cout << "Pilihan: ";
        int aksi;
        int Aksi;
        cin >> aksi;
        int damage;
        if (aksi == 1) {
            damage = pemain.attack - musuh.defense;
            if (damage <= 0) {
                damage = 1;
            }
            musuh.hp -= damage;
            cout << "Anda menyerang " << musuh.nama << " dengan damage: " << damage << endl;
        } else if (aksi == 2) {
            cout << "Anda bertahan, mengurangi damage musuh.\n";
            pemain.defense += 10;
            Aksi = 2;
        } else if (aksi == 3) {
            if (pemain.potion > 0) {
                pemain.hp += 25;
                pemain.potion--;
                cout << "Anda menggunakan potion.\n" << " Potion anda tersisa : " << pemain.potion << ". HP Anda sekarang: " << pemain.hp << endl;
            } else {
                cout << "Anda tidak memiliki potion!\n";
            }
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    
        // Serangan musuh
        int damageMusuh = musuh.attack - pemain.defense;
            if (damageMusuh <= 0) {
                damageMusuh = 1;
            }
        pemain.hp -= damageMusuh;
        cout << musuh.nama << " menyerang Anda dengan damage: " << damageMusuh << endl;
        if (Aksi == 2) {
            pemain.defense -= 10;
            Aksi = 1;
        }
            
        if (musuh.hp <= 0) {
            musuh.hp = 0;
        }
        if (pemain.hp <= 0) {
            pemain.hp = 0;
        }
        cout << "HP Anda: " << pemain.hp << " | HP " << musuh.nama << ": " << musuh.hp << endl;
        
        if (pemain.hp <= 0) {
            cout << "Anda kalah dalam pertempuran...\n";
            return;
        }
    }
    
    if (musuh.hp <= 0) {
        cout << musuh.nama << " dikalahkan!\n";
        pemain.xp += 4000;
        cout << "Anda mendapatkan 50 XP. Total XP: " << pemain.xp << endl;

        // Level up
        if (pemain.xp >= pemain.level * 50) {
            pemain.level+=80;
            pemain.hp += 4000;
            pemain.attack += 2000;
            pemain.defense += 1200;
            cout << "Selamat! Anda naik level ke " << pemain.level << "!\n";
        }
    }
}

void lawanLyvia(Pemain &pemain) {
    Musuh musuh = Lyvia();
    cout << "Anda bertemu " << musuh.nama << "! HP Musuh: " << musuh.hp << endl;
    while (musuh.hp > 0 && pemain.hp > 0) {
        cout << "\nAksi Anda:\n";
        cout << "1. Serang\n2. Bertahan\n3. Gunakan Potion\n";
        cout << "Pilihan: ";
        int aksi;
        int Aksi;
        cin >> aksi;
        int damage;
        if (aksi == 1) {
            damage = pemain.attack - musuh.defense;
            if (damage <= 0) {
                damage = 1;
            }
            musuh.hp -= damage;
            cout << "Anda menyerang " << musuh.nama << " dengan damage: " << damage << endl;
        } else if (aksi == 2) {
            cout << "Anda bertahan, mengurangi damage musuh.\n";
            pemain.defense += 10;
            Aksi = 2;
        } else if (aksi == 3) {
            if (pemain.potion > 0) {
                pemain.hp += 25;
                pemain.potion--;
                cout << "Anda menggunakan potion.\n" << " Potion anda tersisa : " << pemain.potion << ". HP Anda sekarang: " << pemain.hp << endl;
            } else {
                cout << "Anda tidak memiliki potion!\n";
            }
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    
        // Serangan musuh
        int damageMusuh = musuh.attack - pemain.defense;
            if (damageMusuh <= 0) {
                damageMusuh = 1;
            }
        pemain.hp -= damageMusuh;
        cout << musuh.nama << " menyerang Anda dengan damage: " << damageMusuh << endl;
        if (Aksi == 2) {
            pemain.defense -= 10;
            Aksi = 1;
        }
            
        if (musuh.hp <= 0) {
            musuh.hp = 0;
        }
        if (pemain.hp <= 0) {
            pemain.hp = 0;
        }
        cout << "HP Anda: " << pemain.hp << " | HP " << musuh.nama << ": " << musuh.hp << endl;
        
        if (pemain.hp <= 0) {
            cout << "Anda kalah dalam pertempuran...\n";
            return;
        }
    }
    
    if (musuh.hp <= 0) {
        cout << musuh.nama << " dikalahkan!\n";
        pemain.xp += 10000;
        cout << "Anda mendapatkan 50 XP. Total XP: " << pemain.xp << endl;

        // Level up
        if (pemain.xp >= pemain.level * 50) {
            pemain.level+=200;
            pemain.hp += 10000;
            pemain.attack += 5000;
            pemain.defense += 3000;
            cout << "Selamat! Anda naik level ke " << pemain.level << "!\n";
        }
    }
}


void lawanGoblin(Pemain &pemain) {
    Musuh musuh = Goblin();
    cout << "Anda bertemu " << musuh.nama << "! HP Musuh: " << musuh.hp << endl;
    while (musuh.hp > 0 && pemain.hp > 0) {
        cout << "\nAksi Anda:\n";
        cout << "1. Serang\n2. Bertahan\n3. Gunakan Potion\n";
        cout << "Pilihan: ";
        int aksi;
        int Aksi;
        cin >> aksi;
        int damage;
        if (aksi == 1) {
            damage = pemain.attack - musuh.defense;
            if (damage <= 0) {
                damage = 1;
            }
            musuh.hp -= damage;
            cout << "Anda menyerang " << musuh.nama << " dengan damage: " << damage << endl;
        } else if (aksi == 2) {
            cout << "Anda bertahan, mengurangi damage musuh.\n";
            pemain.defense += 10;
            Aksi = 2;
        } else if (aksi == 3) {
            if (pemain.potion > 0) {
                pemain.hp += 25;
                pemain.potion--;
                cout << "Anda menggunakan potion.\n" << " Potion anda tersisa : " << pemain.potion << ". HP Anda sekarang: " << pemain.hp << endl;
            } else {
                cout << "Anda tidak memiliki potion!\n";
            }
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    
        // Serangan musuh
        int damageMusuh = musuh.attack - pemain.defense;
            if (damageMusuh <= 0) {
                damageMusuh = 1;
            }
        pemain.hp -= damageMusuh;
        cout << musuh.nama << " menyerang Anda dengan damage: " << damageMusuh << endl;
        if (Aksi == 2) {
            pemain.defense -= 10;
            Aksi = 1;
        }
            
        if (musuh.hp <= 0) {
            musuh.hp = 0;
        }
        if (pemain.hp <= 0) {
            pemain.hp = 0;
        }
        cout << "HP Anda: " << pemain.hp << " | HP " << musuh.nama << ": " << musuh.hp << endl;
        
        if (pemain.hp <= 0) {
            cout << "Anda kalah dalam pertempuran...\n";
            return;
        }
    }
    
    if (musuh.hp <= 0) {
        cout << musuh.nama << " dikalahkan!\n";
        pemain.xp += 50;
        cout << "Anda mendapatkan 50 XP. Total XP: " << pemain.xp << endl;

        // Level up
        if (pemain.xp >= pemain.level * 50) {
            pemain.level++;
            pemain.hp += 50;
            pemain.attack += 25;
            pemain.defense += 15;
            cout << "Selamat! Anda naik level ke " << pemain.level << "!\n";
        }
    }
}

void lawanGoblinKing(Pemain &pemain) {
    Musuh musuh = GoblinKing();
    cout << "Anda bertemu " << musuh.nama << "! HP Musuh: " << musuh.hp << endl;
    while (musuh.hp > 0 && pemain.hp > 0) {
        cout << "\nAksi Anda:\n";
        cout << "1. Serang\n2. Bertahan\n3. Gunakan Potion\n";
        cout << "Pilihan: ";
        int aksi;
        int Aksi;
        cin >> aksi;
        int damage;
        if (aksi == 1) {
            damage = pemain.attack - musuh.defense;
            if (damage <= 0) {
                damage = 1;
            }
            musuh.hp -= damage;
            cout << "Anda menyerang " << musuh.nama << " dengan damage: " << damage << endl;
        } else if (aksi == 2) {
            cout << "Anda bertahan, mengurangi damage musuh.\n";
            pemain.defense += 10;
            Aksi = 2;
        } else if (aksi == 3) {
            if (pemain.potion > 0) {
                pemain.hp += 25;
                pemain.potion--;
                cout << "Anda menggunakan potion.\n" << " Potion anda tersisa : " << pemain.potion << ". HP Anda sekarang: " << pemain.hp << endl;
            } else {
                cout << "Anda tidak memiliki potion!\n";
            }
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    
        // Serangan musuh
        int damageMusuh = musuh.attack - pemain.defense;
            if (damageMusuh <= 0) {
                damageMusuh = 1;
            }
        pemain.hp -= damageMusuh;
        cout << musuh.nama << " menyerang Anda dengan damage: " << damageMusuh << endl;
        if (Aksi == 2) {
            pemain.defense -= 10;
            Aksi = 1;
        }
            
        if (musuh.hp <= 0) {
            musuh.hp = 0;
        }
        if (pemain.hp <= 0) {
            pemain.hp = 0;
        }
        cout << "HP Anda: " << pemain.hp << " | HP " << musuh.nama << ": " << musuh.hp << endl;
        
        if (pemain.hp <= 0) {
            cout << "Anda kalah dalam pertempuran...\n";
            return;
        }
    }
    
    if (musuh.hp <= 0) {
        cout << musuh.nama << " dikalahkan!\n";
        pemain.xp += 200;
        cout << "Anda mendapatkan 50 XP. Total XP: " << pemain.xp << endl;

        // Level up
        if (pemain.xp >= pemain.level * 50) {
            pemain.level+=4;
            pemain.hp += 200;
            pemain.attack += 100;
            pemain.defense += 60;
            cout << "Selamat! Anda naik level ke " << pemain.level << "!\n";
        }
    }
}


void lawanSlime(Pemain &pemain) {
    Musuh musuh = Slime();
    cout << "Anda bertemu " << musuh.nama << "! HP Musuh: " << musuh.hp << endl;
    while (musuh.hp > 0 && pemain.hp > 0) {
        cout << "\nAksi Anda:\n";
        cout << "1. Serang\n2. Bertahan\n3. Gunakan Potion\n";
        cout << "Pilihan: ";
        int aksi;
        int Aksi;
        cin >> aksi;
        int damage;
        if (aksi == 1) {
            damage = pemain.attack - musuh.defense;
            if (damage <= 0) {
                damage = 1;
            }
            musuh.hp -= damage;
            cout << "Anda menyerang " << musuh.nama << " dengan damage: " << damage << endl;
        } else if (aksi == 2) {
            cout << "Anda bertahan, mengurangi damage musuh.\n";
            pemain.defense += 10;
            Aksi = 2;
        } else if (aksi == 3) {
            if (pemain.potion > 0) {
                pemain.hp += 25;
                pemain.potion--;
                cout << "Anda menggunakan potion.\n" << " Potion anda tersisa : " << pemain.potion << ". HP Anda sekarang: " << pemain.hp << endl;
            } else {
                cout << "Anda tidak memiliki potion!\n";
            }
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    
        // Serangan musuh
        int damageMusuh = musuh.attack - pemain.defense;
            if (damageMusuh <= 0) {
                damageMusuh = 1;
            }
        pemain.hp -= damageMusuh;
        cout << musuh.nama << " menyerang Anda dengan damage: " << damageMusuh << endl;
        if (Aksi == 2) {
            pemain.defense -= 10;
            Aksi = 1;
        }
            
        if (musuh.hp <= 0) {
            musuh.hp = 0;
        }
        if (pemain.hp <= 0) {
            pemain.hp = 0;
        }
        cout << "HP Anda: " << pemain.hp << " | HP " << musuh.nama << ": " << musuh.hp << endl;
        
        if (pemain.hp <= 0) {
            cout << "Anda kalah dalam pertempuran...\n";
            return;
        }
    }
    
    if (musuh.hp <= 0) {
        cout << musuh.nama << " dikalahkan!\n";
        pemain.xp += 30;
        cout << "Anda mendapatkan 30 XP. Total XP: " << pemain.xp << endl;

        // Level up
        if (pemain.xp >= pemain.level * 50) {
            pemain.level++;
            pemain.hp += 50;
            pemain.attack += 25;
            pemain.defense += 15;
            cout << "Selamat! Anda naik level ke " << pemain.level << "!\n";
        }
    }
}

void lawanSerigala(Pemain &pemain) {
    Musuh musuh = Serigala();
    cout << "Anda bertemu " << musuh.nama << "! HP Musuh: " << musuh.hp << endl;
    while (musuh.hp > 0 && pemain.hp > 0) {
        cout << "\nAksi Anda:\n";
        cout << "1. Serang\n2. Bertahan\n3. Gunakan Potion\n";
        cout << "Pilihan: ";
        int aksi;
        int Aksi;
        cin >> aksi;
        int damage;
        if (aksi == 1) {
            damage = pemain.attack - musuh.defense;
            if (damage <= 0) {
                damage = 1;
            }
            musuh.hp -= damage;
            cout << "Anda menyerang " << musuh.nama << " dengan damage: " << damage << endl;
        } else if (aksi == 2) {
            cout << "Anda bertahan, mengurangi damage musuh.\n";
            pemain.defense += 10;
            Aksi = 2;
        } else if (aksi == 3) {
            if (pemain.potion > 0) {
                pemain.hp += 25;
                pemain.potion--;
                cout << "Anda menggunakan potion.\n" << " Potion anda tersisa : " << pemain.potion << ". HP Anda sekarang: " << pemain.hp << endl;
            } else {
                cout << "Anda tidak memiliki potion!\n";
            }
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    
        // Serangan musuh
        int damageMusuh = musuh.attack - pemain.defense;
            if (damageMusuh <= 0) {
                damageMusuh = 1;
            }
        pemain.hp -= damageMusuh;
        cout << musuh.nama << " menyerang Anda dengan damage: " << damageMusuh << endl;
        if (Aksi == 2) {
            pemain.defense -= 10;
            Aksi = 1;
        }
            
        if (musuh.hp <= 0) {
            musuh.hp = 0;
        }
        if (pemain.hp <= 0) {
            pemain.hp = 0;
        }
        cout << "HP Anda: " << pemain.hp << " | HP " << musuh.nama << ": " << musuh.hp << endl;
        
        if (pemain.hp <= 0) {
            cout << "Anda kalah dalam pertempuran...\n";
            return;
        }
    }
    
    if (musuh.hp <= 0) {
        cout << musuh.nama << " dikalahkan!\n";
        pemain.xp += 75;
        cout << "Anda mendapatkan 75 XP. Total XP: " << pemain.xp << endl;

        // Level up
        if (pemain.xp >= pemain.level * 50) {
            pemain.level++;
            pemain.hp += 50;
            pemain.attack += 25;
            pemain.defense += 15;
            cout << "Selamat! Anda naik level ke " << pemain.level << "!\n";
        }
    }
}

void lawanOrc(Pemain &pemain) {
    Musuh musuh = Orc();
    cout << "Anda bertemu " << musuh.nama << "! HP Musuh: " << musuh.hp << endl;
    while (musuh.hp > 0 && pemain.hp > 0) {
        cout << "\nAksi Anda:\n";
        cout << "1. Serang\n2. Bertahan\n3. Gunakan Potion\n";
        cout << "Pilihan: ";
        int aksi;
        int Aksi;
        cin >> aksi;
        int damage;
        if (aksi == 1) {
            damage = pemain.attack - musuh.defense;
            if (damage <= 0) {
                damage = 1;
            }
            musuh.hp -= damage;
            cout << "Anda menyerang " << musuh.nama << " dengan damage: " << damage << endl;
        } else if (aksi == 2) {
            cout << "Anda bertahan, mengurangi damage musuh.\n";
            pemain.defense += 10;
            Aksi = 2;
        } else if (aksi == 3) {
            if (pemain.potion > 0) {
                pemain.hp += 25;
                pemain.potion--;
                cout << "Anda menggunakan potion.\n" << " Potion anda tersisa : " << pemain.potion << ". HP Anda sekarang: " << pemain.hp << endl;
            } else {
                cout << "Anda tidak memiliki potion!\n";
            }
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    
        // Serangan musuh
        int damageMusuh = musuh.attack - pemain.defense;
            if (damageMusuh <= 0) {
                damageMusuh = 1;
            }
        pemain.hp -= damageMusuh;
        cout << musuh.nama << " menyerang Anda dengan damage: " << damageMusuh << endl;
        if (Aksi == 2) {
            pemain.defense -= 10;
            Aksi = 1;
        }
            
        if (musuh.hp <= 0) {
            musuh.hp = 0;
        }
        if (pemain.hp <= 0) {
            pemain.hp = 0;
        }
        cout << "HP Anda: " << pemain.hp << " | HP " << musuh.nama << ": " << musuh.hp << endl;
        
        if (pemain.hp <= 0) {
            cout << "Anda kalah dalam pertempuran...\n";
            return;
        }
    }
    
    if (musuh.hp <= 0) {
        cout << musuh.nama << " dikalahkan!\n";
        pemain.xp += 150;
        cout << "Anda mendapatkan 150 XP. Total XP: " << pemain.xp << endl;

        // Level up
        if (pemain.xp >= pemain.level * 50) {
            pemain.level+=3;
            pemain.hp += 150;
            pemain.attack += 75;
            pemain.defense += 45;
            cout << "Selamat! Anda naik level ke " << pemain.level << "!\n";
        }
    }
}

void lawanWyvern(Pemain &pemain) {
    Musuh musuh = Wyvern();
    cout << "Anda bertemu " << musuh.nama << "! HP Musuh: " << musuh.hp << endl;
    while (musuh.hp > 0 && pemain.hp > 0) {
        cout << "\nAksi Anda:\n";
        cout << "1. Serang\n2. Bertahan\n3. Gunakan Potion\n";
        cout << "Pilihan: ";
        int aksi;
        int Aksi;
        cin >> aksi;
        int damage;
        if (aksi == 1) {
            damage = pemain.attack - musuh.defense;
            if (damage <= 0) {
                damage = 1;
            }
            musuh.hp -= damage;
            cout << "Anda menyerang " << musuh.nama << " dengan damage: " << damage << endl;
        } else if (aksi == 2) {
            cout << "Anda bertahan, mengurangi damage musuh.\n";
            pemain.defense += 10;
            Aksi = 2;
        } else if (aksi == 3) {
            if (pemain.potion > 0) {
                pemain.hp += 25;
                pemain.potion--;
                cout << "Anda menggunakan potion.\n" << " Potion anda tersisa : " << pemain.potion << ". HP Anda sekarang: " << pemain.hp << endl;
            } else {
                cout << "Anda tidak memiliki potion!\n";
            }
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    
        // Serangan musuh
        int damageMusuh = musuh.attack - pemain.defense;
            if (damageMusuh <= 0) {
                damageMusuh = 1;
            }
        pemain.hp -= damageMusuh;
        cout << musuh.nama << " menyerang Anda dengan damage: " << damageMusuh << endl;
        if (Aksi == 2) {
            pemain.defense -= 10;
            Aksi = 1;
        }
            
        if (musuh.hp <= 0) {
            musuh.hp = 0;
        }
        if (pemain.hp <= 0) {
            pemain.hp = 0;
        }
        cout << "HP Anda: " << pemain.hp << " | HP " << musuh.nama << ": " << musuh.hp << endl;
        
        if (pemain.hp <= 0) {
            cout << "Anda kalah dalam pertempuran...\n";
            return;
        }
    }
    
    if (musuh.hp <= 0) {
        cout << musuh.nama << " dikalahkan!\n";
        pemain.xp += 300;
        cout << "Anda mendapatkan 300 XP. Total XP: " << pemain.xp << endl;

        // Level up
        if (pemain.xp >= pemain.level * 50) {
            pemain.level+=6;
            pemain.hp += 300;
            pemain.attack += 150;
            pemain.defense += 90;
            cout << "Selamat! Anda naik level ke " << pemain.level << "!\n";
        }
    }
}


void lawanNaga(Pemain &pemain) {
    Musuh musuh = Naga();
    cout << "Anda bertemu " << musuh.nama << "! HP Musuh: " << musuh.hp << endl;
    while (musuh.hp > 0 && pemain.hp > 0) {
        cout << "\nAksi Anda:\n";
        cout << "1. Serang\n2. Bertahan\n3. Gunakan Potion\n";
        cout << "Pilihan: ";
        int aksi;
        int Aksi;
        cin >> aksi;
        int damage;
        if (aksi == 1) {
            damage = pemain.attack - musuh.defense;
            if (damage <= 0) {
                damage = 1;
            }
            musuh.hp -= damage;
            cout << "Anda menyerang " << musuh.nama << " dengan damage: " << damage << endl;
        } else if (aksi == 2) {
            cout << "Anda bertahan, mengurangi damage musuh.\n";
            pemain.defense += 10;
            Aksi = 2;
        } else if (aksi == 3) {
            if (pemain.potion > 0) {
                pemain.hp += 25;
                pemain.potion--;
                cout << "Anda menggunakan potion.\n" << " Potion anda tersisa : " << pemain.potion << ". HP Anda sekarang: " << pemain.hp << endl;
            } else {
                cout << "Anda tidak memiliki potion!\n";
            }
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    
        // Serangan musuh
        int damageMusuh = musuh.attack - pemain.defense;
            if (damageMusuh <= 0) {
                damageMusuh = 1;
            }
        pemain.hp -= damageMusuh;
        cout << musuh.nama << " menyerang Anda dengan damage: " << damageMusuh << endl;
        if (Aksi == 2) {
            pemain.defense -= 10;
            Aksi = 1;
        }
            
        if (musuh.hp <= 0) {
            musuh.hp = 0;
        }
        if (pemain.hp <= 0) {
            pemain.hp = 0;
        }
        cout << "HP Anda: " << pemain.hp << " | HP " << musuh.nama << ": " << musuh.hp << endl;
        
        if (pemain.hp <= 0) {
            cout << "Anda kalah dalam pertempuran...\n";
            return;
        }
    }
    
    if (musuh.hp <= 0) {
        cout << musuh.nama << " dikalahkan!\n";
        pemain.xp += 500;
        cout << "Anda mendapatkan 500 XP. Total XP: " << pemain.xp << endl;

        // Level up
        if (pemain.xp >= pemain.level * 50) {
            pemain.level+=10;
            pemain.hp += 500;
            pemain.attack += 250;
            pemain.defense += 150;
            cout << "Selamat! Anda naik level ke " << pemain.level << "!\n";
        }
    }
}

void lawanBandit(Pemain &pemain) {
    Musuh musuh = Bandit();
    cout << "Anda bertemu " << musuh.nama << "! HP Musuh: " << musuh.hp << endl;
    while (musuh.hp > 0 && pemain.hp > 0) {
        cout << "\nAksi Anda:\n";
        cout << "1. Serang\n2. Bertahan\n3. Gunakan Potion\n";
        cout << "Pilihan: ";
        int aksi;
        int Aksi;
        cin >> aksi;
        int damage;
        if (aksi == 1) {
            damage = pemain.attack - musuh.defense;
            if (damage <= 0) {
                damage = 1;
            }
            musuh.hp -= damage;
            cout << "Anda menyerang " << musuh.nama << " dengan damage: " << damage << endl;
        } else if (aksi == 2) {
            cout << "Anda bertahan, mengurangi damage musuh.\n";
            pemain.defense += 10;
            Aksi = 2;
        } else if (aksi == 3) {
            if (pemain.potion > 0) {
                pemain.hp += 25;
                pemain.potion--;
                cout << "Anda menggunakan potion.\n" << " Potion anda tersisa : " << pemain.potion << ". HP Anda sekarang: " << pemain.hp << endl;
            } else {
                cout << "Anda tidak memiliki potion!\n";
            }
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    
        // Serangan musuh
        int damageMusuh = musuh.attack - pemain.defense;
            if (damageMusuh <= 0) {
                damageMusuh = 1;
            }
        pemain.hp -= damageMusuh;
        cout << musuh.nama << " menyerang Anda dengan damage: " << damageMusuh << endl;
        if (Aksi == 2) {
            pemain.defense -= 10;
            Aksi = 1;
        }
            
        if (musuh.hp <= 0) {
            musuh.hp = 0;
        }
        if (pemain.hp <= 0) {
            pemain.hp = 0;
        }
        cout << "HP Anda: " << pemain.hp << " | HP " << musuh.nama << ": " << musuh.hp << endl;
        
        if (pemain.hp <= 0) {
            cout << "Anda kalah dalam pertempuran...\n";
            return;
        }
    }
    
    if (musuh.hp <= 0) {
        cout << musuh.nama << " dikalahkan!\n";
        pemain.xp += 250;
        cout << "Anda mendapatkan 250 XP. Total XP: " << pemain.xp << endl;

        // Level up
        if (pemain.xp >= pemain.level * 50) {
            pemain.level+=5;
            pemain.hp += 250;
            pemain.attack += 125;
            pemain.defense += 75;
            cout << "Selamat! Anda naik level ke " << pemain.level << "!\n";
        }
    }
}

int end() {
    return 0;
}

void CeritaUtama1(Pemain &pemain) {
    cout << pemain.nama << " sampai di sebuah tempat yang gelap dan asing, di tempat asing ini terlihat banyak sekali monster. Saat sedang asyik menelusuri hutan, anda bertemu dengan gerombolan goblin lalu terjadilah pertarungan." << endl;
    lawanGoblin(pemain);
    lawanGoblin(pemain);
    lawanGoblin(pemain);
    lawanGoblin(pemain);
    lawanGoblin(pemain);
    cout << "Dengan mudah, anda bisa mengalahkan gerombolan goblin itu. Lalu munculah Goblin King." << endl;
    int pilihan;
    cout << "1. Serang\n2. Lari" << endl;
    cout << "Masukkan Pilihan Anda : ";
    cin >> pilihan;
    if (pilihan == 1) {
        lawanGoblinKing(pemain);
        cout << "Setelah pertarungan itu anda memutuskan untuk kembali menelusuri hutan." << endl;
    } else {
        cout << "Anda melarikan diri dari Goblin King" << endl;
    }
}

void CeritaUtama2(Pemain &pemain) {
    cout << "Hutan ini sangatlah sunyi. Yang terdengar hanya suara-suara asing yang entah darimana asalnya. Cahaya matahari seakan enggan menyinari hutan ini, membuat suasana semakin mencekam." << endl;
    lawanSlime(pemain);
    lawanSerigala(pemain);
    lawanOrc(pemain);
    cout << "Setelah berjalan cukup jauh anda menyadari satu hal. Di sini anda bertemu banyak sekali monster yang beraneka ragam rupa dan bentuknya. Anda melawan monster-monster ini hingga hari semakin gelap." << endl;
    cout << "1. Istirahat\n2. Lanjut Berkelana" << endl;
    int pilihan;
    cout << "Masukkan Pilihan Anda : ";
    cin >> pilihan;
    if (pilihan == 1) {
        pemain.hp += 150;
        cout << "Anda Telah Beristirahat +150 HP" << ", HP anda sekarang : " << pemain.hp << endl;
    } else {
        cout << "Anda Melanjutkan Perjalanan Anda" << endl;
    }
    cout << "Anda melihat ada seseorang yang sedang membutuhkan pertolongan, sepertinya mereka diserang oleh para bandit" << endl;
    int pilihan2;
    cout << "1. Tolong\n2. Tidak Peduli" << endl;
    cout << "Masukkan Pilihan Anda" << endl;
    cin >> pilihan2;
    if (pilihan2 == 1) {
        lawanBandit(pemain);
        lawanBandit(pemain);
        lawanBandit(pemain);
        cout << "Pedagang : Terimakasih sudah menolong kami pahlawan\nKepala Keluarga Viscount : Bandit tadi kuat sekali, sampai-sampai prajuritku tidak bisa melawannya, terimakasih atas kerja kerasmu penyelematku" << endl;
        cout << "Kepala Keluarga Viscount : Beritahu aku siapakah namamu wahai pahlawan" << endl;
        string nama;
        cin >> nama;
        cout << "Kepala Keluarga Viscount : Apakah anda mau ikut kami ke Negeri para ras cahaya, Agrana? kami akan memberikan anda imbalan yang setara" << endl;
        cout << "1. Ikut dengan Kepala Keluarga Viscount\n2. Tidak Ikut" << endl;
        int pilihan3;
        cout << "Masukkan Pilihan Anda : ";
        cin >> pilihan3;
        if (pilihan3 == 1){
            cout << "Kepala Keluarga Viscount : Baiklah, ayo naik " << nama << endl;
            cout << "Anda melanjutkan perjalanan" << endl;
            lawanSerigala(pemain);
            lawanOrc(pemain);
            lawanWyvern(pemain);
        } else {
            cout << "Kepala Keluarga Viscount : Baiklah Kalau begitu, setidaknya tolong terima ini" << endl;
            pemain.potion += 10;
            cout << "Anda Mendapatkan 10 Potion, Potion Anda sekarang : " << pemain.potion << endl;
            cout << "Anda melanjutkan perjalanan" << endl;
            lawanSerigala(pemain);
            lawanOrc(pemain);
            lawanWyvern(pemain);
        }

    } else {
        cout << "Anda meninggalkan orang yang membutuhkan pertolongan tersebut" << endl;
        cout << "Anda melanjutkan perjalanan" << endl;
        lawanSerigala(pemain);
        lawanOrc(pemain);
        lawanWyvern(pemain);
    }
}

void CeritaUtama3(Pemain &pemain) {
    cout << "Apakah anda menyelamatkan seseorang dari bandit dan menerima ajakannya?" << endl;
    cout << "1. Ya\n2. Tidak" << endl;
    cout << "Masukkan Pilihan Anda : ";
    int x;
    cin >> x;
    if (x == 1) {
        cout << "'Setelah menempuh perjalan yang cukup panjang, akhirnya sampai juga di Negeri Agrana' ujar " << pemain.nama << endl;
        cout << "Kepala Keluarga Viscount : Aku berkunjung kesini untuk melihat kerabatku, terimakasih telah melindungi kami, ini adalah imbalanmu" << endl;
        cout << "Anda Mendapatkan sebuah pedang. Dengan melihat secara sekilas saja anda sudah tau kalau pedang ini ditempa oleh Blacksmith seorang ahli pedang yang paling disegani di negeri ini" << endl;
        pemain.attack += 100;
        cout << "Attack anda Bertambah 100, " << "Attack Anda Sekarang : " << pemain.attack << endl;
        cout << "Serpihan cahaya yang selalu bersama dengan anda perlahan mulai berubah bentuk dan bisa berbicara. Menyadari tubuh anda yang melemah, cahaya itu menunjuk sebuah penginapan. Mengisyaratkan agar anda beristirahat sejenak. Saat beristirahat di sebuah penginapan, cahaya itu bercerita sedikit tentang Agrana yang membuat anda menjadi semakin tertarik untuk menjelajahinya." << endl;
        cout << "Keesokan Harinya" << endl;
        cout << "Pagi itu matahari bersinar terang. Ini merupakan awal yang baik untuk memulai petualangan." << endl;
    } else {
        cout << "'Setelah menempuh perjalanan yang cukup panjang, akhirnya sampai juga di negeri Agrana' ujar " << pemain.nama << endl;
        cout << "Serpihan cahaya yang selalu bersama dengan anda perlahan mulai berubah bentuk dan bisa berbicara. Menyadari tubuh anda yang melemah, cahaya itu menunjuk sebuah penginapan. Mengisyaratkan agar anda beristirahat sejenak. Saat sedang beristirahat di sebuah penginapan, cahaya itu bercerita sedikit tentang Agrana yang membuat anda menjadi semakin tertarik untuk menjelajahinya." << endl;
        cout << "Keesokan Harinya" << endl;
        cout << "Pagi itu matahari bersinar terang. Ini merupakan awal yang baik untuk memulai petualangan." << endl;
    }
}

void CeritaUtama4(Pemain &pemain) {
    cout << "Anda mulai menjelajahi Agrana bersama dengan roh cahaya, tanpa sengaja anda melihat sebuah goa. Merasa penasaran, anda melangkahkan kaki masuk ke dalam goa itu. Sebelum memasuki goa ada beberapa wyvern dan naga yang menjaga goa tersebut" << endl;
    lawanWyvern(pemain);
    lawanWyvern(pemain);
    lawanNaga(pemain);
    cout << "Anda memasuki goa\nKetika sampai di ujung goa anda terkejut. Siapa sangka di dalam goa yang gelap itu terdapat sebuah artefak. Artefak itu bukanlah artefak biasa. Artefak ini memancarkan cahaya sihir. Karena merasa tertarik, anda membuka segel yang ada di artefak itu. Setelah segel dibuka, cahaya dari artefak itu menyatu dengan roh cahaya yang selama ini menemani anda dan membentuk sosok elf yang selama ini menghilang (Fyna). Roh dari Fyna menceritakan semua kebenaran dari konflik yang terjadi di masa lalu yang menyebabkan perpecahan antara dua kubu. Fyna pun mengungkap bahwa Rynda adalah dalang di balik perpecahaan. Rynda sangat membenci ras kegelapan karena memiliki sifat yang sedikit arogan dan tidak peduli dengan kebaikan dari ras cahaya. Setelah menceritakan semuanya roh Fyna pun kembali tersegel ke dalam artefak tersebut. Pengakuan ini membuat hati anda menjadi bimbang. Anda dihadapkan pada dua pilihan. 'ini adalah pilihan yang sulit'"<< endl;
    cout << "1. Satukan kedua belah pihak (Anda pergi menghadap Dewi Lyvia dengan membawa artefak dan mengungkapkan kebenaran)\n2. Ras Cahaya sudah melewati batas, AKU HARUS MEMBUNUH MEREKA SEMUA!!!!" << endl;
    int pilihan;
    cout << "Pilihlah dengan bijak : ";
    cin >> pilihan;
    if (pilihan == 1) {
        cout << "Anda menuju ke kediaman para petinggi ras kegelapan untuk memberitahu tentang kejadian ini dan menanyakan mereka untuk segera melakukan : " << endl;
        cout << "1. Diskusi\n2. Perang" << endl;
        int pilihan2;
        cout << "Masukkan Pilihan Anda : ";
        cin >> pilihan2;
        if (pilihan2 == 1) {
            cout << "Para petinggi berdiskusi dan sepakat untuk menuju ke Agrana untuk menemui Dewi Lyvia" << endl;
            cout << "Setelah sampai di sana dan memberitahukan kepada Dewi Lyvia, para petinggi ras cahaya merasa marah karena ras kegelapan masih saja menuduh mereka sebagai pemicu konflik di masa lalu" << endl;
            cout << "Tetapi kehendak dari Dewi berbeda, Dewi Lyvia bisa mengetahui artefak tersebut asli atau palsu" << endl;
            cout << "Dengan perintah dari Dewi Lyvia, para petinggi dan semua penduduk ras cahaya meminta maaf kepada ras kegelapan, dan mereka semua pun hidup damai sampai saat ini" << endl;
        } else {
            cout << "Para petinggi ras kegelapan setuju dengan perang tetapi tidak memperbolehkan adanya penyerangan kepada penduduk tidak bersalah" << endl;
            cout << "Apakah anda Setuju?" << endl;
            int pilihan3;
            cout << "1. Ya\n2. Tidak" << endl;
            cout << "Masukkan Pilihan Anda : ";
            cin >> pilihan3;
            if (pilihan3 == 1) {
                cout << "Anda menyetujui usulan dari para petinggi dan bergegas menuju Agrana" << endl;
                cout << "Setelah sampai di kediaman para petinggi, Dewi Lyvia terkejut dengan kenyataan seperti itu" << endl;
                cout << "Dewi Lyvia tidak bisa ikut campur karena konflik ini terjadi akibat ketidakbecusannya sendiri" << endl;
                lawanPetinggi1(pemain);
                lawanPetinggi2(pemain);
                lawanPetinggi3(pemain);
                cout << "Dengan kalahnya ras cahaya, membuat ras kegelapan menuju ke era kejayaannya. Hal ini membuat anda menjadi penguasa tertinggi setelah Dewi di negeri ini" << endl;
                end();
            } else {
                cout << "Aku tidak mau mendengarkan mu, ras cahaya harus membayar apa yang telah dia perbuat!" << endl;
                lawanPetinggiKegelapan1(pemain);
                lawanPetinggiKegelapan2(pemain);
                lawanPetinggiKegelapan3(pemain);
                cout << "Anda menuju ke Agrana sendirian dan mulai membantai para petinggi serta tidak memedulikan semua penduduk yang anda bunuh" << endl;
                lawanPetinggi1(pemain);
                lawanPetinggi2(pemain);
                lawanPetinggi3(pemain);
                cout << "Dewi Lyvia yang telah mengetahui alasannya tidak bisa melakukan apapun karena hal tersebut adalah hasil dari ketidakbecusannya" << endl;
                cout << "Selain membantai para petinggi, anda juga membunuh para elf dari ras cahaya. Kini yang tersisa hanyalah kehampaan. Anda mulai menyadari kenyataan bahwa balas dendam bukanlah hal yang sebaiknya dilakukan" << endl;
                end();
            }
        }

    } else {
        cout << "Anda memberitahu semua penduduk ras kegelapan tentang artefak tersebut dengan penuh amarah. Tapi para penduduk tidak ingin membalaskan dendam mereka, mereka hanya ingin hidup damai dengan ras cahaya" << endl;
        cout << "Para petinggi dari ras kegelapan pun menghentikan anda untuk menyerang ras cahaya" << endl;
        cout << "1. Mereka semua tak mengerti apapun, HANYA AKULAH YANG MERASAKAN KEBENCIAN, MINGGIR KALIAN SEMUA\n2. Mari dengarkan apa yang mau dibicarakan" << endl;
        int pilihan2;
        cout << "Masukkan Pilihan Anda : ";
        cin >> pilihan2;
        if (pilihan2 == 1) {
            cout << "Anda tidak mau mendengarkan apa pun yang akan disampaikan para petinggi" << endl;
            lawanPetinggiKegelapan1(pemain);
            lawanPetinggiKegelapan2(pemain);
            lawanPetinggiKegelapan3(pemain);
            cout << "Pembantaian dimulai. Anda mulai membunuh para penduduk yang tak bersalah dari ras kegelapan. Dalam panas api yang membara anda menuju pemukiman ras cahaya disertai dengan perasaan penuh dendam, emosi yang meluap-luap, serta rasa ingin membunuh yang kuat" << endl;
            cout << "Sesampainya di pemukiman ras cahaya anda mulai menyebabkan kekacauan bagi seluruh penduduk" << endl;
            cout << "Para petinggi menganggu pesta anda" << endl;
            lawanPetinggi1(pemain);
            lawanPetinggi2(pemain);
            lawanPetinggi3(pemain);
            cout << "Anda tidak merasa puas karena hanya membantai penduduk penduduk biasa" << endl;
            cout << "Anda mulai berpikir siapa sebenarnya pemicu konflik ini. Akhirnya anda mengetahuinya" << endl;
            cout << "Pemicu konflik ini tak lain tak bukan adalah Dewi Lyvia itu sendiri. Karena ketidakbecusannya dalam memimpin para elf. Selain itu ia dengan mudah ditipu oleh para petinggi kubu cahaya, dia tidak cocok menjadi dewi!" << endl;
            cout << "Anda menghampiri Dewi Lyvia dengan badan penuh luka serta bersimbah darah" << endl;
            cout << "Lyvia : Apa pada akhirnya kau akan membunuhku?\nLyvia : Engkau adalah keturunanku, aku harus bertanggung jawab hingga akhir, bukan begitu?" << endl;
            if (pemain.level >= 100) {
                cout << "Anda adalah keturunan yang ditakdirkan\nAnda membangkitkan kekuatan dewi anda sendiri" << endl;
                pemain.hp += 5837439;
                pemain.attack += 1743628;
                pemain.defense += 273938;
                cout << "HP anda bertambah 5837439" << endl;
                cout << "Attack anda bertambah 1743628" << endl;
                cout << "Defense anda bertambah 273938" << endl;
                cout << "Stats anda Sekarang : " << endl;
                cout << "Nama: " << pemain.nama << "\n";
                cout << "HP: " << pemain.hp << "\n";
                cout << "Attack: " << pemain.attack << "\n";
                cout << "Defense: " << pemain.defense << "\n";
                cout << "Level: " << pemain.level << "\n";
                cout << "XP: " << pemain.xp << "\n";
                cout << "Potion: " << pemain.potion << "\n";
                cout << "Lyvia : Jadi kau adalah yang ditakdirkan untuk menggantikanku, sungguh ironi..." << endl; 
                lawanLyvia(pemain);
                cout << "Anda telah mengalahkan seorang Dewi!" << endl;
                cout << "Kekuatan Dewi mulai anda serap" << endl;
                pemain.hp += 9283023;
                pemain.attack += 937922;
                pemain.defense += 394739;
                cout << "HP anda bertambah 9283023" << endl;
                cout << "Attack anda bertambah 937922" << endl;
                cout << "Defense anda bertambah 394739" << endl;
                cout << "Nama: " << pemain.nama << "\n";
                cout << "HP: " << pemain.hp << "\n";
                cout << "Attack: " << pemain.attack << "\n";
                cout << "Defense: " << pemain.defense << "\n";
                cout << "Level: " << pemain.level << "\n";
                cout << "XP: " << pemain.xp << "\n";
                cout << "Potion: " << pemain.potion << "\n";
                cout << "Anda telah berubah menjadi Origin God, mahluk terkuat dari yang paling kuat di dunia ini...\nTetapi apakah itu akan bertahan selamanya?\nAnda sendirian dalam waktu yang lama\npada akhirnya anda melahirkan 2 anak yang menguasai Cahaya dan Kegelapan\nApakah kejadian dulu akan terulang lagi?" << endl;
                cout << "=====The End=====" << endl;
                end();
            } else {
                cout << "Anda tidak mempunyai cukup kekuatan untuk mengalahkan Dewi Lyvia\nLyvia : Aku sangat kecewa padamu, sungguh keturunan yang menjijikkan" << endl;
            }

        
        } else {
            cout << "Para petinggi ras kegelapan setuju dengan perang tetapi tidak memperbolehkan adanya penyerangan kepada penduduk yang tidak bersalah satupun" << endl;
            cout << "Apakah anda Setuju?" << endl;
            int pilihan3;
            cout << "1. Ya\n2. Tidak" << endl;
            cout << "Masukkan Pilihan Anda : ";
            cin >> pilihan3;
            if (pilihan3 == 1) {
                cout << "Anda menyetujui usulan dari para petinggi dan segera bergegas ke Agrana" << endl;
                cout << "Setelah sampai pada kediaman para petinggi, Dewi Lyvia juga terkejut dengan kenyataan seperti itu" << endl;
                cout << "Dewi Lyvia tidak bisa ikut campur dikarenakan itu juga karena ketidakbecusannya sendiri" << endl;
                lawanPetinggi1(pemain);
                lawanPetinggi2(pemain);
                lawanPetinggi3(pemain);
                cout << "Dengan kekalahan dari ras cahaya, sekarang ras kegelapan sudah menuju ke era kejayaannya dan anda telah menjadi penguasa tertinggi setelah Dewi di negeri ini" << endl;
                end();
            } else {
                cout << "Aku tidak mau mendengarkan mu, ras cahaya harus membayar apa yang telah dia perbuat!" << endl;
                lawanPetinggiKegelapan1(pemain);
                lawanPetinggiKegelapan2(pemain);
                lawanPetinggiKegelapan3(pemain);
                cout << "Anda menuju ke Agrana sendirian dan mulai membantai semua petinggi serta tidak memedulikan semua penduduk yang anda bunuh" << endl;
                lawanPetinggi1(pemain);
                lawanPetinggi2(pemain);
                lawanPetinggi3(pemain);
                cout << "Dewi Lyvia yang telah mengetahui alasannya tidak bisa melakukan apapun dikarenakan hal tersebut adalah hasil dari ketidakbecusannya" << endl;
                cout << "Selain membantai semua petinggi, anda juga membunuh elf dari ras cahaya. Kini yang tersisa hanyalah kehampaan. Anda mulai menyadari kenyataan bahwa balas dendam bukanlah hal yang sebaiknya dilakukan" << endl;
                end();
            }
        }
    }
}

// Fungsi menjelajah lokasi
void jelajahLokasi(Pemain &pemain, int X, int Y) {
    cout << "\nAnda menjelajahi lokasi...\n";
    if (X == 4 && Y == 1) {
        cout << "Anda bertemu musuh!\n";
        lawanGoblin(pemain);
    } else if (X == 4 && Y == 4 || X == 3 && Y == 0) {
        cout << "Anda bertemu musuh!\n";
        lawanSerigala(pemain);
    } else if (X == 3 && Y == 3) {
        cout << "Anda bertemu musuh!\n";
        lawanSlime(pemain);
    } else if (X == 2 && Y == 4) {
        cout << "Anda bertemu musuh!\n";
        lawanOrc(pemain);
    } else if (X == 1 && Y == 0 || X == 0 && Y == 4) {
        cout << "Anda bertemu musuh!\n";
        lawanWyvern(pemain);
    } else if (X == 0 && Y == 1 || X == 0 && Y == 3) {
        cout << "Anda bertemu musuh!\n";
        lawanNaga(pemain);
    } else if (X == 3 && Y == 1 || X == 4 && Y == 3 || X == 3 && Y == 4 || X == 2 && Y == 0 || X == 1 && Y == 1 || X == 1 && Y == 3 || X == 1 && Y == 4) {
        cout << "Anda menemukan potion!\n";
        pemain.potion++;
    } else if (X == 3 && Y == 2){
        CeritaUtama1(pemain);
    } else if (X == 2 && Y == 2){
        CeritaUtama2(pemain);
    } else if (X == 1 && Y == 2){
        CeritaUtama3(pemain);
    } else if (X == 0 && Y == 2){
        CeritaUtama4(pemain);
    } else {
        cout << "Anda tidak menemukan apa apa disini." << endl;
    }
}

// Fungsi untuk eksplorasi peta
void eksplorasiPeta(Pemain &pemain, char peta[5][5], int &posX, int &posY) {
    cout << "\n===== Peta Dunia =====\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == posX && j == posY) {
                cout << "P ";  // Posisi pemain
            } else {
                cout << peta[i][j] << " ";
            }
        }
        cout << endl;
    }

    cout << "\nArah gerakan:\n";
    cout << "w: Atas | s: Bawah | a: Kiri | d: Kanan\n";
    cout << "Masukkan pilihan: ";
    char gerakan;
    cin >> gerakan;

    if (gerakan == 'w' && posX > 0) posX--;
    else if (gerakan == 's' && posX < 4) posX++;
    else if (gerakan == 'a' && posY > 0) posY--;
    else if (gerakan == 'd' && posY < 4) posY++;
    else cout << "Gerakan tidak valid!\n";

    jelajahLokasi(pemain, posX, posY);
}

// Fungsi utama permainan
void mainGame(Pemain &pemain) {
    char peta[5][5] = {
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'}
    };

    int posX = 4, posY = 2;  // Posisi awal pemain

    while (pemain.hp > 0) {
        cout << "\n===== Pilihan Anda =====\n";
        cout << "1. Eksplorasi Peta\n2. Status Pemain\n3. Keluar Permainan\n";
        cout << "Pilihan: ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1) {
            eksplorasiPeta(pemain, peta, posX, posY);
        } else if (pilihan == 2) {
            cout << "\n===== Status Pemain =====\n";
            cout << "Nama: " << pemain.nama << "\n";
            cout << "HP: " << pemain.hp << "\n";
            cout << "Attack: " << pemain.attack << "\n";
            cout << "Defense: " << pemain.defense << "\n";
            cout << "Level: " << pemain.level << "\n";
            cout << "XP: " << pemain.xp << "\n";
            cout << "Potion: " << pemain.potion << "\n";
        } else if (pilihan == 3) {
            cout << "Permainan selesai. Terima kasih telah bermain!\n";
            break;
        } else {
            cout << "Pilihan tidak valid!\n";
        }

        if (pemain.hp <= 0) {
            cout << "Anda mati dalam perjalanan. Game Over.\n";
        }
    }
}

int main() {
    Pemain pemain;
    cout << "Selamat datang di Petualangan Teks Interaktif!\n";
    cout << "Masukkan nama karakter Anda: ";
    cin >> pemain.nama;
    cout << R"(Agrana, 6400 SM
Agrana, negeri dari para elf yang dipimpin oleh Dewi Lyvia.
Saat itu, Dewi Lyvia melahirkan dua anak kembar bernama Neubella dan Lyta. Kelahiran mereka membawa keseimbangan unik, Neubella dianugerahi kekuatan cahaya dan Lyta dianugerahi kekuatan kegelapan. Para elf pun bahagia atas kelahiran kedua anak dewi tersebut.

Agrana, 5864 SM
Neubella dan Lyta pun beranjak dewasa dan memiliki banyak keturunan yang menyebabkan terciptanya dua kubu yang berbeda, Cahaya dan Kegelapan. Di bawah kepemimpinan Dewi Lyvia, Neubella memimpin ras cahaya yang bertugas menjaga negeri dari dalam.
Sedangkan Lyta memimpin ras kegelapan yang bertugas melindungi negeri dari ancaman luar dalam bayang-bayang.
Meski berbeda cara, kedua kubu saling melengkapi dan melindungi Agrana.
Namun, seorang elf dari ras cahaya Bernama Rynda memicu konflik besar. 
Karena rasa kebenciannya terhadap ras kegelapan, Rynda menculik dan menyembunyikan Fyna, seorang elf muda dari ras cahaya, dan menuduh ras kegelapan sebagai pelakunya. 
Tuduhan itu membuat Agrana terpecah belah, perang saudara pun terjadi, memaksa Dewi Lyvia mengusir ras kegelapan.
Dengan berat hati, Lyta memimpin pengikutnya dan membuat negeri baru bernama Aranylyta, jauh di sebelah selatan Agrana. Meskipun damai tercipta, luka terus membekas dalam hati Lyta dan pengikutnya.
)" << endl;
    cout << "Aranylyta, 5786 SM" << endl;
    cout << "Seorang anak elf lahir dengan kemampuan istimewa, Ia dianugerahi kemampuan untuk bisa melihat dan berkomunikasi dengan roh dari elf yang sudah meninggal. Anak itu Bernama " << pemain.nama << endl;
    cout << "Aranylyta, 5740 SM" << endl;
    cout << pemain.nama << " menyadari ada sesuatu yang aneh dengan dirinya, ia selalu bermimpi tentang negeri elf yang damai dengan adanya perbedaan lalu diakhiri dengan peperangan di setiap mimpinya, dan ia pun sering melihat sesuatu yang besinar di sekitarnya. Ketika ia menanyakan kepada orang lain, tidak ada yang mengetahui tentang hal itu. Suatu hari, " << pemain.nama << " melihat cahaya itu mengisyaratkan sesuatu (cahaya itu ingin " << pemain.nama << " untuk mengikutinya). " << pemain.nama << " pun mengikutinya, dan mereka pun pergi bersama untuk menjelajahi dunia." << endl;


    // Inisialisasi status pemain
    pemain.hp = 100;
    pemain.attack = 35;
    pemain.defense = 20;
    pemain.level = 1;
    pemain.xp = 0;
    pemain.potion = 2;

    cout << "Petualangan dimulai...\n";
    cout << "Lurus untuk melanjutkan cerita utama." << endl;
    mainGame(pemain);

    return 0;
}
