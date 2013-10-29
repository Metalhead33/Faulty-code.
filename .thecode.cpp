#include <iostream>
#include <fstream>
#include <cstdlib>
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

class w_type
{private:
    string display_name;
public:
    w_type(string setname)
    {
        display_name = setname;
    }
    w_type()
    {
        string setname = "None";
    }
    static w_type GetNull()
    {
        w_type *res = new w_type("None");
        return *res;
     };
};
w_type blunt("Blunt");
w_type ranged("Ranged");
w_type piercing("Piercing");
w_type slashing("Slashing");

enum w_type2_setup
{
    s_crude = 1,
    s_bow,
    s_crossbow,
    s_short_blade,
    s_long_blade,
    s_axe,
    s_halberd,
    s_hammer,
    s_spear,
    s_special
};

class w_type2
{
private:
    string display_name;
    w_type2_setup alias;
public:
    w_type2(string setname, w_type2_setup setalias)
    {
        display_name = setname;
        alias = setalias;
    };
    w_type2()
    {
        string setname = "None";
        w_type2_setup setalias = s_crude;
    };
    static w_type2 GetNull()
    {
        w_type2 *res = new w_type2("None", s_crude);
        return *res;
     };
};

w_type2 crude("Crude", s_crude);
w_type2 bow("Bow", s_bow);
w_type2 crossbow("Crossbow", s_crossbow);
w_type2 short_blade("Short Blade", s_short_blade);
w_type2 long_blade("Long Blade", s_long_blade);
w_type2 axe("Axe", s_axe);
w_type2 halberd("Battle Axe", s_halberd);
w_type2 hammer("Hammer", s_hammer);
w_type2 spear("Polearm", s_spear);
w_type2 special("Special", s_special);

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
public:
    w_type *w_usage;
    w_type2 *w_kind;
    wpn(string w_setname, int w_setmin, int w_setmax, int w_setcond, int w_setcost, material w_setmat, element w_setelem, w_type *w_settype, w_type2 *w_setkind)
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
        w_type *w_settype = &blunt;
        w_type2 *w_kind = &crude;
        };
    static wpn GetNull()
    {
        wpn *res = new wpn("N\\A",0, 0, 0, 0, a_none, m_none, &blunt, &crude);
        return *res;
     };
    void w_set_name(string w_setname) {w_display_name = w_setname; }
    void w_set_min(int w_setmin) {w_minatk = w_setmin; }
    void w_set_max(int w_setmax) {w_maxatk = w_setmax; }
    void w_set_cond(int w_setcond) {w_cond = w_setcond; }
    void w_set_cost(int w_setcost) {w_cost = w_setcost; }
    void w_set_mat(material w_setmat) {w_mat = w_setmat; }
    void w_set_elem(element w_setelem) {w_elem = w_setelem; }
    void w_set_type(w_type *w_settype) {w_usage = w_settype; }
    void w_set_kind(w_type2 *w_setkind) {w_kind = w_setkind; }
    string GetW_display_name() { return w_display_name; }
    float GetW_minatk() { return w_minatk; }
    float GetW_maxatk() { return w_maxatk; }
    float GetW_cond() { return w_cond; }
    float GetW_cost() { return w_cost; }
    material GetW_mat() { return w_mat; }
    element GetW_elem() { return w_elem; }
};
wpn w_dummy("N\\A",0, 0, 0, 0, a_none, m_none, &blunt, &crude);

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
    void SetA_display_name(string a_setname) { a_display_name = a_setname; }
    void SetA_defense(int a_setvalue) { a_defense = a_setvalue; }
    void SetA_cond(int a_setcond) { a_cond = a_setcond; }
    void SetA_cost(int a_setcost) { a_cost = a_setcost; }
    void SetA_mat(material a_setmat) { a_mat = a_setmat; }
    void SetA_elem(element a_setelem) { a_elem = a_setelem; }
    void SetA_wearer(a_type a_settype) { a_wearer = a_settype; }
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

