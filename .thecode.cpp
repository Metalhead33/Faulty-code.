#include <iostream>
#include <string>
#include <map>
using namespace std;

struct attrib
{
    signed int atr_str;
    signed int atr_int;
    signed int atr_wlp;
    signed int atr_agl;
    signed int atr_dxt;
    signed int atr_chr;
};

enum wpn_slot
{
    eq_wpn_dummy = 0,
    eq_wpn1,
    eq_wpn2
};

enum armour_slot
{
    eq_arm_dummy = 0,
    eq_shld,
    eq_hlm,
    eq_clth1,
    eq_clth2,
    eq_ndrwr,
    eq_arm_tors,
    eq_arm_lgs,
    eq_boots,
    eq_ggntlet,
    eq_clk,
    eq_arrow,
    eq_neck
};

enum w_type
{
        blunt = 1,
        ranged,
        piercing,
        slashing
};

enum w_type2
{
        crude = 1,
        bow,
        crossbow,
        short_blade,
        long_blade,
        axe,
        halberd,
        hammer,
        spear,
        special
};

enum a_type
{
    t_none = 1,
    cloth,
    light_armour,
    medium_armour,
    heavy_armour
};

enum element
{
    m_none,
    m_fire,
    m_water,
    m_ice,
    m_air,
    m_thunder,
    m_earth,
    m_light,
    m_dark
};

enum material
{
    a_none,
    a_wood,
    a_iron,
    a_steel,
    a_dwarven,
    a_leather
};

class wpn{
private:
    string w_display_name;
    float w_minatk;
    float w_maxatk;
    float w_cond;
    float w_cost;
    material w_mat;
    element w_elem;
    w_type w_usage;
    w_type2 w_kind;
public:
    wpn(string w_setname, int w_setmin, int w_setmax, int w_setcond, int w_setcost, material w_setmat, element w_setelem, w_type w_settype, w_type2 w_setkind)
        {
        w_display_name = w_setname;
        w_minatk = w_setmin;
        w_maxatk = w_setmax;
        w_cond = w_setcond;
        w_cost = w_setcost;
        w_mat = w_setmat;
        w_elem = w_setelem;
        w_usage = w_settype;
        w_kind = w_setkind;
        };
    wpn()
        {
        string w_setname = "N\\A";
        int w_setmin = 0;
        int w_setmax = 0;
        int w_setcond = 0;
        int w_setcost = 0;
        material w_setmat = a_none;
        element w_setelem = m_none;
        w_type w_settype = blunt;
        w_kind = crude;
        };
    static wpn GetNull()
    {
        wpn *res = new wpn("N\\A",0, 0, 0, 0, a_none, m_none, blunt, crude);
        return *res;
     };
    string GetW_display_name() { return w_display_name; }
    float GetW_minatk() { return w_minatk; }
    float GetW_maxatk() { return w_maxatk; }
    float GetW_cond() { return w_cond; }
    float GetW_cost() { return w_cost; }
    material GetW_mat() { return w_mat; }
    element GetW_elem() { return w_elem; }
    w_type getW_usage() { return w_usage; }
};
wpn w_dummy("N\\A",0, 0, 0, 0, a_none, m_none, blunt, crude);

class armour{
private:
    string a_display_name;
    float a_defense;
    float a_cond;
    float a_cost;
    material a_mat;
    element a_elem;
    a_type a_wearer;
public:
    armour(string a_setname, int a_setvalue, int a_setcond, int a_setcost, material a_setmat, element a_setelem, a_type a_settype)
        {
        a_display_name = a_setname;
        a_defense = a_setvalue;
        a_cond = a_setcond;
        a_cost = a_setcost;
        a_mat = a_setmat;
        a_elem = a_setelem;
        a_wearer = a_settype;
        }
    armour()
        {
        string a_setname = "N\\A";
        int a_setvalue = 0;
        int a_setcond = 0;
        int a_setcost = 0;
        material a_setmat = a_none;
        element a_setelem = m_none;
        a_type a_settype = t_none;
        }
    static armour GetNull()
    {
    armour *res = new armour("N\\A",0,0,0,a_none,m_none,t_none);
    return *res;
    };
    string GetA_display_name() { return a_display_name; }
    float GetA_defense() { return a_defense; }
    float GetA_cond() { return a_cond; }
    float GetA_cost() { return a_cost; }
    material GetA_mat() { return a_mat; }
    element GetA_elem() { return a_elem; }
    a_type getA_wearer() { return a_wearer; }
};
armour a_dummy("N\\A",0,0,0,a_none,m_none,t_none);