class char_class
{
private:
    string c_display_name;
    bool arcane_magic;
    bool cleric_magic;
    bool druid_magic;
    bool can_use[s_special];
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
        can_use[s_crude] = can_use_crude;
        can_use[s_bow] = can_use_bow;
        can_use[s_crossbow] = can_use_crossbow;
        can_use[s_short_blade] = can_use_short_blade;
        can_use[s_long_blade] = can_use_long_blade;
        can_use[s_axe] = can_use_axe;
        can_use[s_halberd] = can_use_halberd;
        can_use[s_hammer] = can_use_hammer;
        can_use[s_spear] = can_use_spear;
        can_use[s_special] = can_use_special;
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
	void set_c_display_name(string set_name) { c_display_name = set_name; }
	void set_arcane_magic(bool setmagic1) { arcane_magic = setmagic1; }
	void set_cleric_magic(bool setmagic2) { cleric_magic = setmagic2; }
	void set_druid_magic(bool setmagic3) { druid_magic = setmagic3; }
	void set_req_str(int setr_atr_str) { requirement.atr_str = setr_atr_str; }
	void set_req_int(int setr_atr_int) { requirement.atr_int = setr_atr_int; }
	void set_req_wlp(int setr_atr_wlp) { requirement.atr_wlp = setr_atr_wlp; }
	void set_req_agl(int setr_atr_agl) { requirement.atr_agl = setr_atr_agl; }
	void set_req_dxt(int setr_atr_dxt) { requirement.atr_dxt = setr_atr_dxt; }
	void set_req_chr(int setr_atr_chr) { requirement.atr_chr = setr_atr_chr; }
	void set_can_crude(bool can_use_crude) { can_use[s_crude] = can_use_crude; }
	void set_can_bow(bool can_use_bow) { can_use[s_bow] = can_use_bow; }
	void set_can_crossbow(bool can_use_crossbow) { can_use[s_crossbow] = can_use_crossbow; }
	void set_can_short_blade(bool can_use_short_blade) { can_use[s_short_blade] = can_use_short_blade; }
	void set_can_long_blade(bool can_use_long_blade) { can_use[s_long_blade] = can_use_long_blade; }
	void set_can_axe(bool can_use_axe) { can_use[s_axe] = can_use_axe; }
	void set_can_halberd(bool can_use_halberd) { can_use[s_halberd] = can_use_halberd; }
	void set_can_hammer(bool can_use_hammer) { can_use[s_hammer] = can_use_hammer; }
	void set_can_spear(bool can_use_spear) { can_use[s_spear] = can_use_spear; }
	void set_can_special(bool can_use_special) { can_use[s_special] = can_use_special; }
	void set_can_t_none(bool can_wear_t_none) { can_wear[t_none] = can_wear_t_none; }
	void set_can_cloth(bool can_wear_cloth) { can_wear[cloth] = can_wear_cloth; }
	void set_can_light_armour(bool can_wear_light_armour) { can_wear[light_armour] = can_wear_light_armour; }
	void set_can_medium_armour(bool can_wear_medium_armour) { can_wear[medium_armour] = can_wear_medium_armour; }
	void set_can_heavy_armour(bool can_wear_heavy_armour) { can_wear[heavy_armour] = can_wear_heavy_armour; }
    string get_c_display_name() { return c_display_name; }
    bool get_arcane_magic() { return arcane_magic; }
    bool get_cleric_magic() { return cleric_magic; }
    bool get_druid_magic() { return druid_magic; }
    int get_req_str() { return requirement.atr_str; }
    int get_req_int() { return requirement.atr_int; }
    int get_req_wlp() { return requirement.atr_wlp; }
    int get_req_agl() { return requirement.atr_agl; }
    int get_req_dxt() { return requirement.atr_dxt; }
    int get_req_chr() { return requirement.atr_chr; }
    bool get_can_crude() { return can_use[s_crude]; }
    bool get_can_bow() { return can_use[s_bow]; }
    bool get_can_crossbow() { return can_use[s_crossbow]; }
    bool get_can_short_blade() { return can_use[s_short_blade]; }
    bool get_can_long_blade() { return can_use[s_long_blade]; }
    bool get_can_axe() { return can_use[s_axe]; }
    bool get_can_halberd() { return can_use[s_halberd]; }
    bool get_can_hammer() { return can_use[s_hammer]; }
    bool get_can_spear() { return can_use[s_spear]; }
    bool get_can_special() { return can_use[s_special]; }
    bool get_can_t_none() { return can_wear[t_none]; }
    bool get_can_cloth() { return can_wear[cloth]; }
    bool get_can_light_armour() { return can_wear[light_armour]; }
    bool get_can_medium_armour() { return can_wear[medium_armour]; }
    bool get_can_heavy_armour() { return can_wear[heavy_armour]; }
};
char_class c_dummy("None", false,  false,  false, 0, 0, 0, 0, 0, 0,  true,  true,  true,  true,  false,  true,  false,  false,  true,  false,  true,  true,  true,  false,  false);
char_class c_warrior("Warrior", false,  false,  false, 11, 0, 0, 9, 0, 0,  true,  true,  true,  true, true,  true, true, true,  true, true,  true,  true,  true, true, true);
char_class c_thief("Thief", false,  false,  false, 0, 0, 0, 12, 12, 0,  true,  true,  true,  true, true,  true, true, true,  true, true,  true,  true,  true, false, false);
char_class c_cleric("Cleric", false, true,  false, 10, 10, 13, 0, 0, 10,  true, false, false, false, false, false, false, true, false, true,  true,  true,  true, true, false);
char_class c_mage("Magician", true, false,  false, 0, 12, 12, 0, 0, 10,  true, false, true, true, false, true, false, true, false, true,  true,  true,  true, false, false);
char_class c_druid("Druid", false, false, true, 0, 14, 12, 0, 0, 0,  true, true, false, false, false, false, false, false, false, true,  true,  true, false, false, false);

class prestige_class
{
private:
    string pc_display_name;
    bool free_variation;
    bool arcane_magic;
    bool cleric_magic;
    bool druid_magic;
    bool can_use[s_special];
    bool can_wear[heavy_armour];
public:
    char_class *required_class1;
    char_class *required_class2;
    prestige_class(string set_name, char_class *setreq1, char_class *setreq2, bool set_free_variation, bool setmagic1, bool setmagic2, bool setmagic3, bool can_use_crude, bool can_use_bow, bool can_use_crossbow, bool can_use_short_blade, bool can_use_long_blade, bool can_use_axe, bool can_use_halberd, bool can_use_hammer, bool can_use_spear, bool can_use_special , bool can_wear_t_none, bool can_wear_cloth, bool can_wear_light_armour, bool can_wear_medium_armour, bool can_wear_heavy_armour)
    {
        pc_display_name = set_name;
        free_variation = set_free_variation;
        required_class1 = setreq1;
        required_class2 = setreq2;
        arcane_magic = setmagic1;
        cleric_magic = setmagic2;
        druid_magic = setmagic3;
        can_use[s_crude] = can_use_crude;
        can_use[s_bow] = can_use_bow;
        can_use[s_crossbow] = can_use_crossbow;
        can_use[s_short_blade] = can_use_short_blade;
        can_use[s_long_blade] = can_use_long_blade;
        can_use[s_axe] = can_use_axe;
        can_use[s_halberd] = can_use_halberd;
        can_use[s_hammer] = can_use_hammer;
        can_use[s_spear] = can_use_spear;
        can_use[s_special] = can_use_special;
        can_wear[t_none] = can_wear_t_none;
        can_wear[cloth] = can_wear_cloth;
        can_wear[light_armour] = can_wear_light_armour;
        can_wear[medium_armour] = can_wear_medium_armour;
        can_wear[heavy_armour] = can_wear_heavy_armour;
    };
    prestige_class()
    {
        string set_name = "None";
        char_class setreq1 = c_dummy;
        char_class setreq2 = c_dummy;
        bool set_free_variation = true;
        bool setmagic1 = false;
        bool setmagic2 = false;
        bool setmagic3 = false;
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
    static prestige_class GetNull()
    {
    prestige_class *res = new prestige_class("None", &c_dummy, &c_dummy, true, false, false, false, true, true, true, true, false, true, false, false, true, false, true, true, true, false, false);
    return *res;
    };
    void set_req1(char_class *setclass1) { required_class1 = setclass1;}
    void set_req2(char_class *setclass2) { required_class2 = setclass2;}
	void set_pc_display_name(string set_name) { pc_display_name = set_name; }
	void set_arcane_magic(bool setmagic1) { arcane_magic = setmagic1; }
	void set_cleric_magic(bool setmagic2) { cleric_magic = setmagic2; }
	void set_druid_magic(bool setmagic3) { druid_magic = setmagic3; }
	void set_can_crude(bool can_use_crude) { can_use[s_crude] = can_use_crude; }
	void set_can_bow(bool can_use_bow) { can_use[s_bow] = can_use_bow; }
	void set_can_crossbow(bool can_use_crossbow) { can_use[s_crossbow] = can_use_crossbow; }
	void set_can_short_blade(bool can_use_short_blade) { can_use[s_short_blade] = can_use_short_blade; }
	void set_can_long_blade(bool can_use_long_blade) { can_use[s_long_blade] = can_use_long_blade; }
	void set_can_axe(bool can_use_axe) { can_use[s_axe] = can_use_axe; }
	void set_can_halberd(bool can_use_halberd) { can_use[s_halberd] = can_use_halberd; }
	void set_can_hammer(bool can_use_hammer) { can_use[s_hammer] = can_use_hammer; }
	void set_can_spear(bool can_use_spear) { can_use[s_spear] = can_use_spear; }
	void set_can_special(bool can_use_special) { can_use[s_special] = can_use_special; }
	void set_can_t_none(bool can_wear_t_none) { can_wear[t_none] = can_wear_t_none; }
	void set_can_cloth(bool can_wear_cloth) { can_wear[cloth] = can_wear_cloth; }
	void set_can_light_armour(bool can_wear_light_armour) { can_wear[light_armour] = can_wear_light_armour; }
	void set_can_medium_armour(bool can_wear_medium_armour) { can_wear[medium_armour] = can_wear_medium_armour; }
	void set_can_heavy_armour(bool can_wear_heavy_armour) { can_wear[heavy_armour] = can_wear_heavy_armour; }
    string get_pc_display_name() { return pc_display_name; }
    bool get_free_variaton() { return free_variation; }
    bool get_arcane_magic() { return arcane_magic; }
    bool get_cleric_magic() { return cleric_magic; }
    bool get_druid_magic() { return druid_magic; }
    bool get_can_crude() { return can_use[s_crude]; }
    bool get_can_bow() { return can_use[s_bow]; }
    bool get_can_crossbow() { return can_use[s_crossbow]; }
    bool get_can_short_blade() { return can_use[s_short_blade]; }
    bool get_can_long_blade() { return can_use[s_long_blade]; }
    bool get_can_axe() { return can_use[s_axe]; }
    bool get_can_halberd() { return can_use[s_halberd]; }
    bool get_can_hammer() { return can_use[s_hammer]; }
    bool get_can_spear() { return can_use[s_spear]; }
    bool get_can_special() { return can_use[s_special]; }
    bool get_can_t_none() { return can_wear[t_none]; }
    bool get_can_cloth() { return can_wear[cloth]; }
    bool get_can_light_armour() { return can_wear[light_armour]; }
    bool get_can_medium_armour() { return can_wear[medium_armour]; }
    bool get_can_heavy_armour() { return can_wear[heavy_armour]; }
};
prestige_class pc_dummy("None", &c_dummy, &c_dummy, true, false, false, false, true, true, true, true, false, true, false, false, true, false, true, true, true, false, false);
prestige_class pc_knight("Knight", &c_warrior, &c_cleric, false, false, false, false, true, true, true, true, false, true, false, false, true, false, true, true, true, false, false);



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
        ~inventory(){
        delete[] char_wpn[eq_wpn1];
        delete[] char_wpn[eq_wpn2];
        delete[] char_armour[eq_shld];
        delete[] char_armour[eq_hlm];
        delete[] char_armour[eq_clth1];
        delete[] char_armour[eq_clth2];
        delete[] char_armour[eq_ndrwr];
        delete[] char_armour[eq_arm_tors];
        delete[] char_armour[eq_arm_lgs];
        delete[] char_armour[eq_boots];
        delete[] char_armour[eq_ggntlet];
        delete[] char_armour[eq_clk];
        delete[] char_armour[eq_arrow];
        delete[] char_armour[eq_neck];}
};