enum sex
{
        male,
        female
};

class race1
{
private:
    string r1_display_name;
    attrib r_max;
    attrib r_min;
public:
    race1(string setname, int min_atr_str, int max_atr_str, int min_atr_int, int max_atr_int, int min_atr_wlp, int max_atr_wlp, int min_atr_agl, int max_atr_agl, int min_atr_dxt, int max_atr_dxt, int min_atr_chr, int max_atr_chr)
    {
        r1_display_name = setname;
        r_min.atr_str = min_atr_str;
        r_max.atr_str = max_atr_str;
        r_min.atr_int = min_atr_int;
        r_max.atr_int = max_atr_int;
        r_min.atr_wlp = min_atr_wlp;
        r_max.atr_wlp = max_atr_wlp;
        r_min.atr_agl = min_atr_agl;
        r_max.atr_agl = max_atr_agl;
        r_min.atr_dxt = min_atr_dxt;
        r_max.atr_dxt = max_atr_dxt;
        r_min.atr_chr = min_atr_chr;
        r_max.atr_chr = max_atr_chr;
    };
    race1()
    {
        string setname = "None";
        int min_atr_str = 0;
        int max_atr_str = 0;
        int min_atr_int = 0;
        int max_atr_int = 0;
        int min_atr_wlp = 0;
        int max_atr_wlp = 0;
        int min_atr_agl = 0;
        int max_atr_agl = 0;
        int min_atr_dxt = 0;
        int max_atr_dxt = 0;
        int min_atr_chr = 0;
        int max_atr_chr = 0;
    };
    static race1 GetNull()
    {
    race1 *res = new race1("None",0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    return *res;
    };
    string get_display_name() {return r1_display_name; }
    int get_min_str() {return r_min.atr_str; }
	void set_min_str(int set_min_atset_str) { r_min.atr_str = set_min_atset_str; }
	int get_max_str() {return r_max.atr_str; }
	void set_max_str(int set_max_atset_str) { r_max.atr_str = set_max_atset_str; }
	int get_min_int() {return r_min.atr_int; }
	void set_min_int(int set_min_atset_int) { r_min.atr_int = set_min_atset_int; }
	int get_max_int() {return r_max.atr_int; }
	void set_max_int(int set_max_atset_int) { r_max.atr_int = set_max_atset_int; }
	int get_min_wlp() {return r_min.atr_wlp; }
	void set_min_wlp(int set_min_atset_wlp) { r_min.atr_wlp = set_min_atset_wlp; }
	int get_max_wlp() {return r_max.atr_wlp; }
	void set_max_wlp(int set_max_atset_wlp) { r_max.atr_wlp = set_max_atset_wlp; }
	int get_min_agl() {return r_min.atr_agl; }
	void set_min_agl(int set_min_atset_agl) { r_min.atr_agl = set_min_atset_agl; }
	int get_max_agl() {return r_max.atr_agl; }
	void set_max_agl(int set_max_atset_agl) { r_max.atr_agl = set_max_atset_agl; }
	int get_min_dxt() {return r_min.atr_dxt; }
	void set_min_dxt(int set_min_atset_dxt) { r_min.atr_dxt = set_min_atset_dxt; }
	int get_max_dxt() {return r_max.atr_dxt; }
	void set_max_dxt(int set_max_atset_dxt) { r_max.atr_dxt = set_max_atset_dxt; }
	int get_min_chr() {return r_min.atr_chr; }
	void set_min_chr(int set_min_atset_chr) { r_min.atr_chr = set_min_atset_chr; }
	int get_max_chr() {return r_max.atr_chr; }
	void set_max_chr(int set_max_atset_chr) { r_max.atr_chr = set_max_atset_chr; }
};

race1 r_dummy("None",0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
race1 r_human("Human", 8, 18, 8, 18, 8, 18, 8, 18, 8, 18, 8, 18);
race1 r_wood_elf("Wood Elf", 7, 17, 9, 19, 9, 19, 9, 19, 8, 18, 7, 17);
race1 r_high_elf("High Elf", 7, 17, 8, 18, 9, 19, 9, 19, 8, 18, 7, 17);
race1 r_dark_elf("Dark Elf", 7, 17, 8, 18, 8, 18, 9, 19, 9, 19, 7, 17);
race1 r_orc("Orc", 10, 20, 8, 18, 7, 17, 9, 19, 7, 17, 7, 17);
race1 r_dwarf("Dwarf", 10, 20, 8, 18, 8, 18, 6, 16, 8, 18, 8, 18);
race1 r_gnome("Gnome", 7, 17, 9, 19, 9, 19, 6, 16, 9, 19, 8, 18);
race1 r_halfling("Halfling", 7, 17, 8, 18, 8, 18, 9, 19, 7, 17, 9, 19);
race1 r_lizardman("Lizardman", 9, 19, 9, 19, 8, 18, 9, 19, 7, 17, 6, 16);
race1 r_ogre("Ogre", 12, 22, 7, 17, 7, 17, 9, 19, 7, 17, 6, 16);
race1 r_goblin("Goblin", 9, 19, 8, 18, 7, 17, 9, 19, 9, 19, 7, 17);

enum race1_setup
{
    sr_dummy = 0,
    sr_human,
    sr_wood_elf,
    sr_high_elf,
    sr_dark_elf,
    sr_orc,
    sr_dwarf,
    sr_gnome,
    sr_halfling,
    sr_lizardman,
    sr_ogre,
    sr_goblin
    };

class race2
{
private:
    string r2_display_name;
    attrib r2_bonus;
public:
    race2(string r2_setname, signed int set_bon_atset_str, signed int set_bon_atset_int, signed int set_bon_atset_wlp, signed int set_bon_agl, signed int set_bon_atset_dxt, signed int set_bon_atset_chr)
    {
    r2_display_name = r2_setname;
    r2_bonus.atr_str = set_bon_atset_str;
    r2_bonus.atr_int = set_bon_atset_int;
    r2_bonus.atr_wlp = set_bon_atset_wlp;
    r2_bonus.atr_agl = set_bon_agl;
    r2_bonus.atr_dxt = set_bon_atset_dxt;
    r2_bonus.atr_chr = set_bon_atset_chr;
    };
    race2()
    {
    string r2_setname = "None";
    int set_bon_atset_str = 0;
    int set_bon_atset_int = 0;
    int set_bon_atset_wlp = 0;
    int set_bon_atset_agl = 0;
    int set_bon_atset_dxt = 0;
    int set_bon_atset_chr = 0;
    };
    static race2 GetNull()
    {
    race2 *res = new race2("None",0, 0, 0, 0, 0, 0);
    return *res;
    };
	int get_bon_str() {return r2_bonus.atr_str; }
	void set_bon_str(int set_bon_atset_str) { r2_bonus.atr_str = set_bon_atset_str; }
	int get_bon_int() {return r2_bonus.atr_int; }
	void set_bon_int(int set_bon_atset_int) { r2_bonus.atr_int = set_bon_atset_int; }
	int get_bon_wlp() {return r2_bonus.atr_wlp; }
	void set_bon_wlp(int set_bon_atset_wlp) { r2_bonus.atr_wlp = set_bon_atset_wlp; }
	int get_bon_agl() {return r2_bonus.atr_agl; }
	void set_bon_agl(int set_bon_atset_agl) { r2_bonus.atr_agl = set_bon_atset_agl; }
	int get_bon_dxt() {return r2_bonus.atr_dxt; }
	void set_bon_dxt(int set_bon_atset_dxt) { r2_bonus.atr_dxt = set_bon_atset_dxt; }
	int get_bon_chr() {return r2_bonus.atr_chr; }
	void set_bon_chr(int set_bon_atset_chr) { r2_bonus.atr_chr = set_bon_atset_chr; }
};
race2 r_none("None", 0, 0, 0, 0, 0, 0);
race2 r_vampire("Vampire", 7, 0, 0, 1, 1, 2);
race2 r_lich("Lich", 0, 6, 6, 0, 0, -1);
race2 r_werewolf("Werewolf", 6, 0, 2, 0, 0, 0);
race2 r_werebear("Werebear", 10, 0, 0, 0, -2, -2);
race2 r_werelion("Werelion", 5, 0, 0, 0, 3, 0);
race2 r_wereboar("Wereboar", 8, 0, 0, 0, -1, 0);
race2 r_weretiger("Weretiger", 5, 0, 0, 1, 2, 0);
race2 r_wererat("Wererat", 1, 3, 1, 0, 3, -1);

enum race2_setup
{
        sr_none,
        sr_vampire,
        sr_lich,
        sr_werewolf,
        sr_werelion,
        sr_werebear,
        sr_wereboar,
        sr_weretiger,
        sr_wererat
};

class char_class
{
private:
    string c_display_name;
    bool arcane_magic;
    bool cleric_magic;
    bool druid_magic;
    bool can_use[special];
    bool can_wear[heavy_armour];
    attrib requirement;
public:
    char_class(string set_name, bool setmagic1, bool setmagic2, bool setmagic3, int setr_atr_str, int setr_atr_int, int setr_atr_wlp, int setr_atr_agl, int setr_atr_dxt, int setr_atr_chr, bool can_use_crude, bool can_use_bow, bool can_use_crossbow, bool can_use_short_blade, bool can_use_long_blade, bool can_use_axe, bool can_use_halberd, bool can_use_hammer, bool can_use_spear, bool can_use_special , bool can_wear_t_none, bool can_wear_cloth, bool can_wear_light_armour, bool can_wear_medium_armour, bool can_wear_heavy_armour)
    {
        c_display_name = set_name;
        arcane_magic = setmagic1;
        cleric_magic = setmagic2;
        druid_magic = setmagic3;
        requirement.atr_str = setr_atr_str;
        requirement.atr_int = setr_atr_int;
        requirement.atr_wlp = setr_atr_wlp;
        requirement.atr_agl = setr_atr_agl;
        requirement.atr_dxt = setr_atr_dxt;
        requirement.atr_chr = setr_atr_chr;
        can_use[crude] = can_use_crude;
        can_use[bow] = can_use_bow;
        can_use[crossbow] = can_use_crossbow;
        can_use[short_blade] = can_use_short_blade;
        can_use[long_blade] = can_use_long_blade;
        can_use[axe] = can_use_axe;
        can_use[halberd] = can_use_halberd;
        can_use[hammer] = can_use_hammer;
        can_use[spear] = can_use_spear;
        can_use[special] = can_use_special;
        can_wear[t_none] = can_wear_t_none;
        can_wear[cloth] = can_wear_cloth;
        can_wear[light_armour] = can_wear_light_armour;
        can_wear[medium_armour] = can_wear_medium_armour;
        can_wear[heavy_armour] = can_wear_heavy_armour;
    };
    char_class()
    {
        string set_name = "None";
        bool setmagic1 = false;
        bool setmagic2 = false;
        bool setmagic3 = false;
        int setr_atr_str = 0;
        int setr_atr_int = 0;
        int setr_atr_wlp = 0;
        int setr_atr_agl = 0;
        int setr_atr_dxt = 0;
        int setr_atr_chr = 0;
        bool can_use_crude = true;
        bool can_use_bow = true;
        bool can_use_crossbow = true;
        bool can_use_short_blade = true;
        bool can_use_long_blade = false;
        bool can_use_axe = true;
        bool can_use_halberd = false;
        bool can_use_hammer = false;
        bool can_use_spear = true;
        bool can_use_special = false;
        bool can_wear_t_none = true;
        bool can_wear_cloth = true;
        bool can_wear_light_armour = true;
        bool can_wear_medium_armour = false;
        bool can_wear_heavy_armour = false;
    };
    static char_class GetNull()
    {
    char_class *res = new char_class("None",false, false, false, 0, 0, 0, 0, 0, 0, true, true, true, true, false, true, false, false, true, false, true, true, true, false, false);
    return *res;
    };
};
char_class c_dummy("None", false,  false,  false, 0, 0, 0, 0, 0, 0,  true,  true,  true,  true,  false,  true,  false,  false,  true,  false,  true,  true,  true,  false,  false);
char_class c_warrior("Warrior", false,  false,  false, 11, 0, 0, 9, 0, 0,  true,  true,  true,  true, true,  true, true, true,  true, true,  true,  true,  true, true, true);
char_class c_thief("Thief", false,  false,  false, 0, 0, 0, 12, 12, 0,  true,  true,  true,  true, true,  true, true, true,  true, true,  true,  true,  true, false, false);
char_class c_cleric("Cleric", false, true,  false, 10, 10, 13, 0, 0, 10,  true, false, false, false, false, false, false, true, false, true,  true,  true,  true, true, false);
char_class c_mage("Magician", true, false,  false, 0, 12, 12, 0, 0, 10,  true, false, true, true, false, true, false, true, false, true,  true,  true,  true, false, false);
char_class c_druid("Druid", false, false, true, 0, 14, 12, 0, 0, 0,  true, true, false, false, false, false, false, false, false, true,  true,  true, false, false, false);


enum char_class_setup
{
        sc_none,
        sc_druid,
        sc_priest,
        sc_magician,
        sc_thief,
        sc_warrior
};


enum pclass
{
        pc_none,
        pc_knight,
        pc_dknight,
        pc_ranger,
        pc_assassin,
        pc_inquisitor,
        pc_necromancer,
        pc_headhunter
};


class inventory{
public:
    wpn *char_wpn[eq_wpn2];
    armour *char_armour[eq_neck];
    inventory(){
        char_wpn[eq_wpn1] = &w_dummy;
        char_wpn[eq_wpn2] = &w_dummy;
        char_armour[eq_shld] = &a_dummy;
        char_armour[eq_hlm] = &a_dummy;
        char_armour[eq_clth1] = &a_dummy;
        char_armour[eq_clth2] = &a_dummy;
        char_armour[eq_ndrwr] = &a_dummy;
        char_armour[eq_arm_tors] = &a_dummy;
        char_armour[eq_arm_lgs] = &a_dummy;
        char_armour[eq_boots] = &a_dummy;
        char_armour[eq_ggntlet] = &a_dummy;
        char_armour[eq_clk] = &a_dummy;
        char_armour[eq_arrow] = &a_dummy;
        char_armour[eq_neck] = &a_dummy;
        };
};


class chr{
private:
    string display_name;
    pclass prestige_class;
    int lvl;
    attrib base_attrib;
    attrib mod_attrib;
    bool alive;
    string state[30];
    float mhp;
    float chp;
    float mmp;
    float cmp;
    float hp_lvl;
    float mp_lvl;
    float msta;
    float csta;
    float sta_lvl;
public:
    race1* race;
    race2* sec_race;
    char_class *class1;
    char_class *class2;
    inventory inv;
    chr(string setname, race1_setup setrace, race2_setup setrace2, char_class_setup setclass1, char_class_setup setclass2, pclass setpclass, int setlvl)
    {
    display_name = setname;
    switch (setrace)
    {
        case sr_dummy:
            race = &r_dummy;
            break;
        case sr_human:
            race = &r_human;
            break;
        case sr_wood_elf:
            race = &r_wood_elf;
            break;
        case sr_high_elf:
            race = &r_high_elf;
            break;
        case sr_dark_elf:
            race = &r_dark_elf;
            break;
        case sr_orc:
            race = &r_orc;
            break;
        case sr_dwarf:
            race = &r_dwarf;
            break;
        case sr_gnome:
            race = &r_gnome;
            break;
        case sr_halfling:
            race = &r_halfling;
            break;
        case sr_lizardman:
            race = &r_lizardman;
            break;
        case sr_ogre:
            race = &r_ogre;
            break;
        case sr_goblin:
            race = &r_goblin;
            break;
    };
    switch (setrace2)
    {
        case sr_none:
            sec_race = &r_none;
            break;
        case sr_vampire:
            sec_race = &r_vampire;
            break;
        case sr_lich:
            sec_race = &r_lich;
            break;
        case sr_werewolf:
            sec_race = &r_werewolf;
            break;
        case sr_werebear:
            sec_race = &r_werebear;
            break;
        case sr_wereboar:
            sec_race = &r_wereboar;
            break;
        case sr_werelion:
            sec_race = &r_werelion;
            break;
        case sr_wererat:
            sec_race = &r_wererat;
            break;
        case sr_weretiger:
            sec_race = &r_weretiger;
            break;
    };
    switch (setclass1)
    {
        case sc_none:
            class1 = &c_dummy;
            break;
        case sc_warrior:
            class1 = &c_warrior;
            break;
        case sc_magician:
            class1 = &c_mage;
            break;
        case sc_priest:
            class1 = &c_cleric;
            break;
        case sc_thief:
            class1 = &c_thief;
            break;
        case sc_druid:
            class1 = &c_druid;
            break;
        }
    switch (setclass2)
    {
        case sc_none:
            class2 = &c_dummy;
            break;
        case sc_warrior:
            class2 = &c_warrior;
            break;
        case sc_magician:
            class2 = &c_mage;
            break;
        case sc_priest:
            class2 = &c_cleric;
            break;
        case sc_thief:
            class2 = &c_thief;
            break;
        case sc_druid:
            class2 = &c_druid;
            break;
        }
    prestige_class = setpclass;
    lvl = setlvl;
    alive = true;
    mhp = 0.00;
    chp = 0.00;
    mmp = 0.00;
    cmp = 0.00;
    hp_lvl = 0.00;
    mp_lvl = 0.00;
    msta = 0.00;
    csta = 0.00;
    sta_lvl = 0.00;
    mod_attrib.atr_str = 0;
    mod_attrib.atr_int = 0;
    mod_attrib.atr_wlp = 0;
    mod_attrib.atr_agl = 0;
    mod_attrib.atr_dxt = 0;
    mod_attrib.atr_chr = 0;
    };
    string GetName() { return display_name; }
    void set_name(string set_name) { display_name = set_name; }
    void set_race2(race1_setup setrace)
    { switch (setrace)
    {
        case sr_dummy:
            race = &r_dummy;
            break;
        case sr_human:
            race = &r_human;
            break;
        case sr_wood_elf:
            race = &r_wood_elf;
            break;
        case sr_high_elf:
            race = &r_high_elf;
            break;
        case sr_dark_elf:
            race = &r_dark_elf;
            break;
        case sr_orc:
            race = &r_orc;
            break;
        case sr_dwarf:
            race = &r_dwarf;
            break;
        case sr_gnome:
            race = &r_gnome;
            break;
        case sr_halfling:
            race = &r_halfling;
            break;
        case sr_lizardman:
            race = &r_lizardman;
            break;
        case sr_ogre:
            race = &r_ogre;
            break;
        case sr_goblin:
            race = &r_goblin;
            break;
    }; }
    void set_race2(race2_setup setrace2) { switch (setrace2)
    {
        case sr_none:
            sec_race = &r_none;
            break;
        case sr_vampire:
            sec_race = &r_vampire;
            break;
        case sr_lich:
            sec_race = &r_lich;
            break;
        case sr_werewolf:
            sec_race = &r_werewolf;
            break;
        case sr_werebear:
            sec_race = &r_werebear;
            break;
        case sr_wereboar:
            sec_race = &r_wereboar;
            break;
        case sr_werelion:
            sec_race = &r_werelion;
            break;
        case sr_wererat:
            sec_race = &r_wererat;
            break;
        case sr_weretiger:
            sec_race = &r_weretiger;
            break;
    }; }
    void set_class1(char_class_setup setclass1) { switch (setclass1)
    {
        case sc_none:
            class1 = &c_dummy;
            break;
        case sc_warrior:
            class1 = &c_warrior;
            break;
        case sc_magician:
            class1 = &c_mage;
            break;
        case sc_priest:
            class1 = &c_cleric;
            break;
        case sc_thief:
            class1 = &c_thief;
            break;
        case sc_druid:
            class1 = &c_druid;
            break;
        }; }
    void set_class2(char_class_setup setclass2) { switch (setclass2)
    {
        case sc_none:
            class2 = &c_dummy;
            break;
        case sc_warrior:
            class2 = &c_warrior;
            break;
        case sc_magician:
            class2 = &c_mage;
            break;
        case sc_priest:
            class2 = &c_cleric;
            break;
        case sc_thief:
            class2 = &c_thief;
            break;
        case sc_druid:
            class2 = &c_druid;
            break;
        }; }
    pclass getpclass() { return prestige_class; }
    void set_pclass(pclass setpclass) { prestige_class = setpclass; }
    int getlvl() { return lvl; }
    void set_lvl(int setlvl) { lvl = setlvl; }
    bool get_alive() { return alive; }
    void rfr_alive()
    {
    if (chp <= 0.00)
        alive = false;
    else
        alive = true; }
    float get_mhp() { return mhp; }
    void set_mhp(float setmhp) { mhp = setmhp; }
    float get_chp() { return chp; }
    void set_chp(float setchp) { chp = setchp; }
    float get_mmp() { return mmp; }
    void set_mmp(float setmmp) { mmp = setmmp; }
    float get_cmp() { return cmp; }
    void set_cmp(float setcmp) { cmp = setcmp; }
    float get_hp_lvl() { return hp_lvl; }
    void set_hp_lvl(float sethp_lvl) { hp_lvl = sethp_lvl; }
    float get_mp_lvl() { return mp_lvl; }
    void set_mp_lvl(float setmp_lvl) { mp_lvl = setmp_lvl; }
    float get_msta() { return msta; }
    void set_msta(float setmsta) { msta = setmsta; }
    float get_csta() { return csta; }
    void set_csta(float setcsta) { msta = setcsta; }
    float get_sta_lvl() { return sta_lvl; }
    void set_sta_lvl(float setsta_lvl) { sta_lvl = setsta_lvl; }
    void default_attributes()
    {
    base_attrib.atr_str = race->get_min_str();
    base_attrib.atr_int = race->get_min_int();
    base_attrib.atr_wlp = race->get_min_wlp();
    base_attrib.atr_agl = race->get_min_agl();
    base_attrib.atr_dxt = race->get_min_dxt();
    base_attrib.atr_chr = race->get_min_chr();
        };
    int get_bstr() { return base_attrib.atr_str; }
    int get_bint() { return base_attrib.atr_int; }
    int get_bwlp() { return base_attrib.atr_wlp; }
    int get_bagl() { return base_attrib.atr_agl; }
    int get_bdxt() { return base_attrib.atr_dxt; }
    int get_bchr() { return base_attrib.atr_chr; }
    void set_bstr(int setstr) { base_attrib.atr_str = setstr; }
    void set_bint(int setint) { base_attrib.atr_int = setint; }
    void set_bwlp(int setwlp) { base_attrib.atr_wlp = setwlp; }
    void set_bagl(int setagl) { base_attrib.atr_agl = setagl; }
    void set_bdxt(int setdxt) { base_attrib.atr_dxt = setdxt; }
    void set_bchr(int setchr) { base_attrib.atr_chr = setchr; }
    void refresh_mstr() { mod_attrib.atr_str = (sec_race->get_bon_str()); }
    void refresh_mint() { mod_attrib.atr_int = (sec_race->get_bon_int()); }
    void refresh_mwlp() { mod_attrib.atr_wlp = (sec_race->get_bon_wlp()); }
    void refresh_magl() { mod_attrib.atr_agl = (sec_race->get_bon_agl()); }
    void refresh_mdxt() { mod_attrib.atr_dxt = (sec_race->get_bon_dxt()); }
    void refresh_mchr() { mod_attrib.atr_chr = (sec_race->get_bon_chr()); }
    int get_mstr() { refresh_mstr(); return mod_attrib.atr_str; }
    int get_mint() { refresh_mint(); return mod_attrib.atr_int; }
    int get_mwlp() { refresh_mwlp(); return mod_attrib.atr_wlp; }
    int get_magl() { refresh_magl(); return mod_attrib.atr_agl; }
    int get_mdxt() { refresh_mdxt(); return mod_attrib.atr_dxt; }
    int get_mchr() { refresh_mchr(); return mod_attrib.atr_chr; }
    void set_mstr(int setstr) { mod_attrib.atr_str = setstr; }
    void set_mint(int setint) { mod_attrib.atr_int = setint; }
    void set_mwlp(int setwlp) { mod_attrib.atr_wlp = setwlp; }
    void set_magl(int setagl) { mod_attrib.atr_agl = setagl; }
    void set_mdxt(int setdxt) { mod_attrib.atr_dxt = setdxt; }
    void set_mchr(int setchr) { mod_attrib.atr_chr = setchr; }
    void plus_mstr(int plusstr) { mod_attrib.atr_str = mod_attrib.atr_str + plusstr; }
    void plus_mint(int plusint) { mod_attrib.atr_int = mod_attrib.atr_int + plusint; }
    void plus_mwlp(int pluswlp) { mod_attrib.atr_wlp = mod_attrib.atr_wlp + pluswlp; }
    void plus_magl(int plusagl) { mod_attrib.atr_agl = mod_attrib.atr_agl + plusagl; }
    void plus_mdxt(int plusdxt) { mod_attrib.atr_dxt = mod_attrib.atr_dxt + plusdxt; }
    void plus_mchr(int pluschr) { mod_attrib.atr_chr = mod_attrib.atr_chr + pluschr; }
    void min_mstr(int minustr) { mod_attrib.atr_str = mod_attrib.atr_str + minustr; }
    void min_mint(int minuint) { mod_attrib.atr_int = mod_attrib.atr_int + minuint; }
    void min_mwlp(int minuwlp) { mod_attrib.atr_wlp = mod_attrib.atr_wlp + minuwlp; }
    void min_magl(int minuagl) { mod_attrib.atr_agl = mod_attrib.atr_agl + minuagl; }
    void min_mdxt(int minudxt) { mod_attrib.atr_dxt = mod_attrib.atr_dxt + minudxt; }
    void min_mchr(int minuchr) { mod_attrib.atr_chr = mod_attrib.atr_chr + minuchr; }
    int getSrength() { return (get_bstr() + get_mstr());}
    int getIntelligence() { return (get_bint() + get_mint());}
    int getWillpower() { return (get_bwlp() + get_mwlp()); }
    int getAgility() { return (get_bagl() + get_magl());}
    int getDexterity() { return (get_bdxt() + get_mdxt());}
    int getCharisma() { return (get_bchr() + get_mchr());}
};

int main()
{
    wpn iron_sword("Iron Sword", 1, 8, 100, 75, a_iron, m_none, slashing, long_blade);
    chr stefanus_tavilrond("Stephanus Tavilrond", sr_human, sr_lich, sc_warrior, sc_priest, pc_knight, 1);
    stefanus_tavilrond.race = &r_human;
    stefanus_tavilrond.inv.char_wpn[eq_wpn1] = &iron_sword;
    cout << stefanus_tavilrond.inv.char_wpn[eq_wpn1]->GetW_display_name() << endl;
    stefanus_tavilrond.default_attributes();
    cout << stefanus_tavilrond.getCharisma() << endl;
    cout << "damnit" << endl;
    return 0;
};