class chr{
private:
    string display_name;
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
    prestige_class *pclass;
    inventory inv;
    chr(string setname, race1 *setrace, race2 *setrace2, char_class *setclass1, char_class *setclass2, prestige_class *setpclass, int setlvl)
    {
    display_name = setname;
    race = setrace;
    sec_race = setrace2;
    class1 = setclass1;
    class2 = setclass2;
    pclass = setpclass;
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
    void set_race1(race1 *setrace) { race = setrace;}
    void set_race2(race2 *setrace2) { sec_race = setrace2;}
    void set_class1(char_class *setclass1) { class1 = setclass1;}
    void set_class2(char_class *setclass2) { class2 = setclass2;}
    void set_pc(prestige_class *setpc){pclass = setpc;}
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
    int get_BaseStrength() { return (base_attrib.atr_str + sec_race->get_bon_str()); }
    int get_BaseIntelligence() { return (base_attrib.atr_int + sec_race->get_bon_int()); }
    int get_BaseWillpower() { return (base_attrib.atr_wlp + sec_race->get_bon_wlp()); }
    int get_BaseAgility() { return (base_attrib.atr_agl + sec_race->get_bon_agl()); }
    int get_BaseDexterity() { return (base_attrib.atr_dxt + sec_race->get_bon_dxt()); }
    int get_BaseCharisma() { return (base_attrib.atr_chr + sec_race->get_bon_chr()); }
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
    int getSrength() { return (get_BaseStrength() + get_mstr());}
    int getIntelligence() { return (get_BaseIntelligence() + get_mint());}
    int getWillpower() { return (get_BaseWillpower() + get_mwlp()); }
    int getAgility() { return (get_BaseAgility() + get_magl());}
    int getDexterity() { return (get_BaseDexterity() + get_mdxt());}
    int getCharisma() { return (get_BaseCharisma() + get_mchr());}
    ~chr()
    {
        delete[] race;
        delete[] sec_race;
        delete[] class1;
        delete[] class2;
        };
};

void Promote(chr *character, prestige_class *classis)
{
    if (classis->get_free_variaton()){
    bool requirements_meet[2];
if (character->class1 == classis->required_class1)
    requirements_meet[0] = true;
else
    requirements_meet[0] = false;
if (character->class2 == classis->required_class1)
    requirements_meet[1] = true;
    else
        requirements_meet[1] = false;
if (requirements_meet[0]||requirements_meet[1])
        character->set_pc(classis);
        else
            cerr << character->GetName() << "is not qualified to be a. " << classis->get_pc_display_name() << "." << endl;}
        else{
    bool requirements_meet[2];
    bool requirements_meet2[2];
    bool arch_requirements_meet[2];
if (character->class1 == classis->required_class1)
    requirements_meet[0] = true;
else
    requirements_meet[0] = false;
if (character->class2 == classis->required_class1)
    requirements_meet[1] = true;
else
    requirements_meet[1] = false;
if (character->class1 == classis->required_class2)
    requirements_meet2[0] = true;
else
    requirements_meet2[0] = false;
if (character->class2 == classis->required_class2)
    requirements_meet2[1] = true;
else
    requirements_meet2[1] = false;
if (requirements_meet[0]||requirements_meet[1])
        arch_requirements_meet[0] = true;
        else
        arch_requirements_meet[0] = false;
if (requirements_meet2[0]||requirements_meet2[1])
        arch_requirements_meet[1] = true;
        else
        arch_requirements_meet[1] = false;
if (arch_requirements_meet[0]&&arch_requirements_meet[1])
        character->set_pc(classis);
        else
            cerr << character->GetName() << "is not qualified to be a. " << classis->get_pc_display_name() << "." << endl;;}}




int main()
{
        string import1;
        int import2;
        int import3;
        int import4;
        int import5;
        material import6;
        element import7;
        w_type import8;
        w_type2 import9;
       ifstream inf("Sample.dat");
    if (!inf)
    {
        // Print an error and exit
        cerr << "Uh oh, Sample.dat could not be opened for reading!" << endl;
        exit(1);
    };
getline(inf, import1);
inf >> import2;
inf >> import3;
inf >>  import4;
inf >>  import5;
inf >>  import6;
inf >> import7;
inf >>  import8;
inf >>  import9;
wpn new_weapon(import1, import2, import3, import4, import5, import6, import7, import8, import9);
cout << new_weapon.GetW_display_name() << endl;
    return 0;
};
