
/*
	Macro: ERROR_WITH_TITLE()

	Parameters:
	0: CLASSNAME - Classname of item
	1: PRICE - Default item price
	2: STOCK - Default item stock
__________________________________________________________________*/
#define ITEM(CLASSNAME, PRICE, STOCK)\
	class CLASSNAME {\
		price = PRICE;\
		stock = STOCK;\
	};

class cfgAQStore {
	containerTypes[] = {"LandVehicle", "Air", "Ship"};
	containerRadius = 50;
	currencySymbol = "Рубль";
	sellFactor = 0.35;
	debug = 0;

	class categories {

		// ОРУЖИЕ TIR 1
		class Weapons_Pistols_T1 {          // Пистолеты Tir 1             || OK
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_PISTOLS";
			picture = "";
 			
			class rhs_weap_rsp30_white           {price = 1700;stock = 5;};  // ROP-30
			class rhs_weap_rsp30_green           {price = 1700;stock = 5;};  // RSP-30 (Green)
			class rhs_weap_rsp30_red             {price = 1700;stock = 5;};  // RSP-30 (Red)
			class hgun_Pistol_Signal_F           {price = 2600;stock = 5;}; // Taurus Judge
			class hgun_Pistol_heavy_02_F         {price = 5100;stock = 5;}; // Chiappa Rhino 60DS
			class rhs_weap_type94_new            {price = 9050;stock = 5;}; // Type 94 Nambu
			class hgun_Pistol_01_F               {price = 11000;stock = 5;};  // ПМ
			class rhs_weap_makarov_pm            {price = 11000;stock = 5;};  // ПМ (rhs)
			class rhs_weap_6p53                  {price = 13200;stock = 5;};  // 6П53
		};
		class Weapons_Shotguns_T1 {         // Дробовики Tir 1             || OK
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_SHOTGUNS";
			picture = "";

			class rhs_weap_Izh18                   {price = 15500;stock = 5;}; // IZh-18 12 Gauge
			class sgun_HunterShotgun_01_sawedoff_F {price = 16000;stock = 5;}; // CZ 581 (Sawed-Off)
			class sgun_HunterShotgun_01_F          {price = 19000;stock = 5;}; // CZ 581
			class rhs_weap_M590_5RD                {price = 21200;stock = 5;}; // M590A1 (Short)
			class rhs_weap_M590_8RD                {price = 23900;stock = 5;}; // M590A1 (Long)
		};
		class Weapons_SubmachineGuns_T1 {   // Пистолеты - пулеметы Tir 1  || OK
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_SUBMACHINEGUNS";
			picture = "";
		
			class rhs_weap_scorpion                {price = 24750;stock = 5;}; // M84A Scorpion
			class rhs_weap_savz61                  {price = 21000;stock = 5;}; // Sa vz.61
			class hgun_PDW2000_F                   {price = 25600;stock = 5;}; // CPW
			class rhs_weap_m3a1                    {price = 26800;stock = 5;}; // M3A1
		};
		class Weapons_MachineGun_T1 {       // Пулеметы Tir 1              || ??
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_MACHINEGUN";
			picture = "";

			class rhs_weap_mg42                    {price = 50;stock = 5;}; // MG42
			class rhs_weap_fnmag                   {price = 50;stock = 5;}; // FN MAG
			class rhs_weap_m240G                   {price = 50;stock = 5;}; // M240G
			class rhs_weap_m240B                   {price = 50;stock = 5;}; // M240B
		};
		class Weapons_Rifle_T1 {            // Штурмовые винтовки Tir 1    || OK
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_RIFLE";
			picture = "";

			class rhs_weap_savz58p            {price = 30000; stock = 5;}; // Sa vz. 58
			class rhs_weap_savz58p_black      {price = 30750; stock = 5;}; // Sa vz. 58 (Black)
			class rhs_weap_savz58p_rail       {price = 31500; stock = 5;}; // Sa vz. 58 (Rail)
			class rhs_weap_savz58p_rail_black {price = 32250; stock = 5;}; // Sa vz. 58 (Rail, Black)
			class rhs_weap_savz58v            {price = 33000; stock = 5;}; // Sa vz. 58V
			class rhs_weap_savz58v_rail_black {price = 33750; stock = 5;}; // Sa vz. 58V (Rail, Black)
			class rhs_weap_savz58v_rail       {price = 34500; stock = 5;}; // Sa vz. 58V (Rail)
			class rhs_weap_savz58v_rail_fold  {price = 35250; stock = 5;}; // Sa vz. 58V (Rail, Fold)
			class rhs_weap_savz58v_fold       {price = 36000; stock = 5;}; // Sa vz. 58V (Fold)
			class rhs_weap_savz58v_black      {price = 36750; stock = 5;}; // Sa vz. 58V (Black)
			class rhs_weap_savz58v_ris        {price = 37500; stock = 5;}; // Sa vz. 58V (RIS)
			class rhs_weap_savz58v_ris_fold   {price = 38250; stock = 5;}; // Sa vz. 58V (RIS, Fold)

			class rhs_weap_m70ab2             {price = 39000; stock = 5;}; // M70AB2
			class rhs_weap_MP44               {price = 39750; stock = 5;}; // MP44
			class rhs_weap_m70b1              {price = 40500; stock = 5;}; // M70B1
			class rhs_weap_m70b1n             {price = 41250; stock = 5;}; // M70B1N
			class rhs_weap_m70b3n             {price = 42000; stock = 5;}; // M70B3N
			class rhs_weap_m70b3n_pbg40       {price = 42750; stock = 5;}; // M70B3N (PBG)

			class arifle_Katiba_C_F           {price = 43500; stock = 5;}; // KH2002C Cama
			class arifle_Katiba_F             {price = 44250; stock = 5;}; // KH2002 Cama
			class arifle_Katiba_GL_F          {price = 45000; stock = 5;}; // KH2002 Cama KGL
			class rhs_weap_l1a1               {price = 45750; stock = 5;}; // L1A1 (Polymer)
			class rhs_weap_l1a1_wood          {price = 46500; stock = 5;}; // L1A1 (Wood)

			class arifle_SDAR_F               {price = 47250; stock = 5;}; // RFB SDAR
			class arifle_TRG20_F              {price = 48000; stock = 5;}; // CTAR-21
			class arifle_TRG21_F              {price = 48750; stock = 5;}; // TAR-21
			class arifle_TRG21_GL_F           {price = 49500; stock = 5;}; // GTAR-21 EGLM

			class arifle_Mk20C_F              {price = 50250; stock = 5;}; // F2000 Tactical (Камуфляжный)
			class arifle_Mk20C_plain_F        {price = 51000; stock = 5;}; // F2000 Tactical
			class arifle_Mk20_plain_F         {price = 51750; stock = 5;}; // F2000
			class arifle_Mk20_F               {price = 52500; stock = 5;}; // F2000 (Камуфляжный)
			class arifle_Mk20_GL_plain_F      {price = 53250; stock = 5;}; // F2000 EGLM
			class arifle_Mk20_GL_F            {price = 54000; stock = 5;}; // F2000 EGLM (Камуфляжный)

			class rhs_weap_g36c               {price = 54750; stock = 5;}; // HK G36C
			class rhs_weap_g36kv              {price = 55500; stock = 5;}; // HK G36KV
			class rhs_weap_g36kv_ag36         {price = 56250; stock = 5;}; // HK G36KV (AG36)

			class arifle_ARX_hex_F            {price = 57000; stock = 5;}; // Type 115 (гекс)
			class arifle_ARX_ghex_F           {price = 57750; stock = 5;}; // Type 115 (зелёный гекс)
			class arifle_ARX_blk_F            {price = 58500; stock = 5;}; // Type 115 (чёрный)

			class rhs_weap_vhsk2              {price = 59250; stock = 5;}; // VHS-K2
			class rhs_weap_vhsd2              {price = 60000; stock = 5;}; // VHS-D2
			class rhs_weap_vhsd2_ct15x        {price = 60750; stock = 5;}; // VHS-D2 (CT-1.5x)
			class rhs_weap_vhsd2_bg           {price = 61500; stock = 5;}; // VHS-D2 (VHS-BG)
			class rhs_weap_vhsd2_bg_ct15x     {price = 62250; stock = 5;}; // VHS-D2 (VHS-BG, CT-1.5x)

			class rhs_weap_mk17_CQC           {price = 63000; stock = 5;}; // Mk 17 Mod 0 (CQC)
			class rhs_weap_mk17_STD           {price = 63750; stock = 5;}; // Mk 17 Mod 0 (STD)
			class rhs_weap_mk17_LB            {price = 64500; stock = 5;}; // Mk 17 Mod 0 (LB)

			class arifle_CTAR_hex_F           {price = 65250; stock = 5;}; // QBZ-95-1 (гекс)
			class arifle_CTAR_ghex_F          {price = 66000; stock = 5;}; // QBZ-95-1 (зелёный гекс)
			class arifle_CTAR_blk_F           {price = 66750; stock = 5;}; // QBZ-95-1 (чёрный)

			class arifle_CTARS_hex_F          {price = 67500; stock = 5;}; // QBZ-95-1 LSW (гекс)
			class arifle_CTARS_ghex_F         {price = 68250; stock = 5;}; // QBZ-95-1 LSW (зелёный гекс)
			class arifle_CTARS_blk_F          {price = 69000; stock = 5;}; // QBZ-95-1 LSW (чёрный)

			class arifle_CTAR_GL_hex_F        {price = 69750; stock = 5;}; // QBZ-95-1 GL (гекс)
			class arifle_CTAR_GL_ghex_F       {price = 70500; stock = 5;}; // QBZ-95-1 GL (зелёный гекс)
			class arifle_CTAR_GL_blk_F        {price = 71250; stock = 5;}; // QBZ-95-1 GL (чёрный)

			class arifle_MSBS65_F             {price = 72000; stock = 5;}; // MSBS Grot
			class arifle_MSBS65_camo_F        {price = 72750; stock = 5;}; // MSBS Grot (камуфляжный)
			class arifle_MSBS65_sand_F        {price = 73500; stock = 5;}; // MSBS Grot (песочный)
			class arifle_MSBS65_black_F       {price = 74250; stock = 5;}; // MSBS Grot (чёрный)
 			class arifle_MSBS65_GL_F          {price = 75000; stock = 5;}; // MSBS Grot GL
			class arifle_MSBS65_GL_camo_F     {price = 75750; stock = 5;}; // MSBS Grot GL (камуфляжный)
			class arifle_MSBS65_GL_sand_F     {price = 76500; stock = 5;}; // MSBS Grot GL (песочный)
			class arifle_MSBS65_GL_black_F    {price = 77250; stock = 5;}; // MSBS Grot GL (чёрный)
 			class arifle_MSBS65_UBS_F         {price = 78000; stock = 5;}; // MSBS Grot SG
			class arifle_MSBS65_UBS_camo_F    {price = 78750; stock = 5;}; // MSBS Grot SG (камуфляжный)
			class arifle_MSBS65_UBS_sand_F    {price = 79500; stock = 5;}; // MSBS Grot SG (песочный)
			class arifle_MSBS65_UBS_black_F   {price = 80000; stock = 5;}; // MSBS Grot SG (чёрный)
 		};
		class Weapons_Sniper_T1 {           // Снайперские винтовки Tir 1  ||
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_SNIPERS";
			picture = "";

			class rhs_weap_m38                 {price = 50;stock = 5;}; // Винтовка Мосина M38
			class rhs_weap_m38_rail            {price = 50;stock = 5;}; // Винтовка Мосина M38 (рельс)
			class rhs_weap_mosin_sbr           {price = 50;stock = 5;}; // Mosin SBR
			class rhs_weap_kar98k              {price = 50;stock = 5;}; // Karabiner 98 Kurz
			class rhs_weap_m1garand_sa43       {price = 50;stock = 5;}; // M1 Garand
			class rhs_weap_m14                 {price = 50;stock = 5;}; // M14
			class rhs_weap_m14_d               {price = 50;stock = 5;}; // M14 (Desert)
			class rhs_weap_m14_fiberglass      {price = 50;stock = 5;}; // M14 (Fiberglass)
			class rhs_weap_m14_rail            {price = 50;stock = 5;}; // M14 (Rail)
			class rhs_weap_m14_rail_d          {price = 50;stock = 5;}; // M14 (Rail/Desert)
			class rhs_weap_m14_rail_fiberglass {price = 50;stock = 5;}; // M14 (Rail/Fiberglass)
			class rhs_weap_m14_rail_wd         {price = 50;stock = 5;}; // M14 (Rail/Woodland)
			class rhs_weap_m14_ris             {price = 50;stock = 5;}; // M14 (RIS)
			class rhs_weap_m14_ris_d           {price = 50;stock = 5;}; // M14 (RIS/Desert)
			class rhs_weap_m14_ris_fiberglass  {price = 50;stock = 5;}; // M14 (RIS/Fiberglass)
			class rhs_weap_m14_ris_wd          {price = 50;stock = 5;}; // M14 (RIS/Woodland)
			class rhs_weap_m14_wd              {price = 50;stock = 5;}; // M14 (Woodland)
			class srifle_DMR_06_camo_F         {price = 50;stock = 5;}; // M14 (камуфляжный)
			class srifle_DMR_06_hunter_F       {price = 50;stock = 5;}; // M14 (классический)
			class srifle_DMR_06_olive_F        {price = 50;stock = 5;}; // M14 (олива)

			class rhs_weap_m76                 {price = 50;stock = 5;}; // M76
			class rhs_weap_m14_socom           {price = 50;stock = 5;}; // SCOM 16
			class rhs_weap_m14_socom_rail      {price = 50;stock = 5;}; // SCOM 16 (Rail)
			class rhs_weap_m14ebrri            {price = 50;stock = 5;}; // M14 EBR-RI
		};
		class Weapons_Launchers_T1 {        // Пусковые установки Tir 1    ||
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_LAUNCHERS";
			picture = "";

			class rhs_weap_panzerfaust60       {price = 50;stock = 5;}; // Panzerfaust 60
			class rhs_weap_m72a7               {price = 50;stock = 5;}; // M72A7
			class rhs_weap_rpg18               {price = 50;stock = 5;}; // РПГ-18
			class rhs_weap_rpg26               {price = 50;stock = 5;}; // РПГ-26
			class rhs_weap_rshg2               {price = 50;stock = 5;}; // РШГ-2
			class rhs_weap_rpg75               {price = 50;stock = 5;}; // RPG-75
			class rhs_weap_m80                 {price = 50;stock = 5;}; // RBR-M80
			class rhs_weap_M136                {price = 50;stock = 5;}; // M136 (HEAT)
			class rhs_weap_M136_hedp           {price = 50;stock = 5;}; // M136 (HEDP)
			class rhs_weap_M136_hp             {price = 50;stock = 5;}; // M136 (HP)
		};
		class Ammo_T1 {                     // Боеприпасы для оружия Tir 1 ||
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_AMMO";
			picture = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\handgun_ca.paa";
			
			//Пистолеты
			class 6Rnd_45ACP_Cylinder                                  {price = 50;stock = 20;}; // Chiappa Rhino 60DS
			class rhs_mag_9x19_7n31_17                                 {price = 50;stock = 20;}; // Type 94 Nambu
			class rhs_mag_9x19_17                                      {price = 50;stock = 20;};
			class rhs_mag_6x8mm_mhp                                    {price = 50;stock = 20;};
			class hgun_Pistol_01_F                                     {price = 50;stock = 20;}; // ПМ
			class rhs_mag_9x18_8_57N181S                               {price = 50;stock = 20;}; // ПМ (rhs)
			class rhs_18rnd_9x21mm_7BT3                                {price = 50;stock = 20;}; // 6П53
			class rhs_18rnd_9x21mm_7N28                                {price = 50;stock = 20;};
			class rhs_18rnd_9x21mm_7N29                                {price = 50;stock = 20;};

			// Дробовики
			class rhsgref_1Rnd_00Buck                                  {price = 50;stock = 20;}; // IZh-18 12 Gauge
			class rhsgref_1Rnd_Slug                                    {price = 50;stock = 20;};
 			class rhsusf_5Rnd_00Buck                                   {price = 50;stock = 20;}; // 5Птр. 00
			class rhsusf_5Rnd_Slug                                     {price = 50;stock = 20;}; // 5Птр. 12г
			class rhsusf_5Rnd_FRAG                                     {price = 50;stock = 20;}; // 5Птр. 12г ФРАГ
			class rhsusf_5Rnd_HE                                       {price = 50;stock = 20;}; // 5Птр. 12г НЕ-ЕР
 			class rhsusf_8Rnd_00Buck                                   {price = 50;stock = 20;}; // 8Птр. 00
			class rhsusf_8Rnd_Slug                                     {price = 50;stock = 20;}; // 8Птр. 12г
			class rhsusf_8Rnd_FRAG                                     {price = 50;stock = 20;}; // 8Птр. 12г ФРАГ
			class rhsusf_8Rnd_HE                                       {price = 50;stock = 20;}; // 8Птр. 12г НЕ-ЕР
			class 2Rnd_12Gauge_Slug                                    {price = 50;stock = 20;}; // CZ 581
			class 2Rnd_12Gauge_Pellets                                 {price = 50;stock = 20;}; 
			class ACE_2Rnd_12Gauge_Pellets_No0_Buck                    {price = 50;stock = 20;}; // 12 Калибр 2 патр. #0 Картечь
			class ACE_2Rnd_12Gauge_Pellets_No1_Buck                    {price = 50;stock = 20;}; // 12 Калибр 2 патр. #1 Картечь
			class ACE_2Rnd_12Gauge_Pellets_No2_Buck                    {price = 50;stock = 20;}; // 12 Калибр 2 патр. #2 Картечь
			class ACE_2Rnd_12Gauge_Pellets_No3_Buck                    {price = 50;stock = 20;}; // 12 Калибр 2 патр. #3 Картечь
			class ACE_2Rnd_12Gauge_Pellets_No4_Buck                    {price = 50;stock = 20;}; // 12 Калибр 2 патр. #4 Картечь
			class ACE_2Rnd_12Gauge_Pellets_No4_Bird                    {price = 50;stock = 20;}; // 12 Калибр 2 патр. #4 Дробь

 			// Пистолеты-пулемёты
			class rhsgref_10rnd_765x17_vz61                            {price = 50;stock = 20;}; // Sa vz.61, M84A Scorpion
			class rhsgref_20rnd_765x17_vz61                            {price = 50;stock = 20;};
  			class 16Rnd_9x21_Mag                                       {price = 50;stock = 20;}; // CPW
			class 16Rnd_9x21_red_Mag                                   {price = 50;stock = 20;};
			class 16Rnd_9x21_yellow_Mag                                {price = 50;stock = 20;};
			class 16Rnd_9x21_green_Mag                                 {price = 50;stock = 20;};
			class 30Rnd_9x21_Mag                                       {price = 50;stock = 20;};
			class 30Rnd_9x21_Red_Mag                                   {price = 50;stock = 20;};
			class 30Rnd_9x21_Yellow_Mag                                {price = 50;stock = 20;};
			class 30Rnd_9x21_Green_Mag                                 {price = 50;stock = 20;};
			class rhsgref_30rnd_1143x23_M1T_SMG                        {price = 50;stock = 20;}; // M3A1
			class rhsgref_30rnd_1143x23_M1T_2mag_SMG                   {price = 50;stock = 20;};
			class rhsgref_30rnd_1143x23_M1911B_SMG                     {price = 50;stock = 20;};
			class rhsgref_30rnd_1143x23_M1911B_2mag_SMG                {price = 50;stock = 20;};

			// Пулемёты
			class hsgref_mg42_acc_AAsight                              {price = 50;stock = 1;}; // MG42
			class 150Rnd_762x51_Box                                    {price = 50;stock = 20;}; // FN MAG, M240G, M240B
			class 150Rnd_762x51_Box_Tracer                             {price = 50;stock = 20;};
			class rhsusf_50Rnd_762x51                                  {price = 50;stock = 20;};
			class rhsusf_50Rnd_762x51_m61_ap                           {price = 50;stock = 20;};
			class rhsusf_50Rnd_762x51_m80a1epr                         {price = 50;stock = 20;};
			class rhsusf_50Rnd_762x51_m82_blank                        {price = 50;stock = 20;};
			class rhsusf_50Rnd_762x51_m62_tracer                       {price = 50;stock = 20;};
     		class rhsusf_100Rnd_762x51                                 {price = 50;stock = 20;};
			class rhsusf_100Rnd_762x51_m61_ap                          {price = 50;stock = 20;};
			class rhsusf_100Rnd_762x51_m80a1epr                        {price = 50;stock = 20;};
			class rhsusf_100Rnd_762x51_m82_blank                       {price = 50;stock = 20;};
			class rhsusf_100Rnd_762x51_m62_tracer                      {price = 50;stock = 20;};
		
			// Автоматы
			class rhs_30Rnd_762x39mm_Savz58                            {price = 50;stock = 20;};// Sa vz.58
			class rhs_30Rnd_762x39mm_Savz58_tracer 					   {price = 50;stock = 20;};
 			class 30Rnd_762x39_AK12_Mag_F                              {price = 50;stock = 20;};
			class 30rnd_762x39_AK12_Arid_Mag_F                         {price = 50;stock = 20;};
			class 30rnd_762x39_AK12_Lush_Mag_F                         {price = 50;stock = 20;};
			class 30Rnd_762x39_AK12_Mag_Tracer_F                       {price = 50;stock = 20;};
			class 30rnd_762x39_AK12_Arid_Mag_Tracer_F                  {price = 50;stock = 20;};
			class 30rnd_762x39_AK12_Lush_Mag_Tracer_F                  {price = 50;stock = 20;};
			class 75rnd_762x39_AK12_Mag_F                              {price = 50;stock = 20;};
			class 75rnd_762x39_AK12_Lush_Mag_F                         {price = 50;stock = 20;};
			class 75rnd_762x39_AK12_Arid_Mag_F                         {price = 50;stock = 20;};
			class 75rnd_762x39_AK12_Mag_Tracer_F                       {price = 50;stock = 20;};
			class 75rnd_762x39_AK12_Lush_Mag_Tracer_F                  {price = 50;stock = 20;};
			class 75rnd_762x39_AK12_Arid_Mag_Tracer_F                  {price = 50;stock = 20;};
			class 30Rnd_762x39_Mag_F                                   {price = 50;stock = 20;};
			class 30Rnd_762x39_Mag_Green_F                             {price = 50;stock = 20;};
			class 30Rnd_762x39_Mag_Tracer_F                            {price = 50;stock = 20;};
			class 30Rnd_762x39_Mag_Tracer_Green_F                      {price = 50;stock = 20;};
			class 75Rnd_762x39_Mag_F                                   {price = 50;stock = 20;};
			class 75Rnd_762x39_Mag_Tracer_F                            {price = 50;stock = 20;};
			class rhs_10Rnd_762x39mm_tracer                            {price = 50;stock = 20;};
			class rhs_10Rnd_762x39mm_U                                 {price = 50;stock = 20;};
			class rhs_10Rnd_762x39mm                                   {price = 50;stock = 20;};
			class rhs_10Rnd_762x39mm_89                                {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_bakelite_tracer                   {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_bakelite_U                        {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_bakelite                          {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_bakelite_89                       {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_tracer                            {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_U                                 {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm                                   {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_89                                {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_polymer_tracer                    {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_polymer_U                         {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_polymer                           {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_polymer_89                        {price = 50;stock = 20;};
			class rhssaf_30Rnd_762x39mm_M67                            {price = 50;stock = 20;};
			class rhssaf_30Rnd_762x39mm_M78_tracer                     {price = 50;stock = 20;};
			class rhssaf_30Rnd_762x39_M82_api                          {price = 50;stock = 20;};
			class rhs_75Rnd_762x39mm_tracer                            {price = 50;stock = 20;};
			class rhs_75Rnd_762x39mm                                   {price = 50;stock = 20;};
			class rhs_75Rnd_762x39mm_89                                {price = 50;stock = 20;};
 			class rhsgref_25Rnd_792x33_SmE_StG                         {price = 50;stock = 20;}; // MP44
			class rhsgref_30Rnd_792x33_SmE_StG                         {price = 50;stock = 20;};
			class 30Rnd_65x39_caseless_green                           {price = 50;stock = 20;}; // KH2002C Cama
			class 30Rnd_65x39_caseless_green_mag_Tracer                {price = 50;stock = 20;};
			class ACE_30Rnd_65x39_caseless_green_mag_Tracer_Dim        {price = 50;stock = 20;}; 
			class rhs_mag_20Rnd_762x51_m61_fnfal 	                   {price = 50;stock = 20;}; // L1A1 (Polymer)
			class rhs_mag_20Rnd_762x51_m62_fnfal                       {price = 50;stock = 20;};
			class rhs_mag_20Rnd_762x51_m80_fnfal                       {price = 50;stock = 20;};
			class rhs_mag_20Rnd_762x51_m80a1_fnfal                     {price = 50;stock = 20;};
 			// STANAG 5.56x45
			class ACE_30Rnd_556x45_Stanag_Tracer_Dim                   {price = 50;stock = 20;};
			class ACE_30Rnd_556x45_Stanag_M995_AP_mag                  {price = 50;stock = 20;};
			class ACE_30Rnd_556x45_Stanag_Mk318_mag                    {price = 50;stock = 20;};
			class ACE_30Rnd_556x45_Stanag_Mk262_mag                    {price = 50;stock = 20;};
			class 20Rnd_556x45_UW_mag                                  {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag                                  {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_red                              {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_green                            {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Tracer_Yellow                    {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Tracer_Green                     {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Tracer_Red                       {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Sand                             {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Sand_green                       {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Sand_red                         {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Sand_Tracer_Yellow               {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Sand_Tracer_Green                {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Sand_Tracer_Red                  {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_M193_2MAG_Stanag                {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_M196_2MAG_Stanag_Tracer_Red     {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_M193_Stanag                     {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_M196_Stanag_Tracer_Red          {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_M200_Stanag                     {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_M855_Stanag                     {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_M855A1_Stanag                   {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_Mk262_Stanag                    {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_EPM_Tracer_Red           {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_EPM_Pull_Tracer_Red      {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_EPM_Pull                 {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_EPM_Ranger_Tracer_Red    {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_EPM_Ranger               {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_EPM                      {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan_Tracer_Red      {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_PMAG_Tracer_Red          {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_PMAG_Tan_Tracer_Red        {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_PMAG_Tracer_Red            {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_PMAG        			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_PMAG_Tan    			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_PMAG      			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan  			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk262_PMAG       			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk262_PMAG_Tan    			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_PMAG       			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_PMAG_Tan    			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_SCAR_Pull   			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_SCAR_Ranger 			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_SCAR        			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M200_Stanag       			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Red        {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_Stanag_Tracer_Red          {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_Stanag_Pull_Tracer_Red   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_Stanag_Pull_Tracer_Red     {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_Stanag_Pull                {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_Stanag_Pull              {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk262_Stanag_Pull               {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_Stanag_Pull               {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_Stanag_Ranger_Tracer_Red {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_Stanag_Ranger_Tracer_Red   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_Stanag_Ranger              {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_Stanag_Ranger            {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk262_Stanag_Ranger             {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_Stanag_Ranger             {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M193_Stanag                     {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M196_Stanag_Tracer_Red          {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_Stanag                     {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_Stanag                   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk262_Stanag                    {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_Stanag                    {price = 50;stock = 20;};
 			class rhs_mag_100Rnd_556x45_M855_cmag                      {price = 50;stock = 20;};
			class rhs_mag_100Rnd_556x45_M855A1_cmag                    {price = 50;stock = 20;};
			class rhs_mag_100Rnd_556x45_Mk262_cmag                     {price = 50;stock = 20;};
			class rhs_mag_100Rnd_556x45_Mk318_cmag                     {price = 50;stock = 20;};
			class rhs_mag_100Rnd_556x45_M855_cmag_mixed                {price = 50;stock = 20;};
			class rhs_mag_100Rnd_556x45_M855A1_cmag_mixed              {price = 50;stock = 20;};
 			class 150Rnd_556x45_Drum_Mag_F                             {price = 50;stock = 20;};
			class 150Rnd_556x45_Drum_Mag_Tracer_F                      {price = 50;stock = 20;};
			class rhssaf_100rnd_556x45_EPR_G36                         {price = 50;stock = 20;};
			class rhssaf_30rnd_556x45_TDIM_G36                         {price = 50;stock = 20;};
			class rhssaf_30rnd_556x45_EPR_G36                          {price = 50;stock = 20;};
			class rhssaf_30rnd_556x45_MDIM_G36                         {price = 50;stock = 20;};
			class rhssaf_30rnd_556x45_Tracers_G36                      {price = 50;stock = 20;};
			class rhssaf_30rnd_556x45_SPR_G36                          {price = 50;stock = 20;};
			class rhssaf_30rnd_556x45_SOST_G36                         {price = 50;stock = 20;};
			class rhsgref_30rnd_556x45_vhs2                            {price = 50;stock = 20;};
			class rhsgref_30rnd_556x45_vhs2_t                          {price = 50;stock = 20;};
		 	class rhs_mag_20Rnd_SCAR_762x51_m118_special               {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_m118_special_bk            {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_m61_ap                     {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_m61_ap_bk                  {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_m62_tracer                 {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_m62_tracer_bk              {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_m80_ball                   {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_m80_ball_bk                {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_m80a1_epr                  {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_m80a1_epr_bk               {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_mk316_special              {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_mk316_special_bk           {price = 50;stock = 20;};
 			class 100Rnd_580x42_hex_Mag_F                              {price = 50;stock = 20;};
			class 100Rnd_580x42_hex_Mag_Tracer_F                       {price = 50;stock = 20;};
			class 100Rnd_580x42_ghex_Mag_F                             {price = 50;stock = 20;};
			class 100Rnd_580x42_ghex_Mag_Tracer_F                      {price = 50;stock = 20;};
			class 100Rnd_580x42_Mag_F                                  {price = 50;stock = 20;};
			class 100Rnd_580x42_Mag_Tracer_F                           {price = 50;stock = 20;};
			class 30Rnd_580x42_Mag_F                       		       {price = 50;stock = 20;};
			class 30Rnd_580x42_Mag_Tracer_F                            {price = 50;stock = 20;};
 			class 30Rnd_65x39_caseless_msbs_mag                        {price = 50;stock = 20;};
			class 30Rnd_65x39_caseless_msbs_mag_Tracer                 {price = 50;stock = 20;};
			class ACE_30Rnd_65_Creedmor_msbs_mag                       {price = 50;stock = 20;};
			class ACE_30Rnd_65x47_Scenar_msbs_mag                      {price = 50;stock = 20;};
	
			// Снайперские винтовки
			class rhsgref_5Rnd_762x54_m38                              {price = 50;stock = 20;};
			class rhsgref_8Rnd_762x63_Tracer_M1T_M1rifle               {price = 50;stock = 20;};
			class rhsgref_8Rnd_762x63_M2B_M1rifle                      {price = 50;stock = 20;};
			class ACE_10Rnd_762x51_Mag_Tracer_Dim                      {price = 50;stock = 20;};
			class ACE_10Rnd_762x51_Mag_SD                              {price = 50;stock = 20;};
			class ACE_10Rnd_762x51_Mag_Tracer                          {price = 50;stock = 20;};
			class ACE_10Rnd_762x51_M118LR_Mag                          {price = 50;stock = 20;};
			class ACE_10Rnd_762x51_M993_AP_Mag                         {price = 50;stock = 20;};
			class ACE_10Rnd_762x51_Mk316_Mod_0_Mag                     {price = 50;stock = 20;};
			class ACE_10Rnd_762x51_Mk319_Mod_0_Mag                     {price = 50;stock = 20;};
			class ACE_20Rnd_762x51_Mag_Tracer_Dim                      {price = 50;stock = 20;};
			class ACE_20Rnd_762x51_Mag_SD                              {price = 50;stock = 20;};
			class ACE_20Rnd_762x51_Mag_Tracer                          {price = 50;stock = 20;};
			class ACE_20Rnd_762x51_M118LR_Mag                          {price = 50;stock = 20;};
			class ACE_20Rnd_762x51_M993_AP_Mag                         {price = 50;stock = 20;};
			class ACE_20Rnd_762x51_Mk316_Mod_0_Mag                     {price = 50;stock = 20;};
			class ACE_20Rnd_762x51_Mk319_Mod_0_Mag                     {price = 50;stock = 20;};
			class 10Rnd_Mk14_762x51_Mag                                {price = 50;stock = 20;};
			class 20Rnd_762x51_Mag                                     {price = 50;stock = 20;};
			class rhsusf_20Rnd_762x51_m118_special_Mag                 {price = 50;stock = 20;};
			class rhsusf_20Rnd_762x51_m62_Mag                          {price = 50;stock = 20;};
			class rhsusf_20Rnd_762x51_m80_Mag                          {price = 50;stock = 20;};
			class rhsusf_20Rnd_762x51_m993_Mag                         {price = 50;stock = 20;};
 			class rhssaf_10Rnd_792x57_m76_tracer                       {price = 50;stock = 20;};
			class rhsgref_10Rnd_792x57_m76                             {price = 50;stock = 20;};
		};

		// ОРУЖИЕ TIR 2
		class Weapons_Pistols_T2 {          // Пистолеты Tir 2
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_PISTOLS";
			picture = "";

			class rhs_weap_tt33                                   {price = 50;stock = 5;}; // ТТ-33
			class rhs_weap_pya                                    {price = 50;stock = 5;}; // ПЯ
			class hgun_Rook40_F                                 {price = 50;stock = 5;}; // МР-443 Грач
			class rhsusf_weap_m9                                  {price = 50;stock = 5;}; // M9 Beretta
			class rhssaf_weapon_cz99                                   {price = 50;stock = 5;}; // CZ99
			class rhssaf_weapon_cz99_etched                            {price = 50;stock = 5;}; // CZ99 (Engraves)
		};
		class Weapons_SubmachineGuns_T2 {   // Пистолеты - пулеметы Tir 2
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_SUBMACHINEGUNS";
			picture = "";

			class rhs_weap_pp2000                                 {price = 50;stock = 5;}; // PP-2000
			class SMG_05_F                                      {price = 50;stock = 5;}; // MP5K
			class rhssaf_weapon_m92                                    {price = 50;stock = 5;}; // M92
			class rhssaf_weapon_m92_fold                               {price = 50;stock = 5;}; // M92 (Сл.)
			class SMG_02_F                                      {price = 50;stock = 5;}; // Scorpion Evo 3 A1
			class rhs_weap_m3a1_specops                           {price = 50;stock = 5;}; // M3A1 (SD)
		};
		class Weapons_MachineGun_T2 {       // Пулеметы Tir 2
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_MACHINEGUNS";
			picture = "";

			class rhs_weap_rpk74m                                 {price = 50;stock = 5;}; // РПК-74М
			class rhs_weap_pkp                                    {price = 50;stock = 5;}; // ПКП
			class rhssaf_weapon_m84                                    {price = 50;stock = 5;}; // M84
			class rhs_weap_pkm                                    {price = 50;stock = 5;}; // ПКМ
			class MMG_01_tan_F                                  {price = 50;stock = 5;}; // HK121 (пустынный)
			class MMG_01_hex_F                                  {price = 50;stock = 5;}; // HK121 (гекс)
			class MMG_02_sand_F                                 {price = 50;stock = 5;}; // LWMMG (песочный)
			class MMG_02_black_F                                {price = 50;stock = 5;}; // LWMMG (чёрный)
			class MMG_02_camo_F                                 {price = 50;stock = 5;}; // LWMMG (MTP)
			class arifle_RPK12_F                                {price = 50;stock = 5;}; // RPK
			class arifle_RPK12_lush_f                           {price = 50;stock = 5;}; // RPK (обильная растительность)
			class arifle_RPK12_arid_f                           {price = 50;stock = 5;}; // RPK (сухая местность)
			class rhs_weap_rpk74m_npz                                  {price = 50;stock = 5;}; // RPK-74M (B-13)
		};
		class Weapons_Rifle_T2 {            // Штурмовые винтовки Tir 2
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_RIFLES";
			picture = "";

			class rhssaf_weapon_m21s_fold                              {price = 50;stock = 20;}; // M21S (Сл.)
			class rhssaf_weapon_m21s                                   {price = 50;stock = 20;}; // M21S
			class rhssaf_weapon_m21a_fold                              {price = 50;stock = 20;}; // M21A (Сл.)
			class rhssaf_weapon_m21a                                   {price = 50;stock = 20;}; // M21A
			class rhssaf_weapon_m21a_pbg40                             {price = 50;stock = 20;}; // M21 (PBG)
			class arifle_AKS_F                                  {price = 50;stock = 20;}; // AKS-74U
			class rhs_weap_aks74un                                {price = 50;stock = 20;}; // АКС-74УН
			class rhs_weap_aks74u                                 {price = 50;stock = 20;}; // АКС-74У
			class arifle_AKM_F                                  {price = 50;stock = 20;}; // AKM 
			class rhs_weap_pm63                                   {price = 50;stock = 20;}; // ПМ-63
			class rhs_weap_akmn                                   {price = 50;stock = 20;}; // AKMH 
			class rhs_weap_akm                                    {price = 50;stock = 20;}; // AKM 
			class rhs_weap_akmn_gp25                              {price = 50;stock = 20;}; // AKMH (ГП-25)
			class rhs_weap_akm_gp25                               {price = 50;stock = 20;}; // АКМ (ГП-25)
			class rhs_weap_akms                                   {price = 50;stock = 20;}; // АКМС
			class rhs_weap_akms_gp25                              {price = 50;stock = 20;}; // АКМС (ГП-25)
			class rhs_weap_aks74n                                 {price = 50;stock = 20;}; // АКС-74Н
			class rhs_weap_aks74                                  {price = 50;stock = 20;}; // АКС-74
			class rhs_weap_ak74                                   {price = 50;stock = 20;}; // АК-74
			class rhs_weap_ak74_3                                 {price = 50;stock = 20;}; // АК-74 (Зеленый)
			class rhs_weap_ak74_2                                 {price = 50;stock = 20;}; // АК-74 (слива)
			class rhs_weap_ak74n                                  {price = 50;stock = 20;}; // АК-74Н 
			class rhs_weap_ak74m_camo                             {price = 50;stock = 20;}; // АК-74М (камуф.)
			class rhs_weap_ak74m_desert                           {price = 50;stock = 20;}; // АК-74М (пуст.)
			class rhs_weap_ak74m_fullplum                         {price = 50;stock = 20;}; // АК-74М (слива)
			class rhs_weap_ak74n_2                                {price = 50;stock = 20;}; // АК-74Н (слива)
			class rhs_weap_ak74m                                  {price = 50;stock = 20;}; // АК-74М
			class rhs_weap_ak74m_gp25                             {price = 50;stock = 20;}; // АК-74М (ГП-25)
			class rhs_weap_ak74m_fullplum_gp25                    {price = 50;stock = 20;}; // АК-74М (ГП-25/слива)
			class rhs_weap_ak74_gp25                              {price = 50;stock = 20;}; // АК-74 (ГП-25)
			class rhs_weap_ak74n_gp25                             {price = 50;stock = 20;}; // АК-74Н (ГП-25)
			class rhs_weap_ak74n_2_gp25                           {price = 50;stock = 20;}; // АК-74Н (слива/ГП-25)
			class rhs_weap_aks74_2                                {price = 50;stock = 20;}; // АКС-74 (слива)
			class rhs_weap_aks74n_2                               {price = 50;stock = 20;}; // АКС-74Н (слива)
			class rhs_weap_aks74_gp25                             {price = 50;stock = 20;}; // АКС-74 (ГП-25)
			class rhs_weap_aks74n_gp25                            {price = 50;stock = 20;}; // АКС-74Н (ГП-25)
			class rhs_weap_ak105                                  {price = 50;stock = 20;}; // АК-105
			class rhs_weap_ak104                                  {price = 50;stock = 20;}; // АК-104
			class rhs_weap_ak103_1                                {price = 50;stock = 20;}; // АК-103-1
			class rhs_weap_ak103_2                                {price = 50;stock = 20;}; // АК-103-2
			class rhs_weap_ak103                                  {price = 50;stock = 20;}; // АК-103
			class rhs_weap_ak103_gp25                             {price = 50;stock = 20;}; // АК-103 (ГП-25)
			class rhs_weap_SCARH_USA_CQC                          {price = 50;stock = 20;}; // SCAR-H (USA/CQC)
			class rhs_weap_SCARH_USA_STD                          {price = 50;stock = 20;}; // SCAR-H (USA/STD)
			class rhs_weap_SCARH_USA_LB                           {price = 50;stock = 20;}; // SCAR-H (USA/LB)
			class arifle_AK12U_F                                {price = 50;stock = 20;}; // АК-15К
			class arifle_AK12U_lush_f                           {price = 50;stock = 20;}; // АК-15К (обильная растительность)
			class arifle_AK12U_arid_f                           {price = 50;stock = 20;}; // АК-15К (сухая местность)
			class arifle_AK12_F                                 {price = 50;stock = 20;}; // АК-15
			class arifle_AK12_lush_f                            {price = 50;stock = 20;}; // АК-15 (обильная растительность)
			class arifle_AK12_arid_f                            {price = 50;stock = 20;}; // АК-15 (сухая местность)
			class arifle_AK12_GL_F                              {price = 50;stock = 20;}; // АК-15 GL
			class arifle_AK12_GL_lush_F                         {price = 50;stock = 20;}; // АК-15 GL (обильная растительность)
			class arifle_AK12_GL_arid_F                         {price = 50;stock = 20;}; // АК-15 GL (сухая местность)
			class arifle_MXC_F                                  {price = 50;stock = 20;}; // MXC
			class arifle_MXC_khk_F                              {price = 50;stock = 20;}; // MXC (хаки)
			class arifle_MXC_Black_F                            {price = 50;stock = 20;}; // MXC (чёрный)
			class arifle_MX_F                                   {price = 50;stock = 20;}; // MX
			class arifle_MX_khk_F                               {price = 50;stock = 20;}; // MX (хаки)
			class arifle_MX_Black_F                             {price = 50;stock = 20;}; // MX (чёрный)
			class arifle_MX_GL_F                                {price = 50;stock = 20;}; // MX 3GL
			class arifle_MX_GL_khk_F                            {price = 50;stock = 20;}; // MX 3GL (хаки)
			class arifle_MX_GL_Black_F                          {price = 50;stock = 20;}; // MX 3GL (чёрный)
			class arifle_MXM_F                                  {price = 50;stock = 20;}; // MXM
			class arifle_MXM_khk_F                              {price = 50;stock = 20;}; // MXM (хаки)
			class arifle_MXM_Black_F                            {price = 50;stock = 20;}; // MXM (чёрный)
			class rhs_weap_m16a4_carryhandle                      {price = 50;stock = 20;}; // M16A4 (p)
			class rhs_weap_m16a4_carryhandle_M203                 {price = 50;stock = 20;}; // M16A4 (p/M203)
			class rhs_weap_m16a4                                  {price = 50;stock = 20;}; // M16A4 
			class rhs_weap_m16a4_imod                             {price = 50;stock = 20;}; // M16A4 (IMOD Stock)
			class rhs_weap_m16a4_imod_M203                        {price = 50;stock = 20;}; // M16A4 (IMOD Stock/M203)
			class rhs_weap_m4_carryhandle                         {price = 50;stock = 20;}; // M4 (p)
			class rhs_weap_m4_carryhandle_m203                    {price = 50;stock = 20;}; // M4 (p/M203)
			class rhs_weap_m4_carryhandle_m203S                   {price = 50;stock = 20;}; // M4 (p/M203S)
			class rhs_weap_m4a1_carryhandle_m203                  {price = 50;stock = 20;}; // M4A1 (M203) 
			class rhs_weap_m4_carryhandle_mstock                  {price = 50;stock = 20;}; // M4 (Carryhundle/Magpull Stock)
			class rhs_weap_m4a1_carryhandle_mstock                {price = 50;stock = 20;}; // M4A1 (Magpull Stock)
		};
		class Weapons_Sniper_T2 {           // Снайперские винтовки Tir 2
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_SNIPERS";
			picture = "";

			class srifle_DMR_01_F                               {price = 50;stock = 5;}; // VS-121
			class srifle_EBR_F                                  {price = 50;stock = 5;}; // Mk14 Mod 1 EBR
			class arifle_MSBS65_Mark_F                          {price = 50;stock = 5;}; // MSBS GROT MR
			class arifle_MSBS65_Mark_camo_F                     {price = 50;stock = 5;}; // MSBS (камуфляжный)
			class arifle_MSBS65_Mark_sand_F                     {price = 50;stock = 5;}; // MSBS (песочный)
			class arifle_MSBS65_Mark_black_F                    {price = 50;stock = 5;}; // MSBS (чёрный)
 			class rhs_weap_svdp                                   {price = 50;stock = 5;}; // СВДМ
			class rhs_weap_svdp_npz                               {price = 50;stock = 5;}; // СВДМ (НПЗ)
			class rhs_weap_svdp_wd                                {price = 50;stock = 5;}; // СВДМ (камуф.)
			class rhs_weap_svdp_wd_npz                            {price = 50;stock = 5;}; // СВДМ (камуф./НПЗ)
			class rhs_weap_svds                                   {price = 50;stock = 5;}; // СВДС
			class rhs_weap_svds_npz                               {price = 50;stock = 5;}; // СВДС (НПЗ)
			class srifle_DMR_07_hex_F                           {price = 50;stock = 5;}; // QBU-88 (гекс)
			class srifle_DMR_07_ghex_F                          {price = 50;stock = 5;}; // QBU-88 (зелёный гекс)
			class srifle_DMR_07_blk_F                           {price = 50;stock = 5;}; // QBU-88 (чёрный)
			class srifle_DMR_03_multicam_F                      {price = 50;stock = 5;}; // SIG 556 (камуфляжный)
			class srifle_DMR_03_tan_F                           {price = 50;stock = 5;}; // SIG 556 (песочный)
			class srifle_DMR_03_khaki_F                         {price = 50;stock = 5;}; // SIG 556 (хаки)
			class srifle_DMR_03_F                               {price = 50;stock = 5;}; // SIG 556 (чёрный)
			class srifle_DMR_03_woodland_F                      {price = 50;stock = 5;}; // SIG 556 (Woodland)
			class srifle_DMR_05_hex_F                           {price = 50;stock = 5;}; // Cyrus (гекс)
			class srifle_DMR_05_tan_f                           {price = 50;stock = 5;}; // Cyrus (пустынный)
			class srifle_DMR_05_blk_F                           {price = 50;stock = 5;}; // Cyrus (чёрный)
			class rhs_weap_t5000                                  {price = 50;stock = 5;}; // T-5000
			class rhs_weap_vss                                    {price = 50;stock = 5;}; // ВСС Винторез
			class rhs_weap_vss_npz                                {price = 50;stock = 5;}; // ВСС Винторез (НПЗ)
			class rhs_weap_vss_grip                               {price = 50;stock = 5;}; // ВСС Винторез (GRIP)
			class rhs_weap_vss_grip_npz                           {price = 50;stock = 5;}; // ВСС Винторез (GRIP/НПЗ)
		};
		class Weapons_Launchers_T2 {        // Пусковые установки Tir 2
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_LAUNCHERS";
			picture = "";

			class rhs_weap_igla                                   {price = 50;stock = 20;}; // 9K38
			class rhs_weap_fim92                                  {price = 50;stock = 20;}; // FIM-92F
			class rhs_weap_smaw                                   {price = 50;stock = 20;}; // MK153 Mod 0 SMAW (Black)
			class rhs_weap_smaw_green                             {price = 50;stock = 20;}; // MK153 Mod 0 SMAW (Green)
			class launch_RPG7_F                                 {price = 50;stock = 20;}; // RPG-7
			class rhs_weap_rpg7                                   {price = 50;stock = 20;}; // RPG-7B2
			class rhs_weap_maaws                                  {price = 50;stock = 20;}; // M3 MAAWS
		};
		class Ammo_T2 {                     // Боеприпасы для оружия Tir 2
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_AMMO";
			picture = "";
	
			// Пистолеты
			class rhs_mag_762x25_8                                     {price = 50;stock = 20;};
			class rhs_mag_9x19_7n31_17                                 {price = 50;stock = 20;};
			class rhs_mag_9x19_17                                      {price = 50;stock = 20;};
 			class 16Rnd_9x21_yellow_Mag                                {price = 50;stock = 20;};
			class 16Rnd_9x21_green_Mag                                 {price = 50;stock = 20;};
			class 16Rnd_9x21_red_Mag                                   {price = 50;stock = 20;};
			class 16Rnd_9x21_Mag                                       {price = 50;stock = 20;};
			class 30Rnd_9x21_Green_Mag                                 {price = 50;stock = 20;};
			class 30Rnd_9x21_Mag                                       {price = 50;stock = 20;};
			class 30Rnd_9x21_Yellow_Mag                                {price = 50;stock = 20;};
			class 30Rnd_9x21_Red_Mag                                   {price = 50;stock = 20;};
 			class rhsusf_mag_15Rnd_9x19_FMJ                            {price = 50;stock = 20;};
			class rhsusf_mag_15Rnd_9x19_JHP                            {price = 50;stock = 20;};
			class rhssaf_mag_15Rnd_9x19_FMJ                            {price = 50;stock = 20;};
			class rhssaf_mag_15Rnd_9x19_JHP                            {price = 50;stock = 20;};

			// Пистолеты - пулемёты
			class rhs_mag_9x19mm_7n21_20                               {price = 50;stock = 20;};
			class rhs_mag_9x19mm_7n31_20                               {price = 50;stock = 20;};
			class rhs_mag_9x19mm_7n21_44                               {price = 50;stock = 20;};
			class rhs_mag_9x19mm_7n31_44                               {price = 50;stock = 20;};
 			class 30Rnd_9x21_Mag_SMG_02_Tracer_Green                   {price = 50;stock = 20;};
			class 30Rnd_9x21_Mag_SMG_02                                {price = 50;stock = 20;};
			class 30Rnd_9x21_Mag_SMG_02_Tracer_Yellow                  {price = 50;stock = 20;};
			class 30Rnd_9x21_Mag_SMG_02_Tracer_Red                     {price = 50;stock = 20;};
			class rhsgref_30rnd_1143x23_M1T_SMG                        {price = 50;stock = 20;};
			class rhsgref_30rnd_1143x23_M1T_2mag_SMG                   {price = 50;stock = 20;};     
			class rhsgref_30rnd_1143x23_M1911B_SMG                     {price = 50;stock = 20;};
			class rhsgref_30rnd_1143x23_M1911B_2mag_SMG                {price = 50;stock = 20;};

			// Пулемёты
			// 5.45x39 AK
			class 150Rnd_762x54_Box                                    {price = 50;stock = 20;};
			class 150Rnd_762x54_Box_Tracer                             {price = 50;stock = 20;};
			class rhs_100Rnd_762x54mmR                                 {price = 50;stock = 20;};
			class rhs_100Rnd_762x54mmR_7BZ3                            {price = 50;stock = 20;};
			class rhs_100Rnd_762x54mmR_7N13                            {price = 50;stock = 20;};
			class rhs_100Rnd_762x54mmR_7N26                            {price = 50;stock = 20;};
			class rhs_100Rnd_762x54mmR_green                           {price = 50;stock = 20;};
			class rhssaf_250Rnd_762x54R                                {price = 50;stock = 20;};
			class 150Rnd_93x64_Mag                                     {price = 50;stock = 20;};
			class 130Rnd_338_Mag                                       {price = 50;stock = 20;};
	
 			// Штурмовые винтовки
			class rhsgref_30rnd_556x45_m21                             {price = 50;stock = 20;};
			class rhsgref_30rnd_556x45_m21_t                           {price = 50;stock = 20;};

			// 5.45x39 AK
			class 30Rnd_545x39_Mag_F                                   {price = 50;stock = 20;};
			class 30Rnd_545x39_Mag_Green_F                             {price = 50;stock = 20;};
			class 30Rnd_545x39_Mag_Tracer_F                            {price = 50;stock = 20;};
			class 30Rnd_545x39_Mag_Tracer_Green_F                      {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N6_AK                              {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N6M_AK                             {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_AK_green                            {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N6_green_AK                        {price = 50;stock = 20;};                     
			class rhs_30Rnd_545x39_7N6M_green_AK                       {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N10_camo_AK                        {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N22_camo_AK                        {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N10_desert_AK                      {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N22_desert_AK                      {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N10_plum_AK                        {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N22_plum_AK                        {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N6M_plum_AK                        {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_AK_plum_green                       {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N10_2mag_AK                        {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N10_2mag_camo_AK                   {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N10_2mag_desert_AK                 {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N10_2mag_plum_AK                   {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N10_AK                             {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N22_AK                             {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7U1_AK                              {price = 50;stock = 20;};
			class rhs_45Rnd_545X39_7N10_AK                             {price = 50;stock = 20;};
			class rhs_45Rnd_545X39_7N22_AK                             {price = 50;stock = 20;};
			class rhs_45Rnd_545X39_7N6M_AK                             {price = 50;stock = 20;};
			class rhs_45Rnd_545X39_7N6_AK                              {price = 50;stock = 20;};
			class rhs_45Rnd_545X39_AK_Green                            {price = 50;stock = 20;};
			class rhs_45Rnd_545X39_7U1_AK                              {price = 50;stock = 20;};
			class rhs_60Rnd_545X39_7N10_AK                             {price = 50;stock = 20;};
			class rhs_60Rnd_545X39_7N22_AK                             {price = 50;stock = 20;};
			class rhs_60Rnd_545X39_AK_Green                            {price = 50;stock = 20;};
 			class rhs_60Rnd_545X39_7U1_AK                              {price = 50;stock = 20;};
			// AK 7.62x39
			class 30Rnd_762x39_AK12_Mag_F                              {price = 50;stock = 20;};
			class 30rnd_762x39_AK12_Arid_Mag_F                         {price = 50;stock = 20;};
			class 30rnd_762x39_AK12_Lush_Mag_F                         {price = 50;stock = 20;};
			class 30Rnd_762x39_AK12_Mag_Tracer_F                       {price = 50;stock = 20;};
			class 30rnd_762x39_AK12_Arid_Mag_Tracer_F                  {price = 50;stock = 20;};
			class 30rnd_762x39_AK12_Lush_Mag_Tracer_F                  {price = 50;stock = 20;};
			class 75rnd_762x39_AK12_Mag_F                              {price = 50;stock = 20;};
			class 75rnd_762x39_AK12_Lush_Mag_F                         {price = 50;stock = 20;};
			class 75rnd_762x39_AK12_Arid_Mag_F                         {price = 50;stock = 20;};
			class 75rnd_762x39_AK12_Mag_Tracer_F                       {price = 50;stock = 20;};
			class 75rnd_762x39_AK12_Lush_Mag_Tracer_F                  {price = 50;stock = 20;};
			class 75rnd_762x39_AK12_Arid_Mag_Tracer_F                  {price = 50;stock = 20;};
			class 30Rnd_762x39_Mag_F                                   {price = 50;stock = 20;};
			class 30Rnd_762x39_Mag_Green_F                             {price = 50;stock = 20;};
			class 30Rnd_762x39_Mag_Tracer_F                            {price = 50;stock = 20;};
			class 30Rnd_762x39_Mag_Tracer_Green_F                      {price = 50;stock = 20;};
			class 75Rnd_762x39_Mag_F                                   {price = 50;stock = 20;};
			class 75Rnd_762x39_Mag_Tracer_F                            {price = 50;stock = 20;};
			class rhs_10Rnd_762x39mm_tracer                            {price = 50;stock = 20;};
			class rhs_10Rnd_762x39mm_U                                 {price = 50;stock = 20;};
			class rhs_10Rnd_762x39mm                                   {price = 50;stock = 20;};
			class rhs_10Rnd_762x39mm_89                                {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_bakelite_tracer                   {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_bakelite_U                        {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_bakelite                          {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_bakelite_89                       {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_tracer                            {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_U                                 {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm                                   {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_89                                {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_polymer_tracer                    {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_polymer_U                         {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_polymer                           {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_polymer_89                        {price = 50;stock = 20;};
			class rhssaf_30Rnd_762x39mm_M67                            {price = 50;stock = 20;};
			class rhssaf_30Rnd_762x39mm_M78_tracer                     {price = 50;stock = 20;};
			class rhssaf_30Rnd_762x39_M82_api                          {price = 50;stock = 20;};
			class rhs_75Rnd_762x39mm_tracer                            {price = 50;stock = 20;};
			class rhs_75Rnd_762x39mm_89                                {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_m118_special               {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_m118_special_bk            {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_m61_ap                     {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_m61_ap_bk                  {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_m62_tracer                 {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_m62_tracer_bk              {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_m80_ball                   {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_m80_ball_bk                {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_m80a1_epr                  {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_m80a1_epr_bk               {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_mk316_special              {price = 50;stock = 20;};
			class rhs_mag_20Rnd_SCAR_762x51_mk316_special_bk           {price = 50;stock = 20;};
			class ACE_100Rnd_65x39_caseless_mag_Tracer_Dim             {price = 50;stock = 20;};
			class ACE_30Rnd_65x39_caseless_mag_Tracer_Dim              {price = 50;stock = 20;};
			class 100Rnd_65x39_caseless_khaki_mag                      {price = 50;stock = 20;};
			class 100Rnd_65x39_caseless_khaki_mag_tracer               {price = 50;stock = 20;};
			class 30Rnd_65x39_caseless_khaki_mag                       {price = 50;stock = 20;};
			class 30Rnd_65x39_caseless_khaki_mag_Tracer                {price = 50;stock = 20;};
			class 100Rnd_65x39_caseless_mag                            {price = 50;stock = 20;};
			class 100Rnd_65x39_caseless_mag_Tracer                     {price = 50;stock = 20;};
			class 30Rnd_65x39_caseless_mag                             {price = 50;stock = 20;};
			class 30Rnd_65x39_caseless_mag_Tracer                      {price = 50;stock = 20;};
			class 100Rnd_65x39_caseless_black_mag                      {price = 50;stock = 20;};
			class 100Rnd_65x39_caseless_black_mag_tracer               {price = 50;stock = 20;};
			class 30Rnd_65x39_caseless_black_mag                       {price = 50;stock = 20;};
			class 30Rnd_65x39_caseless_black_mag_Tracer                {price = 50;stock = 20;};
			class ACE_30Rnd_65_Creedmor_mag                            {price = 50;stock = 20;};
			class ACE_30Rnd_65_Creedmor_khaki_mag                      {price = 50;stock = 20;};
			class ACE_30Rnd_65_Creedmor_black_mag                      {price = 50;stock = 20;};
			class ACE_30Rnd_65x47_Scenar_mag                           {price = 50;stock = 20;};
			class ACE_30Rnd_65x47_Scenar_khaki_mag                     {price = 50;stock = 20;};
			class ACE_30Rnd_65x47_Scenar_black_mag                     {price = 50;stock = 20;};
			// STANAG 5.56x45
			class ACE_30Rnd_556x45_Stanag_Tracer_Dim                   {price = 50;stock = 20;};
			class ACE_30Rnd_556x45_Stanag_M995_AP_mag                  {price = 50;stock = 20;};
			class ACE_30Rnd_556x45_Stanag_Mk318_mag                    {price = 50;stock = 20;};
			class ACE_30Rnd_556x45_Stanag_Mk262_mag                    {price = 50;stock = 20;};
			class 20Rnd_556x45_UW_mag                                  {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag                                  {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_red                              {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_green                            {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Tracer_Yellow                    {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Tracer_Green                     {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Tracer_Red                       {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Sand                             {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Sand_green                       {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Sand_red                         {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Sand_Tracer_Yellow               {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Sand_Tracer_Green                {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Sand_Tracer_Red                  {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_M193_2MAG_Stanag                {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_M196_2MAG_Stanag_Tracer_Red     {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_M193_Stanag                     {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_M196_Stanag_Tracer_Red          {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_M200_Stanag                     {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_M855_Stanag                     {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_M855A1_Stanag                   {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_Mk262_Stanag                    {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_EPM_Tracer_Red           {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_EPM_Pull_Tracer_Red      {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_EPM_Pull                 {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_EPM_Ranger_Tracer_Red    {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_EPM_Ranger               {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_EPM                      {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan_Tracer_Red      {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_PMAG_Tracer_Red          {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_PMAG_Tan_Tracer_Red        {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_PMAG_Tracer_Red            {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_PMAG        			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_PMAG_Tan    			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_PMAG      			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan  			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk262_PMAG       			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk262_PMAG_Tan    			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_PMAG       			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_PMAG_Tan    			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_SCAR_Pull   			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_SCAR_Ranger 			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_SCAR        			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M200_Stanag       			   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Red        {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_Stanag_Tracer_Red          {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_Stanag_Pull_Tracer_Red   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_Stanag_Pull_Tracer_Red     {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_Stanag_Pull                {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_Stanag_Pull              {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk262_Stanag_Pull               {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_Stanag_Pull               {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_Stanag_Ranger_Tracer_Red {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_Stanag_Ranger_Tracer_Red   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_Stanag_Ranger              {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_Stanag_Ranger            {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk262_Stanag_Ranger             {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_Stanag_Ranger             {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M193_Stanag                     {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M196_Stanag_Tracer_Red          {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_Stanag                     {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_Stanag                   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk262_Stanag                    {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_Stanag                    {price = 50;stock = 20;};
 			class rhs_mag_100Rnd_556x45_M855_cmag                      {price = 50;stock = 20;};
			class rhs_mag_100Rnd_556x45_M855A1_cmag                    {price = 50;stock = 20;};
			class rhs_mag_100Rnd_556x45_Mk262_cmag                     {price = 50;stock = 20;};
			class rhs_mag_100Rnd_556x45_Mk318_cmag                     {price = 50;stock = 20;};
			class rhs_mag_100Rnd_556x45_M855_cmag_mixed                {price = 50;stock = 20;};
			class rhs_mag_100Rnd_556x45_M855A1_cmag_mixed              {price = 50;stock = 20;};
 			class 150Rnd_556x45_Drum_Mag_F                             {price = 50;stock = 20;};
			class 150Rnd_556x45_Drum_Mag_Tracer_F                      {price = 50;stock = 20;};
			class rhssaf_100rnd_556x45_EPR_G36                         {price = 50;stock = 20;};
			class rhssaf_30rnd_556x45_TDIM_G36                         {price = 50;stock = 20;};
			class rhssaf_30rnd_556x45_EPR_G36                          {price = 50;stock = 20;};
			class rhssaf_30rnd_556x45_MDIM_G36                         {price = 50;stock = 20;};
			class rhssaf_30rnd_556x45_Tracers_G36                      {price = 50;stock = 20;};
			class rhssaf_30rnd_556x45_SPR_G36                          {price = 50;stock = 20;};
			class rhssaf_30rnd_556x45_SOST_G36                         {price = 50;stock = 20;};
			class rhsgref_30rnd_556x45_vhs2                            {price = 50;stock = 20;};
			class rhsgref_30rnd_556x45_vhs2_t                          {price = 50;stock = 20;};
		 	class 100Rnd_580x42_hex_Mag_F                              {price = 50;stock = 20;};
			class 100Rnd_580x42_hex_Mag_Tracer_F                       {price = 50;stock = 20;};
			class 100Rnd_580x42_ghex_Mag_F                             {price = 50;stock = 20;};
			class 100Rnd_580x42_ghex_Mag_Tracer_F                      {price = 50;stock = 20;};
			class 100Rnd_580x42_Mag_F                                  {price = 50;stock = 20;};
			class 100Rnd_580x42_Mag_Tracer_F                           {price = 50;stock = 20;};
			class 30Rnd_580x42_Mag_F                       		       {price = 50;stock = 20;};
			class 30Rnd_580x42_Mag_Tracer_F                            {price = 50;stock = 20;};
 			class 30Rnd_65x39_caseless_msbs_mag                        {price = 50;stock = 20;};
			class 30Rnd_65x39_caseless_msbs_mag_Tracer                 {price = 50;stock = 20;};
			class ACE_30Rnd_65_Creedmor_msbs_mag                       {price = 50;stock = 20;};
			class ACE_30Rnd_65x47_Scenar_msbs_mag                      {price = 50;stock = 20;};
			class 150Rnd_556x45_Drum_Green_Mag_F                       {price = 50;stock = 20;};
			class 150Rnd_556x45_Drum_Green_Mag_Tracer_F                {price = 50;stock = 20;};

	   		//Снайперские винтовки
			class ACE_10Rnd_762x54_Tracer_mag                          {price = 50;stock = 20;}; 
			class 10Rnd_762x54_Mag                                     {price = 50;stock = 20;}; 
			class rhs_10Rnd_762x54mmR_7N1                              {price = 50;stock = 20;}; 
			class rhs_10Rnd_762x54mmR_7N14                             {price = 50;stock = 20;}; 
			class ACE_10Rnd_762x51_Mag_Tracer_Dim                      {price = 50;stock = 20;}; 
			class ACE_10Rnd_762x51_Mag_SD                              {price = 50;stock = 20;}; 
			class ACE_10Rnd_762x51_Mag_Tracer                          {price = 50;stock = 20;}; 
			class ACE_10Rnd_762x51_M118LR_Mag                          {price = 50;stock = 20;}; 
			class ACE_10Rnd_762x51_M993_AP_Mag                         {price = 50;stock = 20;}; 
			class ACE_10Rnd_762x51_Mk316_Mod_0_Mag                     {price = 50;stock = 20;}; 
			class ACE_10Rnd_762x51_Mk319_Mod_0_Mag                     {price = 50;stock = 20;}; 
			class ACE_20Rnd_762x51_Mag_Tracer_Dim                      {price = 50;stock = 20;}; 
			class ACE_20Rnd_762x51_Mag_SD                              {price = 50;stock = 20;}; 
			class ACE_20Rnd_762x51_Mag_Tracer                          {price = 50;stock = 20;}; 
			class ACE_20Rnd_762x51_M118LR_Mag                          {price = 50;stock = 20;}; 
			class ACE_20Rnd_762x51_M993_AP_Mag                         {price = 50;stock = 20;}; 
			class ACE_20Rnd_762x51_Mk316_Mod_0_Mag                     {price = 50;stock = 20;}; 
			class ACE_20Rnd_762x51_Mk319_Mod_0_Mag                     {price = 50;stock = 20;}; 
			class 10Rnd_Mk14_762x51_Mag                                {price = 50;stock = 20;}; 
			class 20Rnd_762x51_Mag                                     {price = 50;stock = 20;}; 
			class rhsusf_20Rnd_762x51_m118_special_Mag                 {price = 50;stock = 20;}; 
			class rhsusf_20Rnd_762x51_m62_Mag                          {price = 50;stock = 20;}; 
			class rhsusf_20Rnd_762x51_m80_Mag                          {price = 50;stock = 20;}; 
			class rhsusf_20Rnd_762x51_m993_Mag                         {price = 50;stock = 20;}; 
			class ACE_10Rnd_580x42_DBP88_Mag                           {price = 50;stock = 20;}; 
			class ACE_20Rnd_65_Creedmor_mag                            {price = 50;stock = 20;}; 
			class 20Rnd_650x39_Cased_Mag_F                             {price = 50;stock = 20;}; 
			class ACE_20Rnd_65x47_Scenar_mag                           {price = 50;stock = 20;}; 
			class 10Rnd_93x64_DMR_05_Mag                               {price = 50;stock = 20;}; 
			class rhs_5Rnd_338lapua_t5000                              {price = 50;stock = 20;}; 
			class rhs_10rnd_9x39mm_SP5                                 {price = 50;stock = 20;}; 
			class rhs_10rnd_9x39mm_SP6                                 {price = 50;stock = 20;}; 
			class rhs_20rnd_9x39mm_SP5                                 {price = 50;stock = 20;}; 
			class rhs_20rnd_9x39mm_SP6                                 {price = 50;stock = 20;}; 
	
			// Пусковые установки
		 	class Titan_AA                                             {price = 50;stock = 20;};
			class rhs_mag_9k38_rocket                                  {price = 50;stock = 20;};
			class rhs_fim92_mag                                        {price = 50;stock = 20;};
			class rhs_mag_smaw_HEDP                                    {price = 50;stock = 20;};
			class rhs_mag_smaw_HEAA                                    {price = 50;stock = 20;};
			class rhs_rpg7_OG7V_mag                                    {price = 50;stock = 20;};
			class rhs_rpg7_PG7VL_mag                                   {price = 50;stock = 20;};
			class rhs_rpg7_PG7VM_mag                                   {price = 50;stock = 20;};
			class rhs_rpg7_PG7VR_mag                                   {price = 50;stock = 20;};
			class rhs_rpg7_PG7VS_mag                                   {price = 50;stock = 20;};
			class rhs_rpg7_PG7V_mag                                    {price = 50;stock = 20;};
			class RPG7_F                                               {price = 50;stock = 20;};
			class rhs_rpg7_TBG7V_mag                                   {price = 50;stock = 20;};
			class rhs_rpg7_type69_airburst_mag                         {price = 50;stock = 20;};
			class MRAWS_HE_F                                           {price = 50;stock = 20;};
			class MRAWS_HEAT_F                                         {price = 50;stock = 20;};
			class rhs_mag_maaws_HE                                     {price = 50;stock = 20;};
			class rhs_mag_maaws_HEDP                                   {price = 50;stock = 20;};
			class rhs_mag_maaws_HEAT                                   {price = 50;stock = 20;};
	 	};

		// ОРУЖИЕ TIR 3
		class Weapons_Pistols_T3 {          // Пистолеты Tir 3
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_PISTOLS";
			picture = "";
		
			class rhs_weap_pb_6p9                                  {price = 50;stock = 20;}; // 6П9
			class rhsusf_weap_m1911a1                              {price = 50;stock = 20;}; // M1911A1
			class hgun_ACPC2_F                                   {price = 50;stock = 20;}; // Custom Covert II
			class hgun_P07_F                                     {price = 50;stock = 20;}; // P99
			class hgun_P07_khk_F                                 {price = 50;stock = 20;};// P99 (хаки)
			class hgun_P07_blk_F                                 {price = 50;stock = 20;};// P99 (чёрный)
			class hgun_Pistol_heavy_01_F                         {price = 50;stock = 20;};// FNX-45 Tactical
			class hgun_Pistol_heavy_01_green_F                   {price = 50;stock = 20;};// FNX-45 Tactical (зелёный)
			class rhsusf_weap_glock17g4                            {price = 50;stock = 20;};// Glock 17
			class rhs_weap_savz61_folded                           {price = 50;stock = 20;};// Sa vz/ 61
			class rhs_weap_pp2000_folded                           {price = 50;stock = 20;};// PP-2000 (Folded)
		};
		class Weapons_SubmachineGuns_T3 {   // ПП Tir 3
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_SUBMACHINEGUNS";
			picture = "";
		
			class SMG_03C_hex                                  {price = 50;stock = 20;}; // P90 (гекс)
			class SMG_03C_camo                                 {price = 50;stock = 20;}; // P90 (камуфляжный)
			class SMG_03C_khaki                                {price = 50;stock = 20;}; // P90 (хаки)
			class SMG_03C_black                                {price = 50;stock = 20;}; // P90 (чёрный)
			class SMG_03C_TR_hex                               {price = 50;stock = 20;}; // P90 TR (гекс)
			class SMG_03C_TR_camo                              {price = 50;stock = 20;}; // P90 TR (камуфляжный)
			class SMG_03C_TR_khaki                             {price = 50;stock = 20;}; // P90 TR (хаки)
			class SMG_03C_TR_black                             {price = 50;stock = 20;}; // P90 TR (чёрный)
			class SMG_03_hex                                   {price = 50;stock = 20;}; // PS90 (гекс)
			class SMG_03_camo                                  {price = 50;stock = 20;}; // PS90 (камуфляжный)
			class SMG_03_khaki                                 {price = 50;stock = 20;}; // PS90 (хаки)
			class SMG_03_black                                 {price = 50;stock = 20;}; // PS90 (чёрный)
			class SMG_03_TR_hex                                {price = 50;stock = 20;}; // PS90 TR (гекс)
			class SMG_03_TR_camo                               {price = 50;stock = 20;}; // PS90 TR (камуфляжный)
			class SMG_03_TR_khaki                              {price = 50;stock = 20;}; // PS90 TR (хаки)
			class SMG_03_TR_black                              {price = 50;stock = 20;}; // PS90 TR (чёрный)
			class SMG_01_F                                     {price = 50;stock = 20;}; // Vector SMG
			class rhsusf_weap_MP7A2                              {price = 50;stock = 20;}; // MP7A2
			class rhsusf_weap_MP7A2_aor1                         {price = 50;stock = 20;}; // MP7A2 (AOR1)
			class rhsusf_weap_MP7A2_desert                       {price = 50;stock = 20;}; // MP7A2 (Desert)
			class rhsusf_weap_MP7A2_winter                       {price = 50;stock = 20;}; // MP7A2 (Winter)
		};
		class Weapons_MachineGun_T3 {       // Пулеметы Tir 3
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_MACHINEGUNS";
			picture = "";
		
			class arifle_MX_SW_F                               {price = 50;stock = 20;};// MX LSW
			class arifle_MX_SW_khk_F                           {price = 50;stock = 20;};// MX LSW (хаки)
			class arifle_MX_SW_Black_F                         {price = 50;stock = 20;}; // MX LSW (чёрный)
			class rhssaf_weapon_minimi                                {price = 50;stock = 20;}; // FN Minimi Para (RIS)
			class LMG_03_F                                     {price = 50;stock = 20;}; // FN Minimi SPW
			class LMG_Zafir_F                                  {price = 50;stock = 20;}; // Negev NG7
			class LMG_Mk200_black_F                            {price = 50;stock = 20;}; // Stoner 99 LMG (чёрный)
			class LMG_Mk200_F                                  {price = 50;stock = 20;}; // Stoner 99 LMG
			class rhs_weap_m249                                  {price = 50;stock = 20;}; // M249
			class rhs_weap_m249_pip                              {price = 50;stock = 20;}; // M249 PIP
			class rhs_weap_m249_pip_L_para                       {price = 50;stock = 20;}; // M249 PIP (Long/Para)
			class rhs_weap_m249_light_L                          {price = 50;stock = 20;};// M249 PIP (Long/LCBA)
			class rhs_weap_m249_pip_L                            {price = 50;stock = 20;}; // M249 PIP (Long/Savit)
			class rhs_weap_m249_pip_ris                          {price = 50;stock = 20;}; // M249 PIP (RIS)
			class rhs_weap_m249_light_S                          {price = 50;stock = 20;};// M249 PIP (Short/LCBA)
			class rhs_weap_m249_pip_S_para                       {price = 50;stock = 20;};// M249 PIP (Short/Para)
			class rhs_weap_m249_pip_S                            {price = 50;stock = 20;};// M249 PIP (Short/Savit)
		};
		class Weapons_Rifle_T3 {            // Штурмовые винтовки Tir 3
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_RIFLES";
			picture = "";

			class rhs_weap_asval                                 {price = 50;stock = 20;};// АС Вал
			class rhs_weap_asval_npz                             {price = 50;stock = 20;};// АС Вал (НПЗ)
			class rhs_weap_asval_grip                            {price = 50;stock = 20;};// АС Вал (GRIP)
			class rhs_weap_asval_grip_npz                        {price = 50;stock = 20;};// АС Вал (GRIP/НПЗ)
			class rhssaf_weapon_m21s_pr                               {price = 50;stock = 20;};// M21S (Rail)
			class rhssaf_weapon_m21a_pr                               {price = 50;stock = 20;}; // M21A (Rail)
			class rhssaf_weapon_m21a_pr_pbg40                         {price = 50;stock = 20;};// M21A (Rail/PBG)
			class rhs_weap_akm_zenitco01_b33                     {price = 50;stock = 20;};// AKM (Зенитка/Б-33)
			class rhs_weap_akmn_gp25_npz                         {price = 50;stock = 20;};// AKMH (ГП-25/НПЗ)
			class rhs_weap_ak74n_npz                             {price = 50;stock = 20;};// AK-74H (НПЗ)
			class rhs_weap_ak74n_2_npz                           {price = 50;stock = 20;};// AK-74H (слива/Б-13)
			class rhs_weap_ak74n_gp25_npz                        {price = 50;stock = 20;};// AK-74H (ГП-25/НПЗ)
			class rhs_weap_ak74n_2_gp25_npz                      {price = 50;stock = 20;};// AK-74H (слива/ГП-25/Б-13)
			class rhs_weap_aks74n_npz                            {price = 50;stock = 20;};// AKC-74H (НПЗ)
			class rhs_weap_aks74n_gp25_npz                       {price = 50;stock = 20;};// AKC-74H (ГП-25/НПЗ)
			class rhs_weap_aks74n_2_npz                          {price = 50;stock = 20;};// AKC-74H (слива/Б-13)
			class rhs_weap_ak104_npz                             {price = 50;stock = 20;};// AK-104 (Б-13)
			class rhs_weap_ak105_npz                             {price = 50;stock = 20;};// AK-105 (Б-13)
			class rhs_weap_ak103_2_npz                           {price = 50;stock = 20;};// AK-103-2 (Б-13)
			class rhs_weap_ak103_npz                             {price = 50;stock = 20;};// AK-103 (Б-13)
			class rhs_weap_ak103_gp25_npz                        {price = 50;stock = 20;}; // AK-103 (ГП-25/Б-13)
			class rhs_weap_ak74m_camo_npz                        {price = 50;stock = 20;};// AK-74M (камуф./Б-13)
			class rhs_weap_ak74m_desert_npz                      {price = 50;stock = 20;};// AK-74M (пуст./Б-13)
			class rhs_weap_ak74m_fullplum_npz                    {price = 50;stock = 20;};// AK-74M (слива/Б-13)
			class rhs_weap_ak74m_npz                             {price = 50;stock = 20;}; // AK-74M (Б-13)
			class rhs_weap_ak103_1_npz                           {price = 50;stock = 20;};// AK-103-1 (Б-13)
			class rhs_weap_ak74m_fullplum_gp25_npz               {price = 50;stock = 20;};// AK-74M (ГП-25/слива/Б-13)
			class rhs_weap_ak74m_gp25_npz                        {price = 50;stock = 20;}; // AK-74M (ГП-25/Б-13)
			class rhs_weap_ak103_zenitco01                       {price = 50;stock = 20;}; // AK-103 (Зенитка)
			class rhs_weap_ak103_zenitco01_npz                   {price = 50;stock = 20;}; // AK-103 (Зенитка/Б-13)
			class rhs_weap_ak74mr                                {price = 50;stock = 20;}; // AK-74MP (УУК)
			class rhs_weap_ak74mr_gp25                           {price = 50;stock = 20;}; // AK-74MP (УУК/ГП-25)
			class rhs_weap_ak104_zenitco01                       {price = 50;stock = 20;}; // AK-104 (Зенитка)
			class rhs_weap_ak105_zenitco01                       {price = 50;stock = 20;};// AK-105 (Зенитка)
			class rhs_weap_ak74m_zenitco01                       {price = 50;stock = 20;};// AK-74M (Зенитка)
			class rhs_weap_ak104_zenitco01_npz                   {price = 50;stock = 20;}; // AK-104 (Зенитка/Б-13)
			class rhs_weap_ak104_zenitco01_b33                   {price = 50;stock = 20;};// AK-104 (Зенитка/Б-33)
			class rhs_weap_ak105_zenitco01_npz                   {price = 50;stock = 20;};// AK-105 (Зенитка/Б-13)
			class rhs_weap_ak105_zenitco01_b33                   {price = 50;stock = 20;}; // AK-105 (Зенитка/Б-33)
			class rhs_weap_ak74m_zenitco01_npz                   {price = 50;stock = 20;}; // AK-74M (Зенитка/Б-13)
			class rhs_weap_ak74m_zenitco01_b33                   {price = 50;stock = 20;}; // AK-74M (Зенитка/Б-33)
			class rhs_weap_ak103_zenitco01_b33                   {price = 50;stock = 20;}; // AK-103 (Зенитка/Б-33)
 			class rhs_weap_m4a1                                  {price = 50;stock = 20;}; // M4A1 PIP
			class rhs_weap_m4a1_m203s_d                          {price = 50;stock = 20;}; // M4A1 PIP (Desert/M203S)
			class rhs_weap_m4a1_m203s                            {price = 50;stock = 20;}; // M4A1 PIP (M203S)
			class rhs_weap_m4a1_m203s_wd                         {price = 50;stock = 20;};// M4A1 PIP (Woodland/M203S)
			class rhs_weap_m4a1_m203                             {price = 50;stock = 20;};// M4A1 PIP (M203)
			class rhs_weap_m4a1_m320                             {price = 50;stock = 20;}; // M4A1 PIP (M320)
			class rhs_weap_m4a1_wd                               {price = 50;stock = 20;};// M4A1 PIP (Woodland)
			class rhs_weap_m4a1_d                                {price = 50;stock = 20;};// M4A1 PIP (Desert)
			class rhs_weap_m4a1_d_mstock                         {price = 50;stock = 20;};// M4A1 PIP (Desert/Magpull Stock)
			class rhs_weap_m4a1_mstock                           {price = 50;stock = 20;}; // M4A1 PIP (Magpull Stock)
			class rhs_weap_m4a1_wd_mstock                        {price = 50;stock = 20;};// M4A1 PIP (Woodland/Magpull Stock)
			class rhs_weap_m4                                    {price = 50;stock = 20;};// M4
			class rhs_weap_m4_mstock                             {price = 50;stock = 20;};// M4 (Magpull Stock)
			class rhs_weap_m4_m203S                              {price = 50;stock = 20;};// M4 (M203S)
			class rhs_weap_m4_m203                               {price = 50;stock = 20;};// M4 (M203)
			class rhs_weap_m4_m320                               {price = 50;stock = 20;};// M4 (M320)
			class rhs_weap_mk18_KAC_d                            {price = 50;stock = 20;}; // Mk 18 Mod 1 (Desert/SOPMOD Stock)
			class rhs_weap_mk18_KAC                              {price = 50;stock = 20;};// Mk 18 Mod 1 (SOPMOD Stock)
			class rhs_weap_mk18_KAC_wd                           {price = 50;stock = 20;}; // Mk 18 Mod 1 (Woodland/SOPMOD Stock)
			class rhs_weap_mk18_KAC_bk                           {price = 50;stock = 20;};// Mk 18 Mod 1 (Black Rail/SOPMOD Stock)
			class rhs_weap_mk18_d                                {price = 50;stock = 20;};// Mk 18 Mod 1 (Desert)
			class rhs_weap_mk18_wd                               {price = 50;stock = 20;};// Mk 18 Mod 1 (Woodland)
			class rhs_weap_mk18                                  {price = 50;stock = 20;};// Mk 18 Mod 1
			class rhs_weap_mk18_bk                               {price = 50;stock = 20;};// Mk 18 Mod 1 (Black Rail)
			class rhs_weap_mk18_m320                             {price = 50;stock = 20;};// Mk 18 Mod 1 (M320)
			class rhs_weap_m4a1_blockII_d                        {price = 50;stock = 20;}; // M4A1 Block II (Desert)
			class rhs_weap_m4a1_blockII                          {price = 50;stock = 20;}; // M4A1 Block II
			class rhs_weap_m4a1_blockII_wd                       {price = 50;stock = 20;}; // M4A1 Block II (Woodland)
			class rhs_weap_m4a1_blockII_M203_d                   {price = 50;stock = 20;};  // M4A1 Block II (Desert/M203)
			class rhs_weap_m4a1_blockII_bk                       {price = 50;stock = 20;}; // // M4A1 Block II (Black Rail)
			class rhs_weap_m4a1_blockII_M203_bk                  {price = 50;stock = 20;}; // M4A1 Block II (Black Rail/M203)
			class rhs_weap_m4a1_blockII_M203                     {price = 50;stock = 20;}; // M4A1 Block II (M203)
			class rhs_weap_m4a1_blockII_M203_wd                  {price = 50;stock = 20;}; // M4A1 Block II (Woodland/M203)
			class rhs_weap_m4a1_blockII_KAC_bk                   {price = 50;stock = 20;}; // M4A1 Block II (Black Rail/SOPMOD Stock)
			class rhs_weap_m4a1_blockII_KAC_d                    {price = 50;stock = 20;}; // M4A1 Block II (Desert/SOPMOD Stock)
			class rhs_weap_m4a1_blockII_KAC                      {price = 50;stock = 20;}; // M4A1 Block II (SOPMOD Stock)
			class rhs_weap_m4a1_blockII_KAC_wd                   {price = 50;stock = 20;}; // M4A1 Block II (Woodland/SOPMOD Stock)
			class arifle_SPAR_01_snd_F                         {price = 50;stock = 20;}; // HK416A5 11" (песочный)
			class arifle_SPAR_01_khk_F                         {price = 50;stock = 20;}; // HK416A5 11" (хаки)
			class arifle_SPAR_01_blk_F                         {price = 50;stock = 20;}; // HK416A5 11" (чёрный)
			class arifle_SPAR_01_GL_snd_F                      {price = 50;stock = 20;}; // HK416A5 11" GL(песочный)
			class arifle_SPAR_01_GL_khk_F                      {price = 50;stock = 20;}; // HK416A5 11" GL(хаки)
			class arifle_SPAR_01_GL_blk_F                      {price = 50;stock = 20;}; // HK416A5 11" GL(чёрный)
			class arifle_SPAR_02_snd_F                         {price = 50;stock = 20;}; // HK416A5 14.5" (песочный)
			class arifle_SPAR_02_khk_F                         {price = 50;stock = 20;}; // HK416A5 14.5" (хаки)
			class arifle_SPAR_02_blk_F                         {price = 50;stock = 20;}; // HK416A5 14.5" (чёрный)
			class rhs_weap_hk416d10                              {price = 50;stock = 20;};// HK416 D10
			class rhs_weap_hk416d10_LMT                          {price = 50;stock = 20;}; // HK416 D10 (SOPMOD Stock)
			class rhs_weap_hk416d10_LMT_d                        {price = 50;stock = 20;}; // HK416 D10 (SOPMOD Stock/Desert)
			class rhs_weap_hk416d10_LMT_wd                       {price = 50;stock = 20;}; // HK416 D10 (SOPMOD Stock/Woodland)
			class rhs_weap_hk416d10_m320                         {price = 50;stock = 20;}; // HK416 D10 (M320)
			class arifle_SPAR_03_snd_F                         {price = 50;stock = 20;}; // HK417A2 20" (песочный)
			class arifle_SPAR_03_khk_F                         {price = 50;stock = 20;}; // HK417A2 20" (хаки)
			class arifle_SPAR_03_blk_F                         {price = 50;stock = 20;}; // HK417A2 20" (чёрный)
			class rhs_weap_m27iar                                {price = 50;stock = 20;};// M27 IAR
			class rhs_weap_m27iar_grip                           {price = 50;stock = 20;}; // M27 IAR (KAC Grip)
			class rhs_weap_hk416d145                             {price = 50;stock = 20;}; // HK416 D14.5
			class rhs_weap_hk416d145_d                           {price = 50;stock = 20;}; // HK416 D14.5 (Desert Grass)
			class rhs_weap_hk416d145_d_2                         {price = 50;stock = 20;}; // HK416 D14.5 (Desert Net)
			class rhs_weap_hk416d145_wd                          {price = 50;stock = 20;}; // HK416 D14.5 (Woodland Grass)
			class rhs_weap_hk416d145_wd_2                        {price = 50;stock = 20;}; // HK416 D14.5 (Woodland Net)
			class rhs_weap_hk416d145_m320                        {price = 50;stock = 20;}; // HK416 D14.5 (320)
		};
		class Weapons_Sniper_T3 {           // Снайперские винтовки Tir 3
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_SNIPERS";
			picture = "";
		
			class rhs_weap_sr25                                  {price = 790;stock = 5;}; // Mk 11 Mod 0
			class rhs_weap_sr25_d                                {price = 790;stock = 5;}; // Mk 11 Mod 0 (Desert)
			class rhs_weap_sr25_ec                               {price = 790;stock = 5;}; // Mk 11 Mod 0 (EC)
			class rhs_weap_sr25_ec_d                             {price = 790;stock = 5;}; // Mk 11 Mod 0 (EC/Desert)
			class rhs_weap_sr25_ec_wd                            {price = 790;stock = 5;}; // Mk 11 Mod 0 (EC/Woodland)
			class rhs_weap_sr25_wd                               {price = 790;stock = 5;}; // Mk 11 Mod 0 (Woodland)
			class srifle_DMR_04_Tan_F                          {price = 790;stock = 5;}; // ASP-1 Kir (пустынный)
			class srifle_DMR_04_F                              {price = 790;stock = 5;}; // ASP-1 Kir (чёрный)
			class srifle_DMR_02_camo_F                         {price = 790;stock = 5;}; // Noreen 'Bad News' ULR (камуфляжный)
			class srifle_DMR_02_sniper_F                       {price = 790;stock = 5;}; // Noreen 'Bad News' ULR (песочный)
			class srifle_DMR_02_F                              {price = 790;stock = 5;}; // Noreen 'Bad News' ULR (чёрный)
			class rhs_weap_m24sws                                {price = 790;stock = 5;}; // M24 SWS
			class rhs_weap_m24sws_d                              {price = 790;stock = 5;}; // M24 SWS (Desert)
			class rhs_weap_m24sws_wd                             {price = 790;stock = 5;}; // M24 SWS (Woodland)
			class rhs_weap_m40a5                                 {price = 790;stock = 5;}; // M40A5
			class rhs_weap_m40a5_d                               {price = 790;stock = 5;}; // M40A5 (Desert)
			class rhs_weap_m40a5_wd                              {price = 790;stock = 5;}; // M40A5 (Woodland)
			class rhs_weap_XM2010                                {price = 790;stock = 5;}; // M2010 ESR
			class rhs_weap_XM2010_wd                             {price = 790;stock = 5;}; // M2010 ESR (камуф.)
			class rhs_weap_XM2010_sa                             {price = 790;stock = 5;}; // M2010 ESR (полупуст.)
			class rhs_weap_XM2010_d                              {price = 790;stock = 5;}; // M2010 ESR (пуст.)
			class srifle_GM6_F                                 {price = 790;stock = 5;}; // GM6 Lynx
			class srifle_GM6_ghex_F                            {price = 790;stock = 5;}; // GM6 Lynx (зелёный гекс)
			class srifle_GM6_camo_F                            {price = 790;stock = 5;}; // GM6 Lynx (камуфляжный)
			class srifle_LRR_F                                 {price = 790;stock = 5;}; // M200 Intervention
			class srifle_LRR_camo_F                            {price = 790;stock = 5;}; // M200 Intervention (камуфляжный)
			class srifle_LRR_tna_F                             {price = 790;stock = 5;}; // M200 Intervention (тропики)
			class rhssaf_weapon_m82a1                                 {price = 790;stock = 5;}; // M82A1
			class rhs_weap_M107                                  {price = 790;stock = 5;}; // M107
			class rhs_weap_M107_d                                {price = 790;stock = 5;}; // M107 (Desert)
			class rhs_weap_M107_w                                {price = 790;stock = 5;}; // M107 (Woodland)
		};
		class Weapons_Launchers_T3 {        // Пусковые установки Tir 3
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_LAUNCHERS";
			picture = "";
		
			class launch_MRAWS_sand_F                          {price = 790;stock = 5;};// MAAWS Mk4 Mod 1 (песочное)
			class launch_MRAWS_olive_F                         {price = 790;stock = 5;};// MAAWS Mk4 Mod 1 (оливковое)
			class launch_MRAWS_green_F                         {price = 790;stock = 5;};// // MAAWS Mk4 Mod 1 (зеленое)
			class launch_MRAWS_sand_rail_F                     {price = 790;stock = 5;};// MAAWS Mk4 Mod 0 (песочное)
			class launch_MRAWS_olive_rail_F                    {price = 790;stock = 5;};// MAAWS Mk4 Mod 0 (оливковое)
			class launch_MRAWS_green_rail_F                    {price = 790;stock = 5;};// MAAWS Mk4 Mod 0 (зеленое)
			class launch_NLAW_F                                {price = 790;stock = 5;};// NLAW
			class launch_RPG32_F                               {price = 790;stock = 5;};// РПГ-32
			class launch_RPG32_green_F                         {price = 790;stock = 5;};// РПГ-32 (зелёный)
			class launch_RPG32_ghex_F                          {price = 790;stock = 5;};// РПГ-32 (зелёный гекс)
			class launch_O_Vorona_green_F                      {price = 790;stock = 5;};// Метис-М (зелёный)
			class launch_O_Vorona_brown_F                      {price = 790;stock = 5;};// Метис-М (коричневый)
			class rhs_weap_fgm148                              {price = 790;stock = 5;};// FGM-148 Javelin
			class launch_B_Titan_short_tna_F                   {price = 790;stock = 5;};// Titan MPRL Compact (тропики)
			class launch_I_Titan_short_F                       {price = 790;stock = 5;}; // Titan MPRL Compact (оливковая)
			class launch_O_Titan_short_ghex_F                  {price = 790;stock = 5;};// Titan MPRL Compact (зеленый гекс)
			class launch_O_Titan_short_F                       {price = 790;stock = 5;};// Titan MPRL Compact (койот)
			class launch_B_Titan_short_F                {price = 790;stock = 5;};// Titan MPRL Compact (песочная)
			class launch_I_Titan_F                             {price = 790;stock = 5;};// Titan MPRL (цифровая)
			class launch_B_Titan_tna_F                         {price = 790;stock = 5;};// Titan MPRL (тропики)
			class launch_B_Titan_F                             {price = 790;stock = 5;};// Titan MPRL (песочная)
			class launch_B_Titan_olive_F                       {price = 790;stock = 5;};// Titan MPRL (оливковый)
			class launch_O_Titan_ghex_F                        {price = 790;stock = 5;}; // Titan MPRL (зеленый гекс)
			class launch_I_Titan_eaf_F                         {price = 790;stock = 5;};// Titan MPRL (геометрический узор)
			class launch_O_Titan_F                             {price = 790;stock = 5;};// Titan MPRL (гекс)
		};
		class Ammo_T3 {                     // Боеприпасы для оружия Tir 3
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_AMMO";
			picture = "";

			// Пистолеты
			class rhs_mag_9x18_8_57N181S                               {price = 50;stock = 20;};
			class 9Rnd_45ACP_Mag                                       {price = 50;stock = 20;};
			class rhsusf_mag_7x45acp_MHP                               {price = 50;stock = 20;};
			class 16Rnd_9x21_yellow_Mag                                {price = 50;stock = 20;};
			class 16Rnd_9x21_green_Mag                                 {price = 50;stock = 20;};
			class 16Rnd_9x21_red_Mag                                   {price = 50;stock = 20;};
			class 16Rnd_9x21_Mag                                       {price = 50;stock = 20;};
			class 30Rnd_9x21_Green_Mag                                 {price = 50;stock = 20;};
			class 30Rnd_9x21_Mag                                       {price = 50;stock = 20;};
			class 30Rnd_9x21_Yellow_Mag                                {price = 50;stock = 20;};
			class 30Rnd_9x21_Red_Mag                                   {price = 50;stock = 20;};
			class 11Rnd_45ACP_Mag                                      {price = 50;stock = 20;};
			class rhsusf_mag_17Rnd_9x19_FMJ                            {price = 50;stock = 20;};
			class rhsusf_mag_17Rnd_9x19_JHP                            {price = 50;stock = 20;};
			class rhsgref_10rnd_765x17_vz61                            {price = 50;stock = 20;};
			class rhsgref_20rnd_765x17_vz61                            {price = 50;stock = 20;};
			class rhs_mag_9x19mm_7n21_20                               {price = 50;stock = 20;};
			class rhs_mag_9x19mm_7n31_20                               {price = 50;stock = 20;};
			class rhs_mag_9x19mm_7n21_44                               {price = 50;stock = 20;};
			class rhs_mag_9x19mm_7n31_44                               {price = 50;stock = 20;};

			// ПП
			class 50Rnd_570x28_SMG_03                                  {price = 50;stock = 20;};
			class 30Rnd_45ACP_Mag_SMG_01                               {price = 50;stock = 20;};
			class 30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow                 {price = 50;stock = 20;};
			class 30Rnd_45ACP_Mag_SMG_01_Tracer_Green                  {price = 50;stock = 20;};
			class 30Rnd_45ACP_Mag_SMG_01_Tracer_Red                    {price = 50;stock = 20;};
			class rhsusf_mag_40Rnd_46x30_AP                            {price = 50;stock = 20;};
			class rhsusf_mag_40Rnd_46x30_FMJ                           {price = 50;stock = 20;};
			class rhsusf_mag_40Rnd_46x30_JHP                           {price = 50;stock = 20;};
 
			// Пулеметы
			class ACE_100Rnd_65x39_caseless_mag_Tracer_Dim             {price = 50;stock = 20;};
			class ACE_30Rnd_65x39_caseless_mag_Tracer_Dim              {price = 50;stock = 20;};
			class 100Rnd_65x39_caseless_khaki_mag                      {price = 50;stock = 20;};
			class 100Rnd_65x39_caseless_khaki_mag_tracer               {price = 50;stock = 20;};
			class 30Rnd_65x39_caseless_khaki_mag                       {price = 50;stock = 20;};
			class 30Rnd_65x39_caseless_khaki_mag_Tracer                {price = 50;stock = 20;};
			class 100Rnd_65x39_caseless_mag                            {price = 50;stock = 20;};
			class 100Rnd_65x39_caseless_mag_Tracer                     {price = 50;stock = 20;};
			class 30Rnd_65x39_caseless_mag                             {price = 50;stock = 20;};
			class 30Rnd_65x39_caseless_mag_Tracer                      {price = 50;stock = 20;};
			class 100Rnd_65x39_caseless_black_mag                      {price = 50;stock = 20;};
			class 100Rnd_65x39_caseless_black_mag_tracer               {price = 50;stock = 20;};
			class 30Rnd_65x39_caseless_black_mag                       {price = 50;stock = 20;};
			class 30Rnd_65x39_caseless_black_mag_Tracer                {price = 50;stock = 20;};
			class rhsusf_200Rnd_556x45_mixed_soft_pouch_ucp            {price = 50;stock = 20;};
			class rhsusf_200Rnd_556x45_mixed_soft_pouch_coyote         {price = 50;stock = 20;};
			class rhsusf_200Rnd_556x45_mixed_soft_pouch                {price = 50;stock = 20;};
			class rhsusf_200Rnd_556x45_soft_pouch_ucp                  {price = 50;stock = 20;};
			class rhsusf_200Rnd_556x45_soft_pouch_coyote               {price = 50;stock = 20;};
			class rhsusf_200Rnd_556x45_soft_pouch                      {price = 50;stock = 20;};
			class rhsusf_200Rnd_556x45_M855_mixed_soft_pouch_ucp       {price = 50;stock = 20;};
			class rhsusf_200Rnd_556x45_M855_mixed_soft_pouch_coyote    {price = 50;stock = 20;};
			class rhsusf_200Rnd_556x45_M855_mixed_soft_pouch           {price = 50;stock = 20;};
			class rhsusf_200Rnd_556x45_M855_soft_pouch_ucp             {price = 50;stock = 20;};
			class rhsusf_200Rnd_556x45_M855_soft_pouch_coyote          {price = 50;stock = 20;};
			class rhsusf_200Rnd_556x45_M855_soft_pouch                 {price = 50;stock = 20;};
			class rhsusf_200rnd_556x45_mixed_box                       {price = 50;stock = 20;};
			class rhsusf_200Rnd_556x45_box                             {price = 50;stock = 20;};
			class rhsusf_200rnd_556x45_M855_mixed_box                  {price = 50;stock = 20;};
			class rhsusf_200rnd_556x45_M855_box                        {price = 50;stock = 20;};
			class 200Rnd_556x45_Box_F                                  {price = 50;stock = 20;};
			class 200Rnd_556x45_Box_Red_F                              {price = 50;stock = 20;};
			class 200Rnd_556x45_Box_Tracer_F                           {price = 50;stock = 20;};
			class 200Rnd_556x45_Box_Tracer_Red_F                       {price = 50;stock = 20;};
			class rhsusf_100Rnd_556x45_M200_soft_pouch                 {price = 50;stock = 20;};
			class rhsusf_100Rnd_556x45_M200_soft_pouch_coyote          {price = 50;stock = 20;};
			class rhsusf_100Rnd_556x45_M200_soft_pouch_ucp             {price = 50;stock = 20;};
			class rhsusf_100Rnd_556x45_M855_soft_pouch                 {price = 50;stock = 20;};
			class rhsusf_100Rnd_556x45_M855_soft_pouch_coyote          {price = 50;stock = 20;};
			class rhsusf_100Rnd_556x45_M855_soft_pouch_ucp             {price = 50;stock = 20;};
			class rhsusf_100Rnd_556x45_M855_mixed_soft_pouch           {price = 50;stock = 20;};
			class rhsusf_100Rnd_556x45_M855_mixed_soft_pouch_coyote    {price = 50;stock = 20;};
			class rhsusf_100Rnd_556x45_M855_mixed_soft_pouch_ucp       {price = 50;stock = 20;};
			class rhsusf_100Rnd_556x45_soft_pouch                      {price = 50;stock = 20;};
			class rhsusf_100Rnd_556x45_soft_pouch_coyote               {price = 50;stock = 20;};
			class rhsusf_100Rnd_556x45_soft_pouch_ucp                  {price = 50;stock = 20;};
			class rhsusf_100Rnd_556x45_mixed_soft_pouch                {price = 50;stock = 20;};
			class rhsusf_100Rnd_556x45_mixed_soft_pouch_coyote         {price = 50;stock = 20;};
			class rhsusf_100Rnd_556x45_mixed_soft_pouch_ucp            {price = 50;stock = 20;};
			class rhsusf_100Rnd_556x45_M995_soft_pouch                 {price = 50;stock = 20;};
			class rhsusf_100Rnd_556x45_M995_soft_pouch_coyote          {price = 50;stock = 20;};
			class rhsusf_100Rnd_556x45_M995_soft_pouch_ucp             {price = 50;stock = 20;};
			class 150Rnd_762x54_Box                                    {price = 50;stock = 20;};
			class 150Rnd_762x54_Box_Tracer                             {price = 50;stock = 20;};
			class 200Rnd_65x39_cased_Box_Red                           {price = 50;stock = 20;};
			class 200Rnd_65x39_cased_Box                               {price = 50;stock = 20;};
			class 200Rnd_65x39_cased_Box_Tracer                        {price = 50;stock = 20;};
			class 200Rnd_65x39_cased_Box_Tracer_Red                    {price = 50;stock = 20;};
			class ACE_200Rnd_65x39_cased_Box_Tracer_Dim                {price = 50;stock = 20;};

			// Штурмовые винтовки
			class rhs_10rnd_9x39mm_SP5                                 {price = 50;stock = 20;};
			class rhs_10rnd_9x39mm_SP6                                 {price = 50;stock = 20;};
			class rhs_20rnd_9x39mm_SP5                                 {price = 50;stock = 20;};
			class rhs_20rnd_9x39mm_SP6                                 {price = 50;stock = 20;};
			class rhsgref_30rnd_556x45_m21                             {price = 50;stock = 20;};
			class rhsgref_30rnd_556x45_m21_t                           {price = 50;stock = 20;};
			// AK 7.62x39
			class 30Rnd_762x39_AK12_Mag_F                              {price = 50;stock = 20;};
			class 30rnd_762x39_AK12_Arid_Mag_F                         {price = 50;stock = 20;};
			class 30rnd_762x39_AK12_Lush_Mag_F                         {price = 50;stock = 20;};
			class 30Rnd_762x39_AK12_Mag_Tracer_F                       {price = 50;stock = 20;};
			class 30rnd_762x39_AK12_Arid_Mag_Tracer_F                  {price = 50;stock = 20;};
			class 30rnd_762x39_AK12_Lush_Mag_Tracer_F                  {price = 50;stock = 20;};
			class 75rnd_762x39_AK12_Mag_F                              {price = 50;stock = 20;};
			class 75rnd_762x39_AK12_Lush_Mag_F                         {price = 50;stock = 20;};
			class 75rnd_762x39_AK12_Arid_Mag_F                         {price = 50;stock = 20;};
			class 75rnd_762x39_AK12_Mag_Tracer_F                       {price = 50;stock = 20;};
			class 75rnd_762x39_AK12_Lush_Mag_Tracer_F                  {price = 50;stock = 20;};
			class 75rnd_762x39_AK12_Arid_Mag_Tracer_F                  {price = 50;stock = 20;};
			class 30Rnd_762x39_Mag_F                                   {price = 50;stock = 20;};
			class 30Rnd_762x39_Mag_Green_F                             {price = 50;stock = 20;};
			class 30Rnd_762x39_Mag_Tracer_F                            {price = 50;stock = 20;};
			class 30Rnd_762x39_Mag_Tracer_Green_F                      {price = 50;stock = 20;};
			class 75Rnd_762x39_Mag_F                                   {price = 50;stock = 20;};
			class 75Rnd_762x39_Mag_Tracer_F                            {price = 50;stock = 20;};
			class rhs_10Rnd_762x39mm_tracer                            {price = 50;stock = 20;};
			class rhs_10Rnd_762x39mm_U                                 {price = 50;stock = 20;};
			class rhs_10Rnd_762x39mm                                   {price = 50;stock = 20;};
			class rhs_10Rnd_762x39mm_89                                {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_bakelite_tracer                   {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_bakelite_U                        {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_bakelite                          {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_bakelite_89                       {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_tracer                            {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_U                                 {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm                                   {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_89                                {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_polymer_tracer                    {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_polymer_U                         {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_polymer                           {price = 50;stock = 20;};
			class rhs_30Rnd_762x39mm_polymer_89                        {price = 50;stock = 20;};
			class rhssaf_30Rnd_762x39mm_M67                            {price = 50;stock = 20;};
			class rhssaf_30Rnd_762x39mm_M78_tracer                     {price = 50;stock = 20;};
			class rhssaf_30Rnd_762x39_M82_api                          {price = 50;stock = 20;};
			class rhs_75Rnd_762x39mm_tracer                            {price = 50;stock = 20;};
			class rhs_75Rnd_762x39mm_89                                {price = 50;stock = 20;};
			// 5.45x39 AK
			class 30Rnd_545x39_Mag_F                                   {price = 50;stock = 20;};
			class 30Rnd_545x39_Mag_Green_F                             {price = 50;stock = 20;};
			class 30Rnd_545x39_Mag_Tracer_F                            {price = 50;stock = 20;};
			class 30Rnd_545x39_Mag_Tracer_Green_F                      {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N6_AK                              {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N6M_AK                             {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_AK_green                            {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N6_green_AK                        {price = 50;stock = 20;};                     
			class rhs_30Rnd_545x39_7N6M_green_AK                       {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N10_camo_AK                        {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N22_camo_AK                        {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N10_desert_AK                      {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N22_desert_AK                      {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N10_plum_AK                        {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N22_plum_AK                        {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N6M_plum_AK                        {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_AK_plum_green                       {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N10_2mag_AK                        {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N10_2mag_camo_AK                   {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N10_2mag_desert_AK                 {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N10_2mag_plum_AK                   {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N10_AK                             {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7N22_AK                             {price = 50;stock = 20;};
			class rhs_30Rnd_545x39_7U1_AK                              {price = 50;stock = 20;};
			class rhs_45Rnd_545X39_7N10_AK                             {price = 50;stock = 20;};
			class rhs_45Rnd_545X39_7N22_AK                             {price = 50;stock = 20;};
			class rhs_45Rnd_545X39_7N6M_AK                             {price = 50;stock = 20;};
			class rhs_45Rnd_545X39_7N6_AK                              {price = 50;stock = 20;};
			class rhs_45Rnd_545X39_AK_Green                            {price = 50;stock = 20;};
			class rhs_45Rnd_545X39_7U1_AK                              {price = 50;stock = 20;};
			class rhs_60Rnd_545X39_7N10_AK                             {price = 50;stock = 20;};
			class rhs_60Rnd_545X39_7N22_AK                             {price = 50;stock = 20;};
			class rhs_60Rnd_545X39_AK_Green                            {price = 50;stock = 20;};
 			class rhs_60Rnd_545X39_7U1_AK                              {price = 50;stock = 20;};
			//STANG/PMAG/SCAR
			class 150Rnd_556x45_Drum_Green_Mag_F                       {price = 50;stock = 20;};
			class 150Rnd_556x45_Drum_Green_Mag_Tracer_F                {price = 50;stock = 20;};
			class ACE_30Rnd_556x45_Stanag_Tracer_Dim                   {price = 50;stock = 20;};
			class ACE_30Rnd_556x45_Stanag_M995_AP_mag                  {price = 50;stock = 20;};
			class ACE_30Rnd_556x45_Stanag_Mk318_mag                    {price = 50;stock = 20;};
			class ACE_30Rnd_556x45_Stanag_Mk262_mag                    {price = 50;stock = 20;};
			class 150Rnd_556x45_Drum_Mag_F                             {price = 50;stock = 20;};
			class 150Rnd_556x45_Drum_Mag_Tracer_F                      {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag                                  {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_red                              {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_green                            {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Tracer_Yellow                    {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Tracer_Green                     {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Tracer_Red                       {price = 50;stock = 20;};
			class 150Rnd_556x45_Drum_Sand_Mag_F                        {price = 50;stock = 20;};
			class 150Rnd_556x45_Drum_Sand_Mag_Tracer_F                 {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Sand                             {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Sand_green                       {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Sand_red                         {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Sand_Tracer_Yellow               {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Sand_Tracer_Green                {price = 50;stock = 20;};
			class 30Rnd_556x45_Stanag_Sand_Tracer_Red                  {price = 50;stock = 20;};
			class rhs_mag_100Rnd_556x45_M855_cmag                      {price = 50;stock = 20;};
			class rhs_mag_100Rnd_556x45_M855A1_cmag                    {price = 50;stock = 20;};
			class rhs_mag_100Rnd_556x45_Mk262_cmag                     {price = 50;stock = 20;};
			class rhs_mag_100Rnd_556x45_Mk318_cmag                     {price = 50;stock = 20;};
			class rhs_mag_100Rnd_556x45_M855_cmag_mixed                {price = 50;stock = 20;};
			class rhs_mag_100Rnd_556x45_M855A1_cmag_mixed              {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_M193_2MAG_Stanag                {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_M196_2MAG_Stanag_Tracer_Red     {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_M193_Stanag                     {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_M196_Stanag_Tracer_Red          {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_M200_Stanag                     {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_M855_Stanag                     {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_M855A1_Stanag                   {price = 50;stock = 20;};
			class rhs_mag_20Rnd_556x45_Mk262_Stanag                    {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_EPM_Tracer_Red           {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_EPM_Pull_Tracer_Red      {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_EPM_Pull                 {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_EPM_Ranger_Tracer_Red    {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_EPM_Ranger               {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_EPM                      {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan_Tracer_Red      {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_PMAG_Tracer_Red          {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_PMAG_Tan_Tracer_Red        {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_PMAG_Tracer_Red            {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_PMAG                       {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_PMAG_Tan                   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_PMAG                     {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan                 {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk262_PMAG                      {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk262_PMAG_Tan                  {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_PMAG                      {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_PMAG_Tan                  {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_SCAR_Pull                 {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_SCAR_Ranger               {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_SCAR                      {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M200_Stanag                     {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Red        {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_Stanag_Tracer_Red          {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_Stanag_Pull_Tracer_Red   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_Stanag_Pull_Tracer_Red     {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_Stanag_Pull                {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_Stanag_Pull              {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk262_Stanag_Pull               {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_Stanag_Pull               {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_Stanag_Ranger_Tracer_Red {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_Stanag_Ranger_Tracer_Red   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_Stanag_Ranger              {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_Stanag_Ranger            {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk262_Stanag_Ranger             {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_Stanag_Ranger             {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M193_Stanag                     {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M196_Stanag_Tracer_Red          {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855_Stanag                     {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_M855A1_Stanag                   {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk262_Stanag                    {price = 50;stock = 20;};
			class rhs_mag_30Rnd_556x45_Mk318_Stanag                    {price = 50;stock = 20;};
 			class ACE_10Rnd_762x51_Mag_Tracer_Dim                      {price = 50;stock = 20;};
			class ACE_10Rnd_762x51_Mag_SD                              {price = 50;stock = 20;};
			class ACE_10Rnd_762x51_Mag_Tracer                          {price = 50;stock = 20;};
			class ACE_10Rnd_762x51_M118LR_Mag                          {price = 50;stock = 20;};
			class ACE_10Rnd_762x51_M993_AP_Mag                         {price = 50;stock = 20;};
			class ACE_10Rnd_762x51_Mk316_Mod_0_Mag                     {price = 50;stock = 20;};
			class ACE_10Rnd_762x51_Mk319_Mod_0_Mag                     {price = 50;stock = 20;};
			class ACE_20Rnd_762x51_Mag_Tracer_Dim                      {price = 50;stock = 20;};
			class ACE_20Rnd_762x51_Mag_SD                              {price = 50;stock = 20;};
			class ACE_20Rnd_762x51_Mag_Tracer                          {price = 50;stock = 20;};
			class ACE_20Rnd_762x51_M118LR_Mag                          {price = 50;stock = 20;};
			class ACE_20Rnd_762x51_M993_AP_Mag                         {price = 50;stock = 20;};
			class ACE_20Rnd_762x51_Mk316_Mod_0_Mag                     {price = 50;stock = 20;};
			class ACE_20Rnd_762x51_Mk319_Mod_0_Mag                     {price = 50;stock = 20;};
			class 20Rnd_762x51_Mag                                     {price = 50;stock = 20;};

			// Снайперские винтовки
			class rhsusf_20Rnd_762x51_SR25_m118_special_Mag            {price = 790;stock = 20;};
			class rhsusf_20Rnd_762x51_SR25_m62_Mag                     {price = 790;stock = 20;};
			class rhsusf_20Rnd_762x51_SR25_m993_Mag                    {price = 790;stock = 20;};
			class rhsusf_20Rnd_762x51_SR25_mk316_special_Mag           {price = 790;stock = 20;};
			class 10Rnd_127x54_Mag                                     {price = 790;stock = 20;};
			class ACE_10Rnd_762x67_Berger_Hybrid_OTM_Mag               {price = 790;stock = 20;};
			class ACE_10Rnd_762x67_Mk248_Mod_0_Mag                     {price = 790;stock = 20;};
			class ACE_10Rnd_762x67_Mk248_Mod_1_Mag                     {price = 790;stock = 20;};
			class ACE_10Rnd_338_300gr_HPBT_Mag                         {price = 790;stock = 20;};
			class ACE_10Rnd_338_API526_Mag                             {price = 790;stock = 20;};
			class 10Rnd_338_Mag                                        {price = 790;stock = 20;};
			class rhsusf_5Rnd_762x51_m118_special_Mag                  {price = 790;stock = 20;};
			class rhsusf_5Rnd_762x51_m62_Mag                           {price = 790;stock = 20;};
			class rhsusf_5Rnd_762x51_m993_Mag                          {price = 790;stock = 20;};
			class rhsusf_10Rnd_762x51_m118_special_Mag                 {price = 790;stock = 20;};
			class rhsusf_10Rnd_762x51_m62_Mag                          {price = 790;stock = 20;};
			class rhsusf_10Rnd_762x51_m993_Mag                         {price = 790;stock = 20;};
			class rhsusf_5Rnd_762x51_AICS_m118_special_Mag             {price = 790;stock = 20;};
			class rhsusf_5Rnd_762x51_AICS_m62_Mag                      {price = 790;stock = 20;};
			class rhsusf_5Rnd_762x51_AICS_m993_Mag                     {price = 790;stock = 20;};
			class rhsusf_5Rnd_300winmag_xm2010                         {price = 790;stock = 20;};
			class ACE_5Rnd_127x99_Mag                                  {price = 790;stock = 20;};
			class ACE_5Rnd_127x99_API_Mag                              {price = 790;stock = 20;};
			class ACE_5Rnd_127x99_AMAX_Mag                             {price = 790;stock = 20;};
			class 5Rnd_127x108_Mag                                     {price = 790;stock = 20;};
			class 5Rnd_127x108_APDS_Mag                                {price = 790;stock = 20;};
			class ACE_7Rnd_408_305gr_Mag                               {price = 790;stock = 20;};
			class 7Rnd_408_Mag                                         {price = 790;stock = 20;};
			class ACE_10Rnd_127x99_Mag                                 {price = 790;stock = 20;};
			class ACE_10Rnd_127x99_API_Mag                             {price = 790;stock = 20;};
			class ACE_10Rnd_127x99_AMAX_Mag                            {price = 790;stock = 20;};             
			class rhsusf_mag_10Rnd_STD_50BMG_M33                       {price = 790;stock = 20;};             
			class rhsusf_mag_10Rnd_STD_50BMG_mk211                     {price = 790;stock = 20;};

			// Пусковые установки
			class MRAWS_HE_F                                           {price = 790;stock = 20;};
			class MRAWS_HEAT_F                                         {price = 790;stock = 20;};
			class rhs_mag_maaws_HE                                     {price = 790;stock = 20;};
			class rhs_mag_maaws_HEDP                                   {price = 790;stock = 20;};
			class rhs_mag_maaws_HEAT                                   {price = 790;stock = 20;};
			class MRAWS_HEAT55_F                                       {price = 790;stock = 20;};
			class RPG32_HE_F                                           {price = 790;stock = 20;};
			class RPG32_F                                              {price = 790;stock = 20;};
			class Vorona_HE                                            {price = 790;stock = 20;};
			class Vorona_HEAT                                          {price = 790;stock = 20;};
			class Titan_AA                                             {price = 790;stock = 20;};
			class Titan_AP                                             {price = 790;stock = 20;};
			class Titan_AT                                             {price = 790;stock = 20;};
			class rhs_fgm148_magazine_AT                               {price = 790;stock = 20;};
			class ace_missile_manpad_stinger_man                       {price = 790;stock = 20;};
		};

		class attachments {
			displayName = "Attachments - Silencers/Bipods/Lasers/Other";
			picture = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\handgun_ca.paa";

			//RHS
			class rhsusf_acc_grip1                                    {price = 500;stock = 10;};
			class rhsusf_acc_grip2                                    {price = 500;stock = 10;};
			class rhsusf_acc_grip2_tan                                    {price = 500;stock = 10;};
			class rhsusf_acc_grip2_wd                                    {price = 500;stock = 10;};
			class rhsusf_acc_grip3                                    {price = 500;stock = 10;};
			class rhsusf_acc_grip3_tan                                    {price = 500;stock = 10;};
			class rhsusf_acc_grip4                                    {price = 500;stock = 10;};
			class rhsusf_acc_grip4_bipod                                    {price = 700;stock = 10;};
			class rhs_acc_grip_ffg2                                    {price = 400;stock = 10;};
			class rhs_acc_grip_rk2                                    {price = 400;stock = 10;};
			class rhs_acc_grip_rk6                                    {price = 250;stock = 10;};
			class rhsusf_acc_harris_bipod                                    {price = 600;stock = 10;};
			class rhsusf_acc_harris_swivel                                    {price = 600;stock = 10;};
			class rhsusf_acc_kac_grip                                    {price = 400;stock = 10;};
			class rhsusf_acc_kac_grip_saw_bipod                                    {price = 700;stock = 10;};
			class rhsusf_acc_rvg_blk                                    {price = 250;stock = 10;};
			class rhsusf_acc_rvg_de                                    {price = 250;stock = 10;};
			class rhsusf_acc_saw_bipod                                    {price = 700;stock = 10;};
			class rhsusf_acc_saw_lw_bipod                                    {price = 700;stock = 10;};
			class rhsusf_acc_tacsac_blk                                    {price = 250;stock = 10;};
			class rhsusf_acc_tacsac_blue                                    {price = 250;stock = 10;};
			class rhsusf_acc_tacsac_tan                                    {price = 250;stock = 10;};
			class rhsusf_acc_tdstubby_blk                                    {price = 250;stock = 10;};
			class rhsusf_acc_tdstubby_tan                                    {price = 250;stock = 10;};
			class rhs_acc_2dpZenit                                    {price = 200;stock = 10;};
			class rhs_acc_2dpZenit_ris                                    {price = 300;stock = 10;};
			class rhs_acc_perst1ik                                    {price = 200;stock = 10;};
			class rhs_acc_perst1ik_ris                                    {price = 200;stock = 10;};
			class rhs_acc_perst3                                    {price = 300;stock = 10;};
			class rhs_acc_perst3_2dp_h                                    {price = 500;stock = 10;};
			class rhs_acc_perst3_2dp_light_h                                    {price = 500;stock = 10;};
			class rhsusf_acc_M952V                                    {price = 200;stock = 10;};
			class rhsusf_acc_anpeq15                                    {price = 300;stock = 10;};
			class rhsusf_acc_anpeq15A                                    {price = 300;stock = 10;};
			class rhsusf_acc_anpeq15_light                                    {price = 500;stock = 10;};
			class rhsusf_acc_anpeq15_top                                    {price = 300;stock = 10;};
			class rhsusf_acc_anpeq15_wmx                                    {price = 500;stock = 10;};
			class rhsusf_acc_anpeq15_wmx_light                                    {price = 500;stock = 10;};
			class rhsusf_acc_anpeq15_bk                                    {price = 500;stock = 10;};
			class rhsusf_acc_anpeq15_bk_light                                    {price = 500;stock = 10;};
			class rhsusf_acc_anpeq15_bk_top                                    {price = 200;stock = 10;};
			class rhsusf_acc_anpeq15side                                    {price = 200;stock = 10;};
			class rhsusf_acc_anpeq15side_bk                                    {price = 200;stock = 10;};
			class rhsusf_acc_anpeq16a                                    {price = 500;stock = 10;};
			class rhsusf_acc_anpeq16a_light                                    {price = 500;stock = 10;};
			class rhsusf_acc_anpeq16a_light_top                                    {price = 500;stock = 10;};
			class rhsusf_acc_anpeq16a_top                                    {price = 500;stock = 10;};
			class rhsusf_acc_wmx                                    {price = 200;stock = 10;};
			class rhsusf_acc_wmx_bk                                    {price = 200;stock = 10;};
			class rhs_acc_at4_handler                                    {price = 100;stock = 10;};
			class rhsgref_mg42_acc_AAsight                                    {price = 100;stock = 10;};
			class rhsgref_acc_zendl                                    {price = 100;stock = 10;};
			class rhsgref_K98k_acc_sighthood_add                                    {price = 30;stock = 10;};

			//Muzzle accessories RHS
			class rhs_acc_6p9_suppressor {price = 400;stock = 10;};
			class rhs_acc_uuk {price = 150;stock = 10;};
			class rhs_acc_ak5 {price = 400;stock = 10;};
			class rhs_acc_dtk {price = 150;stock = 10;};
			class rhs_acc_dtk1 {price = 150;stock = 10;};
			class rhs_acc_dtk1l {price = 150;stock = 10;};
			class rhs_acc_dtk2 {price = 150;stock = 10;};
			class rhs_acc_dtk3 {price = 300;stock = 10;};
			class rhs_acc_dtk4long {price = 150;stock = 10;};
			class rhs_acc_dtk4screws {price = 150;stock = 10;};
			class rhs_acc_dtk4short {price = 150;stock = 10;};
			class rhs_acc_dtk1983 {price = 150;stock = 10;};
			class rhs_acc_dtkakm {price = 150;stock = 10;};
			class rhs_acc_pbs1 {price = 600;stock = 10;};
			class rhs_acc_pbs4 {price = 600;stock = 10;};
			class rhs_acc_pgs64 {price = 150;stock = 10;};
			class rhs_acc_pgs64_74u {price = 150;stock = 10;};
			class rhs_acc_pgs64_74un {price = 150;stock = 10;};
			class rhs_acc_tgpa {price = 600;stock = 10;};
			class rhs_acc_tgpv {price = 600;stock = 10;};
			class rhs_acc_tgpv2 {price = 600;stock = 10;};
			class rhsusf_acc_aac_scarh_silencer {price = 600;stock = 10;};
			class rhsusf_acc_M2010S {price = 600;stock = 10;};
			class rhsusf_acc_M2010S_d {price = 600;stock = 10;};
			class rhsusf_acc_M2010S_sa {price = 600;stock = 10;};
			class rhsusf_acc_M2010S_wd {price = 600;stock = 10;};
			class rhsusf_acc_SF3P556 {price = 400;stock = 10;};
			class rhsusf_acc_SFMB556 {price = 400;stock = 10;};
			class rhsusf_acc_SR25S {price = 600;stock = 10;};
			class rhsusf_acc_SR25S_d {price = 600;stock = 10;};
			class rhsusf_acc_SR25S_wd {price = 600;stock = 10;};
			class rhsusf_acc_aac_762sd_silencer {price = 600;stock = 10;};
			class rhsusf_acc_aac_762sdn6_silencer {price = 600;stock = 10;};
			class rhsusf_acc_m24_muzzlehider_black {price = 400;stock = 10;};
			class rhsusf_acc_m24_muzzlehider_d {price = 400;stock = 10;};
			class rhsusf_acc_m24_muzzlehider_wd {price = 400;stock = 10;};
			class rhsusf_acc_m24_silencer_black {price = 600;stock = 10;};
			class rhsusf_acc_m24_silencer_d {price = 600;stock = 10;};
			class rhsusf_acc_m24_silencer_wd {price = 600;stock = 10;};
			class rhsusf_acc_nt4_black {price = 600;stock = 10;};
			class rhsusf_acc_nt4_tan {price = 600;stock = 10;};
			class rhsusf_acc_omega9k {price = 300;stock = 10;};
			class rhsusf_acc_rotex5_grey {price = 300;stock = 10;};
			class rhsusf_acc_rotex5_tan {price = 300;stock = 10;};
			class rhsusf_acc_rotex_mp7_aor1 {price = 300;stock = 10;};
			class rhsusf_acc_rotex_mp7 {price = 300;stock = 10;};
			class rhsusf_acc_rotex_mp7_desert {price = 300;stock = 10;};
			class rhsusf_acc_rotex_mp7_winter {price = 300;stock = 10;};
			class rhsusf_acc_ARDEC_M240 {price = 200;stock = 10;};
			class rhsgref_acc_falMuzzle_l1a1 {price = 100;stock = 10;};
			class rhs_acc_npz {price = 400;stock = 10;};
			class bipod_02_F_arid {price = 600;stock = 5;};
			class bipod_03_F_blk {price = 600;stock = 5;};
			class bipod_02_F_blk {price = 600;stock = 5;};
			class bipod_01_F_blk {price = 600;stock = 5;};
			class bipod_02_F_hex {price = 600;stock = 5;};
			class bipod_01_F_khk {price = 600;stock = 5;};
			class bipod_02_F_lush {price = 600;stock = 5;};
			class bipod_01_F_mtp {price = 600;stock = 5;};
			class bipod_03_F_oli {price = 600;stock = 5;};
			class bipod_01_F_snd {price = 600;stock = 5;};
			class bipod_02_F_tan {price = 600;stock = 5;};
			class acc_flashlight {price = 200;stock = 5;};
			class acc_flashlight_smg_01 {price = 200;stock = 5;};
			class acc_pointer_IR {price = 300;stock = 5;};
			class acc_flashlight_pistol {price = 200;stock = 5;};
			class ACE_acc_pointer_green {price = 400;stock = 5;};
			class muzzle_snds_338_black {price = 900;stock = 2;};
			class muzzle_snds_338_green {price = 900;stock = 2;};
			class muzzle_snds_338_sand {price = 900;stock = 2;};
			class muzzle_snds_93mmg {price = 900;stock = 2;};
			class muzzle_snds_93mmg_tan {price = 900;stock = 2;};
			class muzzle_snds_acp {price = 300;stock = 2;};
			class muzzle_snds_B {price = 600;stock = 2;};
			class muzzle_snds_B_khk_F {price = 600;stock = 2;};
			class muzzle_snds_B_snd_F {price = 600;stock = 2;};
			class muzzle_snds_H {price = 600;stock = 2;};
			class muzzle_snds_H_khk_F {price = 600;stock = 2;};
			class muzzle_snds_H_snd_F {price = 600;stock = 2;};
			class muzzle_snds_H_MG {price = 600;stock = 2;};
			class muzzle_snds_H_SW {price = 600;stock = 2;};
			class muzzle_snds_L {price = 200;stock = 2;};
			class muzzle_snds_M {price = 200;stock = 2;};
			class muzzle_snds_58_blk_F {price = 300;stock = 2;};
			class muzzle_snds_m_khk_F {price = 200;stock = 2;};
			class muzzle_snds_m_snd_F {price = 200;stock = 2;};
			class muzzle_snds_58_wdm_F {price = 600;stock = 2;};
			class muzzle_snds_58_ghex_F {price = 600;stock = 2;};
			class muzzle_snds_58_hex_F {price = 600;stock = 2;};
			class muzzle_snds_65_TI_blk_F {price = 600;stock = 2;};
			class muzzle_snds_65_TI_hex_F {price = 600;stock = 2;};
			class muzzle_snds_65_TI_ghex_F {price = 600;stock = 2;};
			class muzzle_snds_H_MG_blk_F {price = 600;stock = 2;};
			class muzzle_snds_H_MG_khk_F {price = 600;stock = 2;};
			//Contact
			class muzzle_snds_B_arid_F {price = 600;stock = 2;};
			class muzzle_snds_B_lush_F {price = 600;stock = 2;};
 		};

		class AttachmentsOptics {
			displayName = "Оптические прицелы";
			picture = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\handgun_ca.paa";

			//Vanilla
			class optic_ACO_grn {price = 200;stock = 2;};
            class optic_Aco {price = 200;stock = 2;};
			class optic_aco_grn_smg {price = 150;stock = 2;};
			class optic_aco_smg {price = 150;stock = 2;};
            class optic_Holosight {price = 250;stock = 2;};
            class optic_Holosight_blk_F {price = 250;stock = 2;};
            class optic_Holosight_khk_F {price = 250;stock = 2;};
            class optic_Holosight_smg {price = 250;stock = 2;};
            class optic_MRD {price = 100;stock = 2;};
            class optic_Yorris {price = 100;stock = 2;};
            class optic_AMS {price = 700;stock = 2;};
            class optic_AMS_khk {price = 700;stock = 2;};
            class optic_AMS_snd {price = 700;stock = 2;};
            class optic_Arco_blk_F {price = 350;stock = 2;};
            class optic_Arco_ghex_F {price = 350;stock = 2;};
            class optic_DMS {price = 450;stock = 2;};
            class optic_DMS_ghex_F {price = 450;stock = 2;};
            class optic_ERCO_blk_F {price = 400;stock = 2;};
            class optic_ERCO_khk_F {price = 400;stock = 2;};
            class optic_ERCO_snd_F {price = 400;stock = 2;};
            class optic_KHS_blk {price = 650;stock = 2;};
            class optic_KHS_hex {price = 650;stock = 2;};
            class optic_KHS_old {price = 650;stock = 2;};
            class optic_KHS_tan {price = 650;stock = 2;};
            class optic_LRPS {price = 900;stock = 2;};
            class optic_LRPS_ghex_F {price = 900;stock = 2;};
            class optic_LRPS_tna_F {price = 900;stock = 2;};
            class optic_SOS {price = 400;stock = 2;};
            class optic_SOS_khk_F {price = 400;stock = 2;};
            class optic_MRCO {price = 350;stock = 2;};
            class optic_Nightstalker {price = 2300;stock = 2;};
            class optic_NVS {price = 1350;stock = 2;};
            class optic_Hamr {price = 350;stock = 2;};
            class optic_Hamr_khk_F {price = 350;stock = 2;};
            class optic_tws {price = 1350;stock = 2;};
            class optic_tws_mg {price = 1350;stock = 2;};
            //Contact
            class optic_Holosight_arid_F {price = 250;stock = 2;};
            class optic_Holosight_lush_F {price = 250;stock = 2;};
            class optic_Arco_AK_arid_F {price = 350;stock = 2;};
            class optic_Arco_AK_blk_F {price = 350;stock = 2;};
            class optic_Arco_AK_lush_F {price = 350;stock = 2;};
            class optic_Arco_arid_F {price = 350;stock = 2;};
            class optic_Arco_lush_F {price = 350;stock = 2;};
            class optic_DMS_weathered_F {price = 450;stock = 2;};
            class optic_DMS_weathered_Kir_F {price = 450;stock = 2;};
            class optic_MRD_black {price = 100;stock = 2;};
            class optic_ico_01_black_f {price = 350;stock = 2;};
            class optic_ico_01_camo_f {price = 350;stock = 2;};
            class optic_ico_01_f {price = 350;stock = 2;};
            class optic_ico_01_sand_f {price = 350;stock = 2;};
			//RHS Optics
			class rhs_acc_1p29 {price = 400;stock = 10;};
			class rhs_acc_1p63 {price = 300;stock = 10;};
			class rhs_acc_1p78 {price = 350;stock = 10;};
			class rhs_acc_1p87 {price = 300;stock = 10;};
			class rhs_acc_1pn93_1 {price = 500;stock = 10;};
			class rhs_acc_1pn93_2 {price = 700;stock = 10;};
			class rhs_acc_ekp1 {price = 250;stock = 10;};
			class rhs_acc_ekp8_02 {price = 250;stock = 10;};
			class rhs_acc_ekp8_18 {price = 250;stock = 10;};
			class rhs_acc_nita {price = 250;stock = 10;};
			class rhs_acc_okp7_dovetail {price = 250;stock = 10;};
			class rhs_acc_okp7_picatinny {price = 250;stock = 10;};
			class rhs_acc_pkas {price = 300;stock = 10;};
			class rhsusf_acc_EOTECH {price = 250;stock = 10;};
			class rhsusf_acc_M2A1 {price = 250;stock = 10;};
			class rhs_acc_rakursPM {price = 250;stock = 10;};
			class rhsusf_acc_RM05 {price = 200;stock = 10;};
			class rhsusf_acc_RM05_fwd {price = 200;stock = 10;};
			class rhsusf_acc_RX01_NoFilter {price = 200;stock = 10;};
			class rhsusf_acc_RX01 {price = 200;stock = 10;};
			class rhsusf_acc_RX01_NoFilter_tan {price = 200;stock = 10;};
			class rhsusf_acc_RX01_tan {price = 200;stock = 10;};
			class rhsusf_acc_T1_high {price = 250;stock = 10;};
			class rhsusf_acc_T1_low {price = 250;stock = 10;};
			class rhsusf_acc_T1_low_fwd {price = 250;stock = 10;};
			class rhsusf_acc_compm4 {price = 250;stock = 10;};
			class rhsusf_acc_eotech_552 {price = 250;stock = 10;};
			class rhsusf_acc_eotech_552_d {price = 250;stock = 10;};
			class rhsusf_acc_eotech_552_wd {price = 250;stock = 10;};
			class rhsusf_acc_g33_t1 {price = 450;stock = 10;};
			class rhsusf_acc_g33_xps3 {price = 450;stock = 10;};
			class rhsusf_acc_g33_xps3_tan {price = 450;stock = 10;};
			class rhsusf_acc_eotech_xps3 {price = 450;stock = 10;};
			class rhsusf_acc_mrds {price = 100;stock = 10;};
			class rhsusf_acc_mrds_fwd {price = 100;stock = 10;};
			class rhsusf_acc_mrds_c {price = 100;stock = 10;};
			class rhsusf_acc_mrds_fwd_c {price = 100;stock = 10;};
			class rhsgref_acc_l1a1_l2a2 {price = 400;stock = 10;};
			class rhs_acc_pgo7v {price = 200;stock = 10;};
			class rhs_acc_pgo7v2 {price = 350;stock = 10;};
			class rhs_acc_pgo7v3 {price = 450;stock = 10;};
			class rhs_acc_pso1m2 {price = 350;stock = 10;};
			class rhs_acc_pso1m21 {price = 350;stock = 10;};
			class rhs_weap_optic_smaw {price = 350;stock = 10;};
			class rhsusf_acc_ACOG {price = 400;stock = 10;};
			class rhsusf_acc_ACOG2 {price = 400;stock = 10;};
			class rhsusf_acc_ACOG2_USMC {price = 400;stock = 10;};
			class rhsusf_acc_ACOG3 {price = 400;stock = 10;};
			class rhsusf_acc_ACOG3_USMC {price = 400;stock = 10;};
			class rhsusf_acc_ACOG_MDO {price = 550;stock = 10;};
			class rhsusf_acc_ACOG_RMR {price = 500;stock = 10;};
			class rhsusf_acc_ACOG_USMC {price = 400;stock = 10;};
			class rhsusf_acc_ACOG_d {price = 400;stock = 10;};
			class rhsusf_acc_ACOG_wd {price = 400;stock = 10;};
			class rhsusf_acc_ELCAN {price = 400;stock = 10;};
			class rhsusf_acc_ELCAN_ard {price = 400;stock = 10;};
			class rhsusf_acc_LEUPOLDMK4 {price = 600;stock = 10;};
			class rhsusf_acc_LEUPOLDMK4_2 {price = 600;stock = 10;};
			class rhsusf_acc_LEUPOLDMK4_2_MRDS {price = 700;stock = 10;};
			class rhsusf_acc_LEUPOLDMK4_2_d {price = 600;stock = 10;};
			class rhsusf_acc_LEUPOLDMK4_d {price = 600;stock = 10;};
			class rhsusf_acc_LEUPOLDMK4_wd {price = 600;stock = 10;};
			class rhsusf_acc_M8541 {price = 700;stock = 10;};
			class rhsusf_acc_M8541_low {price = 700;stock = 10;};
			class rhsusf_acc_M8541_low_d {price = 700;stock = 10;};
			class rhsusf_acc_M8541_low_wd {price = 700;stock = 10;};
			class rhsusf_acc_M8541_mrds {price = 800;stock = 10;};
			class rhsusf_acc_anpas13gv1 {price = 1750;stock = 10;};
			class rhsusf_acc_anpvs27 {price = 990;stock = 10;};
			class rhsgref_acc_l1a1_anpvs2 {price = 1200;stock = 10;};
			class rhsusf_acc_premier {price = 700;stock = 10;};
			class rhsusf_acc_premier_low {price = 700;stock = 10;};
			class rhsusf_acc_premier_mrds {price = 800;stock = 10;};
			class rhsusf_acc_premier_anpvs27 {price = 1800;stock = 10;};
			class rhs_optic_maaws {price = 350;stock = 10;};
			class rhsusf_acc_SpecterDR {price = 100;stock = 10;};
			class rhsusf_acc_SpecterDR_OD {price = 100;stock = 10;};
			class rhsusf_acc_SpecterDR_D {price = 100;stock = 10;};
			class rhsusf_acc_SpecterDR_A {price = 100;stock = 10;};
			class rhsusf_acc_su230_c {price = 350;stock = 10;};
			class rhsusf_acc_su230 {price = 350;stock = 10;};
			class rhsusf_acc_su230_mrds {price = 400;stock = 10;};
			class rhsusf_acc_su230_mrds_c {price = 400;stock = 10;};
			class rhsusf_acc_su230a {price = 500;stock = 10;};
			class rhsusf_acc_su230a_c {price = 500;stock = 10;};
			class rhsusf_acc_su230a_mrds {price = 500;stock = 10;};
			class rhsusf_acc_su230a_mrds_c {price = 500;stock = 10;};
			class rhs_acc_dh520x56 {price = 900;stock = 10;};
			class rhsusf_acc_nxs_3515x50_md {price = 900;stock = 10;};
			class rhsusf_acc_nxs_3515x50f1_h58 {price = 1000;stock = 10;};
			class rhsusf_acc_nxs_5522x56_md {price = 1000;stock = 10;};
		}

		class Bags {
			displayName = "Рюкзаки";
			picture = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\handgun_ca.paa";

			class B_AssaultPack_blk {price = 100;stock = 2;};
			class B_AssaultPack_dgtl {price = 100;stock = 2;};
			class B_AssaultPack_khk {price = 100;stock = 2;};
			class B_AssaultPack_cbr {price = 100;stock = 2;};
			class B_AssaultPack_rgr {price = 100;stock = 2;};
			class B_AssaultPack_ocamo {price = 100;stock = 2;};
			class B_AssaultPack_mcamo {price = 100;stock = 2;};
			class B_AssaultPack_tna_F {price = 100;stock = 2;};
			class B_AssaultPack_sgg {price = 100;stock = 2;};
			class B_Carryall_cbr {price = 600;stock = 2;};
			class B_Carryall_khk {price = 600;stock = 2;};
			class B_Carryall_oli {price = 600;stock = 2;};
			class B_Carryall_mcamo {price = 600;stock = 2;};
			class B_Carryall_ghex_F {price = 600;stock = 2;};
		    class B_Carryall_oucamo {price = 600;stock = 2;};
            class B_FieldPack_blk {price = 300;stock = 2;};
			class B_FieldPack_cbr {price = 300;stock = 2;};
			class B_FieldPack_oli {price = 300;stock = 2;};
			class B_FieldPack_ghex_F {price = 300;stock = 2;};
			class B_FieldPack_oucamo {price = 300;stock = 2;};
			class B_FieldPack_ocamo {price = 300;stock = 2;};
            class B_FieldPack_khk {price = 300;stock = 2;};
            class B_Kitbag_cbr {price = 400;stock = 2;};
			class B_Kitbag_rgr {price = 400;stock = 2;};
			class B_Kitbag_sgg {price = 400;stock = 2;};
			class B_Kitbag_mcamo {price = 400;stock = 2;};
			class B_Parachute {price = 700;stock = 2;};
			class B_TacticalPack_blk {price = 250;stock = 2;};
			class B_TacticalPack_rgr {price = 250;stock = 2;};
		    class B_TacticalPack_ocamo {price = 250;stock = 2;};
		    class B_TacticalPack_mcamo {price = 250;stock = 2;};
		    class B_TacticalPack_oli {price = 250;stock = 2;};
			class B_Bergen_dgtl_F {price = 1000;stock = 2;};
            class B_Bergen_hex_F {price = 1000;stock = 2;};
            class B_Bergen_mcamo_F {price = 1000;stock = 2;};
			class B_Bergen_tna_F {price = 1000;stock = 2;};
			class B_ViperHarness_blk_F {price = 400;stock = 2;};
		    class B_ViperHarness_ghex_F {price = 400;stock = 2;};
		    class B_ViperHarness_hex_F {price = 400;stock = 2;};
		    class B_ViperHarness_khk_F {price = 400;stock = 2;};
			class B_ViperHarness_oli_F {price = 400;stock = 2;};
			class B_ViperLightHarness_blk_F {price = 300;stock = 2;};
		    class B_ViperLightHarness_ghex_F {price = 300;stock = 2;};
		    class B_ViperLightHarness_hex_F {price = 300;stock = 2;};
			class B_ViperLightHarness_khk_F {price = 300;stock = 2;};
			class B_ViperLightHarness_oli_F {price = 300;stock = 2;};

			//Contact
			class B_AssaultPack_eaf_F {price = 100;stock = 2;};
            class B_AssaultPack_wdl_F {price = 100;stock = 2;};
            class B_Carryall_eaf_F {price = 600;stock = 2;};
            class B_Carryall_green_F {price = 600;stock = 2;};
            class B_Carryall_taiga_F {price = 600;stock = 2;};
            class B_Carryall_wdl_F {price = 600;stock = 2;};
            class B_FieldPack_green_F {price = 300;stock = 2;};
            class B_FieldPack_taiga_F {price = 300;stock = 2;};

			//ravage
			class rvg_assault {price = 100;stock = 2;};
			class rvg_carryall_1 {price = 600;stock = 2;};
			class rvg_carryall_2 {price = 600;stock = 2;};
			class rvg_field {price = 300;stock = 2;};
			class rvg_kitbag {price = 400;stock = 2;};
			class rvg_tactical {price = 250;stock = 2;};
			class rvg_bergan {price = 1000;stock = 2;};
			class rvg_legstrappack_1 {price = 100;stock = 2;};
			class rvg_legstrappack_2 {price = 100;stock = 2;};
			class rvg_legstrappack_3 {price = 100;stock = 2;};
			class rvg_legstrappack_4 {price = 100;stock = 2;};
			class rvg_messengerbag_1 {price = 200;stock = 2;};
			class rvg_messengerbag_2 {price = 200;stock = 2;};
			class rvg_messengerbag_3 {price = 200;stock = 2;};
			class rvg_messengerbag_4 {price = 200;stock = 2;};

			//RHS backpacks
			class rhsusf_assault_eagleaiii_coy {price = 100;stock = 10;};
			class B_rhsusf_B_BACKPACK {price = 100;stock = 10;};
			class rhsusf_assault_eagleaiii_ocp {price = 100;stock = 10;};
			class rhsusf_assault_eagleaiii_ucp {price = 100;stock = 10;};
			class rhsusf_falconii_coy {price = 100;stock = 10;};
			class rhsusf_falconii_mc {price = 100;stock = 10;};
			class rhsusf_falconii {price = 100;stock = 10;};
			class rhs_rpg_empty {price = 100;stock = 10;};
			class rhs_sidor {price = 70;stock = 10;};
			class rhs_assault_umbts {price = 100;stock = 10;};
			class rhs_assault_umbts_engineer_empty {price = 100;stock = 10;};
			class rhs_rd54 {price = 200;stock = 10;};
			class rhs_rd54_emr1 {price = 200;stock = 10;};
			class rhs_rd54_flora2 {price = 200;stock = 10;};
			class rhs_rd54_flora1 {price = 200;stock = 10;};
			class rhs_tortila_black {price = 600;stock = 10;};
			class rhs_tortila_emr {price = 600;stock = 10;};
			class rhs_tortila_grey {price = 600;stock = 10;};
			class rhsgref_ttsko_alicepack {price = 500;stock = 25;};
			class rhsgref_hidf_alicepack {price = 500;stock = 25;};
			class rhsgref_wdl_alicepack {price = 500;stock = 25;};
			class rhsgref_tortila_specter {price = 600;stock = 25;};

			//EO bergen
			class eo_hunter_bergan {price = 1000;stock = 2;};
		};

		class Clothing {
			displayName = "Одежда";
			picture = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\secondaryWeapon_ca.paa";

			//RHS headgear
			class rhsgref_hat_m1941cap {price = 10;stock = 10;};
			class rhs_beanie_green {price = 10;stock = 10;};
			class rhs_beanie {price = 10;stock = 10;};
			class rhs_beret_mp1 {price = 10;stock = 10;};
			class rhs_beret_mp2 {price = 10;stock = 10;};
			class rhs_beret_vdv2 {price = 10;stock = 10;};
			class rhs_beret_vdv3 {price = 10;stock = 10;};
			class rhs_beret_vdv1 {price = 10;stock = 10;};
			class rhs_beret_milp {price = 10;stock = 10;};
			class rhs_Booniehat_digi {price = 10;stock = 10;};
			class rhs_Booniehat_flora {price = 10;stock = 10;};
			class rhs_Booniehat_m81 {price = 10;stock = 10;};
			class rhs_booniehat2_marpatd {price = 10;stock = 10;};
			class rhs_booniehat2_marpatwd {price = 10;stock = 10;};
			class rhs_Booniehat_ocp {price = 10;stock = 10;};
			class rhs_Booniehat_ucp {price = 10;stock = 10;};
			class rhs_ushanka {price = 25;stock = 10;};
			class rhs_pilotka {price = 10;stock = 10;};
			class rhs_fieldcap {price = 10;stock = 10;};
			class rhs_fieldcap_helm_digi {price = 10;stock = 10;};
			class rhs_fieldcap_helm_ml {price = 10;stock = 10;};
			class rhs_fieldcap_helm {price = 10;stock = 10;};
			class rhs_fieldcap_digi {price = 10;stock = 10;};
			class rhs_fieldcap_digi2 {price = 10;stock = 10;};
			class rhs_fieldcap_ml {price = 10;stock = 10;};
			class rhs_fieldcap_khk {price = 10;stock = 10;};
			class rhs_fieldcap_vsr {price = 10;stock = 10;};
			class rhsusf_patrolcap_ocp {price = 10;stock = 10;};
			class rhsusf_patrolcap_ucp {price = 10;stock = 10;};
			class rhsgref_hat_m43cap_heer1_tilted {price = 10;stock = 10;};
			class rhsgref_hat_m43cap_heer {price = 10;stock = 10;};
			class rhs_8point_marpatd {price = 20;stock = 10;};
			class rhs_8point_marpatwd {price = 20;stock = 10;};
			//EO headgear
			class H_Watchcap_blk_hsless {price = 10;stock = 10;};
			class H_Watchcap_blu_hsless {price = 10;stock = 10;};
			class H_Watchcap_black_hsless {price = 10;stock = 10;};
			class H_Watchcap_brown_hsless {price = 10;stock = 10;};
			class H_Watchcap_green_hsless {price = 10;stock = 10;};
			class H_Watchcap_red_hsless {price = 10;stock = 10;};
			class H_Watchcap_blueblack_hsless {price = 10;stock = 10;};
			class H_Watchcap_blackred_hsless {price = 10;stock = 10;};
			class H_Watchcap_grey_hsless {price = 10;stock = 10;};
			class H_Watchcap_greyblack_hsless {price = 10;stock = 10;};
			class H_Watchcap_greyblue_hsless {price = 10;stock = 10;};
			class H_Watchcap_greyred_hsless {price = 10;stock = 10;};
			class H_Watchcap_blue2_hsless {price = 10;stock = 10;};
			class H_Watchcap_yellow_hsless {price = 10;stock = 10;};
			class H_Watchcap_drkgrey_hsless {price = 10;stock = 10;};
			class H_Watchcap_blackyellow_hsless {price = 10;stock = 10;};
			class H_Watchcap_wdlkhk_hsless {price = 10;stock = 10;};
			class H_Watchcap_wdl_hsless {price = 10;stock = 10;};
			class H_Watchcap_aaf_hsless {price = 10;stock = 10;};
			class H_Watchcap_ldf_hsless {price = 10;stock = 10;};
			class H_Watchcap_hunter_hsless {price = 10;stock = 10;};
			class H_Booniehat_aaf {price = 10;stock = 10;};
			class H_Booniehat_black {price = 10;stock = 10;};
			class H_Booniehat_blue {price = 10;stock = 10;};
			class H_Booniehat_green {price = 10;stock = 10;};
			class H_Booniehat_grey {price = 10;stock = 10;};
			class H_Booniehat_woodland {price = 10;stock = 10;};
			class H_Booniehat_hunter {price = 10;stock = 10;};
			class H_Booniehat_urban {price = 10;stock = 10;};
			class H_Booniehat_ldf {price = 10;stock = 10;};

			//EO Gorkas
			class eou_gorka_1 {price = 1300;stock = 10;};
			class eou_gorka_2 {price = 1300;stock = 10;};
			class eou_gorka_3 {price = 1300;stock = 10;};
			class eou_gorka_4 {price = 1300;stock = 10;};
			class eou_gorka_5 {price = 1300;stock = 10;};
			class eou_gorka_6 {price = 1300;stock = 10;};
			class eou_gorka_7 {price = 1300;stock = 10;};
			class eou_gorka_8 {price = 1300;stock = 10;};
			class eou_gorka_9 {price = 1300;stock = 10;};
			class eou_gorka_10 {price = 1300;stock = 10;};
			class eou_gorka_11 {price = 1300;stock = 10;};
			class eou_gorka_12 {price = 1300;stock = 10;};
			class eou_gorka_13 {price = 1300;stock = 10;};
			class eou_gorka_14 {price = 1300;stock = 10;};
			class eou_gorka_15 {price = 1300;stock = 10;};
			class eou_gorka_16 {price = 1300;stock = 10;};
			class eou_gorka_17 {price = 1300;stock = 10;};
			class eou_gorka_18 {price = 1300;stock = 10;};
			class eou_gorka_19 {price = 1300;stock = 10;};
			class eou_gorka_20 {price = 1300;stock = 10;};
			class eou_gorka_21 {price = 1300;stock = 10;};
			class eou_gorka_22 {price = 1300;stock = 10;};
			class eou_gorka_23 {price = 1300;stock = 10;};
			class eou_gorka_24 {price = 1300;stock = 10;};
			class eou_gorka_25 {price = 1300;stock = 10;};
			class eou_gorka_26 {price = 1300;stock = 10;};
			class eou_gorka_27 {price = 1300;stock = 10;};
			class eou_gorka_28 {price = 1300;stock = 10;};
			class eou_gorka_29 {price = 1300;stock = 10;};
			class eou_gorka_30 {price = 1300;stock = 10;};
			class eou_gorka_31 {price = 1300;stock = 10;};
			class eou_gorka_32 {price = 1300;stock = 10;};
			class eou_gorka_33 {price = 1300;stock = 10;};
			class eou_gorka_34 {price = 1300;stock = 10;};
			class eou_gorka_35 {price = 1300;stock = 10;};
			class eou_gorka_36 {price = 1300;stock = 10;};
			class eou_gorka_37 {price = 1300;stock = 10;};
			class eou_gorka_38 {price = 1300;stock = 10;};
			class eou_gorka_39 {price = 1300;stock = 10;};


			//RHS clothing
			class rhs_uniform_cu_ocp {price = 100;stock = 10;};
			class rhs_uniform_cu_ocp_101st {price = 100;stock = 10;};
			class rhs_uniform_cu_ocp_10th {price = 100;stock = 10;};
			class rhs_uniform_cu_ocp_1stcav {price = 100;stock = 10;};
			class rhs_uniform_cu_ocp_82nd {price = 100;stock = 10;};
			class rhs_uniform_cu_ucp {price = 100;stock = 10;};
			class rhs_uniform_cu_ucp_101st {price = 100;stock = 10;};
			class rhs_uniform_cu_ucp_10th {price = 100;stock = 10;};
			class rhs_uniform_cu_ucp_1stcav {price = 100;stock = 10;};
			class rhs_uniform_cu_ucp_82nd {price = 100;stock = 10;};
			class rhs_uniform_df15 {price = 100;stock = 10;};
			class rhs_uniform_df15_tan {price = 100;stock = 10;};
			class rhs_uniform_emr_des_patchless {price = 100;stock = 10;};
			class rhs_uniform_vdv_emr_des {price = 100;stock = 10;};
			class rhs_uniform_emr_patchless {price = 100;stock = 10;};
			class rhs_uniform_msv_emr {price = 100;stock = 10;};
			class rhs_uniform_vdv_emr {price = 100;stock = 10;};
			class rhs_uniform_flora_patchless {price = 100;stock = 10;};
			class rhs_uniform_flora_patchless_alt {price = 100;stock = 10;};
			class rhs_uniform_flora {price = 100;stock = 10;};
			class rhs_uniform_vdv_flora {price = 100;stock = 10;};
			class rhs_uniform_vmf_flora {price = 100;stock = 10;};
			class rhs_uniform_FROG01_d {price = 100;stock = 10;};
			class rhs_uniform_FROG01_wd {price = 100;stock = 10;};
			class rhs_uniform_FROG01_m81 {price = 100;stock = 10;};
			class rhs_uniform_g3_blk {price = 100;stock = 10;};
			class rhs_uniform_g3_m81 {price = 100;stock = 10;};
			class rhs_uniform_g3_mc {price = 100;stock = 10;};
			class rhs_uniform_g3_rgr {price = 100;stock = 10;};
			class rhs_uniform_g3_tan {price = 100;stock = 10;};
			class rhs_uniform_gorka_r_g {price = 100;stock = 10;};
			class rhs_uniform_gorka_r_y {price = 100;stock = 10;};
			class rhs_uniform_mvd_izlom {price = 100;stock = 10;};
			class rhs_uniform_m88_patchless {price = 100;stock = 10;};
			class rhs_uniform_mflora_patchless {price = 100;stock = 10;};
			class rhs_uniform_vdv_mflora {price = 100;stock = 10;};
			class rhs_uniform_acu_ucp {price = 100;stock = 10;};
			class rhs_uniform_abu {price = 100;stock = 10;};
			class rhs_chdkz_uniform_1 {price = 100;stock = 10;};
			class rhs_chdkz_uniform_2 {price = 100;stock = 10;};
			class rhs_chdkz_uniform_3 {price = 100;stock = 10;};
			class rhs_chdkz_uniform_4 {price = 100;stock = 10;};
			class rhs_chdkz_uniform_5 {price = 100;stock = 10;};
			class rhsgref_uniform_gorka_1_f {price = 100;stock = 10;};
			class rhsgref_uniform_TLA_1 {price = 100;stock = 10;};
			class rhsgref_uniform_TLA_2 {price = 100;stock = 10;};
			class rhsgref_uniform_para_ttsko_mountain {price = 100;stock = 10;};
			class rhsgref_uniform_para_ttsko_oxblood {price = 100;stock = 10;};
			class rhsgref_uniform_para_ttsko_urban {price = 100;stock = 10;};
			class rhsgref_uniform_vsr {price = 100;stock = 10;};
			class rhsgref_uniform_ttsko_forest {price = 100;stock = 10;};
			class rhsgref_uniform_ttsko_mountain {price = 100;stock = 10;};
			class rhsgref_uniform_ttsko_urban {price = 100;stock = 10;};
			class rhsgref_uniform_3color_desert {price = 100;stock = 10;};
			class rhsgref_uniform_alpenflage {price = 100;stock = 10;};
			class rhsgref_uniform_altis_lizard {price = 100;stock = 10;};
			class rhsgref_uniform_altis_lizard_olive {price = 100;stock = 10;};
			class rhsgref_uniform_dpm {price = 100;stock = 10;};
			class rhsgref_uniform_dpm_olive {price = 100;stock = 10;};
			class rhsgref_uniform_ERDL {price = 100;stock = 10;};
			class rhsgref_uniform_flecktarn {price = 100;stock = 10;};
			class rhsgref_uniform_flecktarn_full {price = 100;stock = 10;};
			class rhsgref_uniform_og107 {price = 100;stock = 10;};
			class rhsgref_uniform_og107_erdl {price = 100;stock = 10;};
			class rhsgref_uniform_olive {price = 100;stock = 10;};
			class rhsgref_uniform_tigerstripe {price = 100;stock = 10;};
			class rhsgref_uniform_reed {price = 100;stock = 10;};
			class rhsgref_uniform_woodland {price = 100;stock = 10;};
			class rhsgref_uniform_woodland_olive {price = 100;stock = 10;};
			class rhsgref_uniform_specter {price = 100;stock = 10;};
			class U_I_FullGhillie_lsh {price = 4000;stock = 10;};
			class U_O_FullGhillie_lsh {price = 4500;stock = 10;};
			class U_B_FullGhillie_lsh {price = 4000;stock = 10;};
			class U_I_FullGhillie_sard {price = 4000;stock = 10;};
			class U_O_FullGhillie_sard {price = 4500;stock = 10;};
			class U_B_FullGhillie_sard {price = 4000;stock = 10;};
			class U_O_T_FullGhillie_tna_F {price = 4500;stock = 10;};
			class U_B_T_FullGhillie_tna_F {price = 4000;stock = 10;};
			class U_I_E_Uniform_01_sweater_F {price = 80;stock = 10;};
			class U_I_E_Uniform_01_F {price = 80;stock = 10;};
			class U_B_CombatUniform_mcam_wdl_f {price = 80;stock = 10;};
			class rvg_shirt_check {price = 25;stock = 2;};
			class rvg_shirt_stripe {price = 25;stock = 2;};
			class rvg_shirt_bandit {price = 25;stock = 2;};
			class rvg_shirt_kabeiroi {price = 25;stock = 2;};
			class rvg_retro_red {price = 25;stock = 2;};
			class rvg_retro_grey {price = 25;stock = 2;};
			class rvg_retro_green {price = 25;stock = 2;};
			class rvg_retro_bandit {price = 25;stock = 2;};
			class rvg_retro_kabeiroi {price = 25;stock = 2;};
			class rvg_paramilitary_1 {price = 25;stock = 2;};
			class rvg_bandit_1 {price = 80;stock = 2;};
			class rvg_camo_1 {price = 80;stock = 2;};
			class rvg_diamond_1 {price = 80;stock = 2;};
			class rvg_survivor_1 {price = 80;stock = 2;};
			class rvg_independant_1 {price = 80;stock = 2;};
			class rvg_bandit {price = 80;stock = 2;};
			class rvg_camo {price = 80;stock = 2;};
			class rvg_diamond {price = 80;stock = 2;};
			class rvg_survivor {price = 80;stock = 2;};
			class rvg_independant {price = 80;stock = 2;};
			//headgear
			class rvg_bandage_1 {price = 10;stock = 2;};
			class rvg_bandage_2 {price = 10;stock = 2;};
			class rvg_bandage_3 {price = 10;stock = 2;};
			class rvg_safari_1 {price = 10;stock = 2;};
			class rvg_safari_2 {price = 10;stock = 2;};
			class rvg_safari_3 {price = 10;stock = 2;};
			class rvg_hat_brown {price = 10;stock = 2;};
			class rvg_hat_grey {price = 10;stock = 2;};
			class rvg_hat_tan {price = 10;stock = 2;};
			class U_O_R_Gorka_01_camo_F {price = 1300;stock = 2;};
			class U_O_R_Gorka_01_F {price=1300;stock=2;};
			class U_O_R_Gorka_01_brown_F {price=1300;stock=2;};
			class U_O_R_Gorka_01_black_F {price=1300;stock=2;};
			class H_Booniehat_khk_hs {price = 10;stock = 10;};
			class H_Booniehat_mcamo {price = 10;stock = 10;};
		    class H_Booniehat_oli {price = 10;stock = 10;};
		    class H_Booniehat_tan {price = 10;stock = 10;};
		    class H_Cap_blk {price = 10;stock = 10;};
			class H_Cap_blk_CMMG {price = 10;stock = 10;};
		    class H_Cap_grn {price = 10;stock = 10;};
		    class H_Cap_blk_ION {price = 10;stock = 10;};
			class H_Cap_oli {price = 10;stock = 10;};
			class H_Cap_oli_hs {price = 10;stock = 10;};
		    class H_Cap_police {price = 10;stock = 10;};
		    class H_Cap_tan {price = 10;stock = 10;};
		    class H_Cap_khaki_specops_UK {price = 10;stock = 10;};
			class H_Cap_usblack {price = 10;stock = 10;};
		    class H_Cap_tan_specops_US {price = 10;stock = 10;};
		    class H_Cap_blk_Raven {price = 10;stock = 10;};
			class H_Cap_brn_SPECOPS {price = 10;stock = 10;};
			class H_Hat_camo {price = 10;stock = 10;};
			class H_MilCap_blue {price = 10;stock = 10;};
			class H_MilCap_gry {price = 10;stock = 10;};
			class H_MilCap_ocamo {price = 10;stock = 10;};
			class H_MilCap_mcamo {price = 10;stock = 10;};
		    class H_MilCap_dgtl {price = 10;stock = 10;};
		    class H_Cap_headphones {price = 10;stock = 10;};
		    class H_Shemag_olive {price = 10;stock = 10;};
		    class H_Shemag_olive_hs {price = 10;stock = 10;};
			class H_ShemagOpen_tan {price = 10;stock = 10;};
		    class H_ShemagOpen_khk {price = 10;stock = 10;};
            class H_Bandanna_gry {price = 10;stock = 10;};
			class H_Bandanna_blu {price = 10;stock = 10;};
			class H_Bandanna_cbr {price = 10;stock = 10;};
			class H_Bandanna_khk_hs {price = 10;stock = 10;};
			class H_Bandanna_khk {price = 10;stock = 10;};
		    class H_Bandanna_mcamo {price = 10;stock = 10;};
		    class H_Bandanna_sgg {price = 10;stock = 10;};
		    class H_Bandanna_sand {price = 10;stock = 10;};
		    class H_Bandanna_camo {price = 10;stock = 10;};
            class H_Booniehat_tna_F {price = 10;stock = 10;};
		    class H_MilCap_gen_F {price = 10;stock = 10;};
		    class H_MilCap_ghex_F {price = 10;stock = 10;};
		    class H_MilCap_tna_F {price = 10;stock = 10;};
			//Contact
            class H_Booniehat_eaf {price = 10;stock = 10;};
            class H_Booniehat_mgrn {price = 10;stock = 10;};
            class H_Booniehat_taiga {price = 10;stock = 10;};
            class H_Booniehat_wdl {price = 10;stock = 10;};
            class H_Hat_Tinfoil_F {price = 5;stock = 5;};
            class H_MilCap_eaf {price = 10;stock = 10;};
            class H_MilCap_grn {price = 10;stock = 10;};
            class H_MilCap_taiga {price = 10;stock = 10;};
            class H_MilCap_wdl {price = 10;stock = 10;};
 		};

		class Vests {
			displayName = "Бронежилеты и разгрузка";
			picture = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\compass_ca.paa";

			class rvg_platecarrier_1 {price = 600;stock = 2;};
			class rvg_platecarrier_2 {price = 600;stock = 2;};
			class rvg_platecarrier_3 {price = 600;stock = 2;};
			class rvg_platecarrier_4 {price = 600;stock = 2;};
			class rvg_platecarrier_5 {price = 600;stock = 2;};
			class rvg_bandolier_1 {price = 150;stock = 2;};
			class rvg_bandolier_2 {price = 150;stock = 2;};
			class rvg_bandolier_3 {price = 150;stock = 2;};
			class rvg_bandolier_4 {price = 150;stock = 2;};
			class rvg_rangemaster_1 {price = 100;stock = 2;};
			class rvg_rangemaster_2 {price = 100;stock = 2;};
			class rvg_rangemaster_3 {price = 100;stock = 2;};
			class rvg_rangemaster_4 {price = 100;stock = 2;};
			class rvg_ravenvest_1 {price = 300;stock = 2;};
			class rvg_tacvest_1 {price = 400;stock = 2;};
			class rvg_tacvest_2 {price = 300;stock = 2;};
			class rvg_tacvest_3 {price = 500;stock = 2;};
			class rvg_tacvest_4 {price = 300;stock = 2;};
			class rvg_legstrapbag_1 {price = 150;stock = 2;};
			class rvg_legstrapbag_2 {price = 150;stock = 2;};
			class rvg_legstrapbag_3 {price = 150;stock = 2;};
			class rvg_legstrapbag_4 {price = 150;stock = 2;};
			class rvg_multipocket_1 {price = 200;stock = 2;};
			class rvg_multipocket_2 {price = 200;stock = 2;};
			class rvg_multipocket_3 {price = 200;stock = 2;};
			class rvg_multipocket_4 {price = 200;stock = 2;};
			class rvg_multipocket_5 {price = 200;stock = 2;};
			class rvg_eodvest_1 {price = 700;stock = 2;};
			class rvg_eodvest_2 {price = 700;stock = 2;};
			class rvg_eodvest_3 {price = 700;stock = 2;};
			class rvg_deckvest_1 {price = 300;stock = 2;};
			class rvg_deckvest_2 {price = 300;stock = 2;};
			class rvg_chestrig {price = 250;stock = 2;};
			class V_PlateCarrier1_blk {price = 600;stock = 2;};
		    class V_PlateCarrier1_rgr {price = 600;stock = 2;};
		    class V_PlateCarrier2_blk {price = 800;stock = 2;};
		    class V_PlateCarrier2_rgr {price = 800;stock = 2;};
			class V_Chestrig_blk {price = 250;stock = 2;};
			class V_Chestrig_rgr {price = 250;stock = 2;};
			class V_Chestrig_khk {price = 250;stock = 2;};
			class V_Chestrig_oli {price = 250;stock = 2;};
		    class V_PlateCarrierL_CTRG {price = 500;stock = 2;};
			class V_PlateCarrierH_CTRG {price = 800;stock = 2;};
			class V_HarnessOGL_brn {price = 250;stock = 2;};
			class V_HarnessOGL_gry {price = 250;stock = 2;};
			class V_HarnessO_brn {price = 250;stock = 2;};
		    class V_HarnessO_gry {price = 250;stock = 2;};
		    class V_Rangemaster_Belt {price = 100;stock = 2;};
		    class V_TacVestIR_blk {price = 300;stock = 2;};
			class V_BandollierB_blk {price = 150;stock = 2;};
			class V_BandollierB_cbr {price = 150;stock = 2;};
			class V_BandollierB_rgr {price = 150;stock = 2;};
			class V_BandollierB_khk {price = 150;stock = 2;};
		    class V_BandollierB_oli {price = 150;stock = 2;};
			class V_TacVest_blk {price = 300;stock = 2;};
			class V_TacVest_brn {price = 300;stock = 2;};
		    class V_TacVest_camo {price = 300;stock = 2;};
			class V_TacVest_khk {price = 300;stock = 2;};
			class V_TacVest_oli {price = 300;stock = 2;};
			class V_TacVest_blk_POLICE {price = 400;stock = 2;};
			class V_PlateCarrierGL_blk {price = 700;stock = 2;};
			class V_PlateCarrierGL_rgr {price = 700;stock = 2;};
			class V_PlateCarrierGL_mtp {price = 700;stock = 2;};
			class V_PlateCarrierGL_tna_F {price = 700;stock = 2;};
		    class V_PlateCarrier_Kerry {price = 300;stock = 2;};
		    class V_PlateCarrier1_rgr_noflag_F {price = 600;stock = 2;};
			class V_PlateCarrier1_tna_F {price = 600;stock = 2;};
		    class V_PlateCarrier2_rgr_noflag_F {price = 800;stock = 2;};
			class V_PLateCarrierSpec_blk {price = 1200;stock = 2;};
		    class V_PLateCarrierSpec_rgr {price = 1200;stock = 2;};
			class V_PLateCarrierSpec_mtp {price = 1200;stock = 2;};
			class V_PLateCarrierSpec_tna_F {price = 1200;stock = 2;};
		    class V_PlateCarrierIAGL_dgtl {price = 700;stock = 2;};
			class V_PlateCarrierIAGL_oli {price = 700;stock = 2;};
		    class V_PlateCarrierIA1_dgtl {price = 550;stock = 2;};
		    class V_PlateCarrierIA2_dgtl {price = 550;stock = 2;};
			class V_TacVest_gen_F {price = 400;stock = 2;};
		    class V_HarnessOGL_ghex_F {price = 250;stock = 2;};
		    class V_HarnessO_ghex_F {price = 250;stock = 2;};
			class V_BandollierB_ghex_F {price = 150;stock = 2;};
			class V_TacChestrig_cbr_F {price = 250;stock = 2;};
			class V_TacChestrig_grn_F {price = 250;stock = 2;};
			class V_TacChestrig_oli_F {price = 250;stock = 2;};
			//Contact
			class V_CarrierRigKBT_01_EAF_F {price = 550;stock = 2;};
			class V_PlateCarrierSpec_wdl {price = 1200;stock = 2;};
            class V_CarrierRigKBT_01_heavy_EAF_F {price = 500;stock = 2;};
            class V_CarrierRigKBT_01_heavy_olive_F {price = 500;stock = 2;};
            class V_CarrierRigKBT_01_light_EAF_F {price = 500;stock = 2;};
            class V_CarrierRigKBT_01_light_olive_F {price = 500;stock = 2;};
            class V_CarrierRigKBT_01_olive_F {price = 100;stock = 2;};
            class V_PlateCarrier1_wdl {price = 600;stock = 2;};
            class V_PlateCarrier2_wdl {price = 800;stock = 2;};
            class V_PlateCarrierGL_wdl {price = 700;stock = 2;};
            class V_SmershVest_01_F {price = 250;stock = 2;};
            class V_SmershVest_01_radio_F {price = 250;stock = 2;};

			//RHS vests
			class rhs_6b13_Flora {price = 1200;stock = 10;};
			class rhs_6b13_Flora_6sh92 {price = 1500;stock = 10;};
			class rhs_6b13_Flora_6sh92_headset_mapcase {price = 1500;stock = 10;};
			class rhs_6b13_Flora_6sh92_radio {price = 1500;stock = 10;};
			class rhs_6b13_Flora_6sh92_vog {price = 1600;stock = 10;};
			class rhs_6b13_Flora_crewofficer {price = 1300;stock = 10;};
			class rhs_6b13_EMR_6sh92 {price = 1500;stock = 10;};
			class rhs_6b13_EMR_6sh92_radio {price = 1500;stock = 10;};
			class rhs_6b13_EMR_6sh92_vog {price = 1600;stock = 10;};
			class rhs_6b13_EMR_6sh92_headset_mapcase {price = 1500;stock = 10;};
			class rhs_6b13_EMR {price = 1200;stock = 10;};
			class rhs_6b13 {price = 1200;stock = 10;};
			class rhs_6b13_6sh92 {price = 1500;stock = 10;};
			class rhs_6b13_6sh92_headset_mapcase {price = 1500;stock = 10;};
			class rhs_6b13_6sh92_radio {price = 1500;stock = 10;};
			class rhs_6b13_6sh92_vog {price = 1600;stock = 10;};
			class rhs_6b13_crewofficer {price = 1200;stock = 10;};
			class rhs_6b23 {price = 600;stock = 10;};
			class rhs_6b23_6sh116_od {price = 800;stock = 10;};
			class rhs_6b23_6sh116_vog_od {price = 800;stock = 10;};
			class rhs_6b23_6sh92 {price = 800;stock = 10;};
			class rhs_6b23_6sh92_headset {price = 800;stock = 10;};
			class rhs_6b23_6sh92_headset_mapcase {price = 800;stock = 10;};
			class rhs_6b23_6sh92_radio {price = 800;stock = 10;};
			class rhs_6b23_6sh92_vog {price = 800;stock = 10;};
			class rhs_6b23_6sh92_vog_headset {price = 800;stock = 10;};
			class rhs_6b23_crewofficer {price = 600;stock = 10;};
			class rhs_6b23_crew {price = 800;stock = 10;};
			class rhs_6b23_engineer {price = 800;stock = 10;};
			class rhs_6b23_medic {price = 800;stock = 10;};
			class rhs_6b23_rifleman {price = 800;stock = 10;};
			class rhs_6b23_sniper {price = 800;stock = 10;};
			class rhs_6b23_vydra_3m {price = 800;stock = 10;};
			class rhs_6b23_digi {price = 800;stock = 10;};
			class rhs_6b23_6sh116 {price = 800;stock = 10;};
			class rhs_6b23_6sh116_vog {price = 800;stock = 10;};
			class rhs_6b23_digi_6sh92 {price = 600;stock = 10;};
			class rhs_6b23_digi_6sh92_headset {price = 800;stock = 10;};
			class rhs_6b23_digi_6sh92_headset_spetsnaz {price = 800;stock = 10;};
			class rhs_6b23_digi_6sh92_headset_mapcase {price = 800;stock = 10;};
			class rhs_6b23_digi_6sh92_radio {price = 800;stock = 10;};
			class rhs_6b23_digi_6sh92_Spetsnaz {price = 800;stock = 10;};
			class rhs_6b23_digi_6sh92_vog {price = 800;stock = 10;};
			class rhs_6b23_digi_6sh92_vog_headset {price = 800;stock = 10;};
			class rhs_6b23_digi_6sh92_Vog_Radio_Spetsnaz {price = 800;stock = 10;};
			class rhs_6b23_digi_crewofficer {price = 600;stock = 10;};
			class rhs_6b23_digi_crew {price = 800;stock = 10;};
			class rhs_6b23_digi_engineer {price = 800;stock = 10;};
			class rhs_6b23_digi_medic {price = 800;stock = 10;};
			class rhs_6b23_digi_rifleman {price = 800;stock = 10;};
			class rhs_6b23_digi_sniper {price = 800;stock = 10;};
			class rhs_6b23_digi_vydra_3m {price = 800;stock = 10;};
			class rhs_6b23_6sh116_flora {price = 800;stock = 10;};
			class rhs_6b23_6sh116_vog_flora {price = 800;stock = 10;};
			class rhs_6b23_ML {price = 800;stock = 10;};
			class rhs_6b23_ML_6sh92 {price = 800;stock = 10;};
			class rhs_6b23_ML_6sh92_headset {price = 800;stock = 10;};
			class rhs_6b23_ML_6sh92_headset_mapcase {price = 800;stock = 10;};
			class rhs_6b23_ML_6sh92_radio {price = 800;stock = 10;};
			class rhs_6b23_ML_6sh92_vog {price = 800;stock = 10;};
			class rhs_6b23_ML_6sh92_vog_headset {price = 800;stock = 10;};
			class rhs_6b23_ML_crewofficer {price = 800;stock = 10;};
			class rhs_6b23_ML_crew {price = 800;stock = 10;};
			class rhs_6b23_ML_engineer {price = 800;stock = 10;};
			class rhs_6b23_ML_medic {price = 800;stock = 10;};
			class rhs_6b23_ML_rifleman {price = 800;stock = 10;};
			class rhs_6b23_ML_sniper {price = 800;stock = 10;};
			class rhs_6b23_ML_vydra_3m {price = 800;stock = 10;};
			class rhs_vydra_3m {price = 200;stock = 10;};
			class rhs_6sh46 {price = 100;stock = 10;};
			class rhs_6sh92 {price = 250;stock = 10;};
			class rhs_6sh92_headset {price = 250;stock = 10;};
			class rhs_6sh92_radio {price = 250;stock = 10;};
			class rhs_6sh92_vog {price = 250;stock = 10;};
			class rhs_6sh92_vog_headset {price = 250;stock = 10;};
			class rhs_6sh92_digi {price = 250;stock = 10;};
			class rhs_6sh92_digi_headset {price = 250;stock = 10;};
			class rhs_6sh92_digi_radio {price = 250;stock = 10;};
			class rhs_6sh92_digi_vog {price = 250;stock = 10;};
			class rhs_6sh92_digi_vog_headset {price = 250;stock = 10;};
			class rhs_6b45 {price = 1300;stock = 10;};
			class rhs_6b45_desert {price = 1300;stock = 10;};
			class rhs_6b45_holster {price = 1300;stock = 10;};
			class rhs_6b45_mg {price = 1600;stock = 10;};
			class rhs_6b45_light {price = 1600;stock = 10;};
			class rhs_6b45_off {price = 1600;stock = 10;};
			class rhs_6b45_rifleman {price = 1600;stock = 10;};
			class rhs_6b45_grn {price = 1600;stock = 10;};
			class rhsusf_iotv_ocp_Grenadier {price = 1800;stock = 10;};
			class rhsusf_iotv_ucp_Grenadier {price = 1800;stock = 10;};
			class rhsusf_iotv_ocp_Medic {price = 1800;stock = 10;};
			class rhsusf_iotv_ucp_Medic {price = 1800;stock = 10;};
			class rhsusf_iotv_ocp {price = 1400;stock = 10;};
			class rhsusf_iotv_ocp_Repair {price = 1800;stock = 10;};
			class rhsusf_iotv_ucp_Repair {price = 1800;stock = 10;};
			class rhsusf_iotv_ocp_Rifleman {price = 1800;stock = 10;};
			class rhsusf_iotv_ucp_Rifleman {price = 1800;stock = 10;};
			class rhsusf_iotv_ocp_SAW {price = 1800;stock = 10;};
			class rhsusf_iotv_ucp_SAW {price = 1800;stock = 10;};
			class rhsusf_iotv_ocp_Squadleader {price = 1800;stock = 10;};
			class rhsusf_iotv_ucp_Squadleader {price = 1800;stock = 10;};
			class rhsusf_iotv_ocp_Teamleader {price = 1800;stock = 10;};
			class rhsusf_iotv_ucp_Teamleader {price = 1800;stock = 10;};
			class rhsusf_iotv_ucp {price = 1400;stock = 10;};
			class rhs_vest_commander {price = 100;stock = 10;};
			class rhs_vest_pistol_holster {price = 100;stock = 10;};
			class rhsusf_spc {price = 1800;stock = 10;};
			class rhsusf_spc_corpsman {price = 1800;stock = 10;};
			class rhsusf_spc_crewman {price = 1800;stock = 10;};
			class rhsusf_spc_iar {price = 1800;stock = 10;};
			class rhsusf_spc_light {price = 1800;stock = 10;};
			class rhsusf_spc_mg {price = 1800;stock = 10;};
			class rhsusf_spc_marksman {price = 1800;stock = 10;};
			class rhsusf_spc_patchless {price = 1800;stock = 10;};
			class rhsusf_spc_patchless_radio {price = 1800;stock = 10;};
			class rhsusf_spc_rifleman {price = 1800;stock = 10;};
			class rhsusf_spc_squadleader {price = 1800;stock = 10;};
			class rhsusf_spc_teamleader {price = 1800;stock = 10;};
			class rhsusf_spcs_ocp {price = 1800;stock = 10;};
			class rhsusf_spcs_ocp_rifleman {price = 1800;stock = 10;};
			class rhsusf_spcs_ucp_rifleman {price = 1800;stock = 10;};
			class rhsusf_spcs_ucp {price = 1800;stock = 10;};
			class rhsgref_6b23_khaki_medic {price = 800;stock = 25;};
			class rhsgref_6b23_khaki_nco {price = 800;stock = 25;};
			class rhsgref_6b23_khaki_officer {price = 800;stock = 25;};
			class rhsgref_6b23_khaki_rifleman {price = 800;stock = 25;};
			class rhsgref_6b23_khaki_sniper {price = 800;stock = 25;};
			class rhsgref_6b23_khaki {price = 800;stock = 25;};
			class rhsgref_alice_webbing {price = 200;stock = 25;};
			class rhsgref_otv_digi {price = 800;stock = 25;};
			class rhsgref_otv_khaki {price = 800;stock = 25;};
			class rhsgref_TacVest_ERDL {price = 350;stock = 25;};
			class rhs_6b5_khaki {price = 1000;stock = 25;};
			class rhs_6b5_rifleman_khaki {price = 1000;stock = 10;};
			class rhs_6b5_medic_khaki {price = 1000;stock = 10;};
			class rhs_6b5_officer_khaki {price = 1000;stock = 10;};
			class rhs_6b5_sniper_khaki {price = 1000;stock = 10;};
			class rhs_6b5_spetsodezhda {price = 1000;stock = 10;};
			class rhs_6b5_rifleman_spetsodezhda {price = 1000;stock = 10;};
			class rhs_6b5_medic_spetsodezhda {price = 1000;stock = 10;};
			class rhs_6b5_officer_spetsodezhda {price = 1000;stock = 10;};
			class rhs_6b5_sniper_spetsodezhda {price = 1000;stock = 10;};
			class rhs_6b5 {price = 1000;stock = 10;};
			class rhs_6b5_rifleman {price = 1000;stock = 10;};
			class rhs_6b5_medic {price = 1000;stock = 10;};
			class rhs_6b5_officer {price = 1000;stock = 10;};
			class rhs_6b5_sniper {price = 1000;stock = 10;};
			class rhs_6b5_ttsko {price = 1000;stock = 10;};
			class rhs_6b5_rifleman_ttsko {price = 1000;stock = 10;};
			class rhs_6b5_medic_ttsko {price = 1000;stock = 10;};
			class rhs_6b5_officer_ttsko {price = 1000;stock = 10;};
			class rhs_6b5_sniper_ttsko {price = 1000;stock = 10;};
			class rhs_6b5_vsr {price = 1000;stock = 10;};
			class rhs_6b5_rifleman_vsr {price = 1000;stock = 10;};
			class rhs_6b5_medic_vsr {price = 1000;stock = 10;};
			class rhs_6b5_officer_vsr {price = 1000;stock = 10;};
			class rhs_6b5_sniper_vsr {price = 200;stock = 25;};
			class rhs_6sh117_mg {price = 300;stock = 25;};
			class rhs_6sh117_rifleman {price = 300;stock = 25;};
			class rhs_6sh117_ar {price = 300;stock = 25;};
			class rhs_6sh117_nco {price = 300;stock = 25;};
			class rhs_6sh117_nco_azart {price = 300;stock = 25;};
			class rhs_6sh117_svd {price = 300;stock = 25;};
			class rhs_6sh117_grn {price = 300;stock = 25;};
			class rhs_6sh117_val {price = 300;stock = 25;};
			//EO Vests
			class V_SmershVest_01_urban_F {price = 250;stock = 25;};
			class V_SmershVest_01_radio_urban_F {price = 250;stock = 25;};
			class V_SmershVest_01_black_F {price = 250;stock = 25;};
			class V_SmershVest_01_radio_black_F {price = 250;stock = 25;};
			class V_CarrierRigKBT_01_LDF_F {price = 450;stock = 25;};
			class V_CarrierRigKBT_01_light_LDF_F {price = 550;stock = 25;};
			class V_CarrierRigKBT_01_DarkOlive_F {price = 450;stock = 25;};
			class V_CarrierRigKBT_01_light_DarkOlive_F {price = 550;stock = 25;};
		};

		class Facewear {	
			displayName = "Очки и маски";
			picture = "";
			//vanilla
			class G_Aviator {price = 10;stock = 2;};
			class G_Balaclava_blk {price = 10;stock = 2;};
			class G_Balaclava_combat {price = 10;stock = 2;};
			class G_Balaclava_lowprofile {price = 10;stock = 2;};
			class G_Balaclava_oli {price = 10;stock = 2;};
			class G_Bandanna_aviator {price = 10;stock = 2;};
			class G_Bandanna_beast {price = 10;stock = 2;};
			class G_Bandanna_blk {price = 10;stock = 2;};
			class G_Bandanna_khk {price = 10;stock = 2;};
			class G_Bandanna_oli {price = 10;stock = 2;};
			class G_Bandanna_shades {price = 10;stock = 2;};
			class G_Bandanna_sport {price = 10;stock = 2;};
			class G_Bandanna_tan {price = 10;stock = 2;};
			class G_Combat {price = 10;stock = 2;};
			//rvg
			class rvg_bandanaShades_1 {price = 10;stock = 2;};
			class rvg_bandanaShades_2 {price = 10;stock = 2;};
			class rvg_bandanaShades_3 {price = 10;stock = 2;};
			class rvg_bandanaShades_4 {price = 10;stock = 2;};
			class rvg_bandanaShades_5 {price = 10;stock = 2;};
			class rvg_bandanaSport_1 {price = 10;stock = 2;};
			class rvg_bandanaSport_2 {price = 10;stock = 2;};
			class rvg_bandanaSport_3 {price = 10;stock = 2;};
			class rvg_bandanaSport_4 {price = 10;stock = 2;};
			class rvg_bandanaSport_5 {price = 10;stock = 2;};
			class rvg_respirator_1 {price = 10;stock = 2;};
			class rvg_respirator_2 {price = 10;stock = 2;};
			class rvg_respirator_3 {price = 10;stock = 2;};
			class rvg_respirator_4 {price = 10;stock = 2;};
			class rvg_respirator_5 {price = 10;stock = 2;};
			class rvg_eyeprotector {price = 10;stock = 2;};
			class rvg_balaclava_1 {price = 10;stock = 2;};
			class rvg_balaclava_2 {price = 10;stock = 2;};
			class rvg_balaclava_3 {price = 10;stock = 2;};
			class rvg_balaclava_4 {price = 10;stock = 2;};
			class rvg_balaclava_5 {price = 10;stock = 2;};
			class rvg_balaclavaLow_1 {price = 10;stock = 2;};
			class rvg_balaclavaLow_2 {price = 10;stock = 2;};
			class rvg_balaclavaLow_3 {price = 10;stock = 2;};
			class rvg_balaclavaLow_4 {price = 10;stock = 2;};
			class rvg_balaclavaLow_5 {price = 10;stock = 2;};
			class rvg_balaclavaCombat_1 {price = 10;stock = 2;};
			class rvg_balaclavaCombat_2 {price = 10;stock = 2;};
			class rvg_balaclavaCombat_3 {price = 10;stock = 2;};
			class rvg_balaclavaCombat_4 {price = 10;stock = 2;};
			class rvg_balaclavaCombat_5 {price = 10;stock = 2;};
			class rvg_bandana_1 {price = 10;stock = 2;};
			class rvg_bandana_2 {price = 10;stock = 2;};
			class rvg_bandana_3 {price = 10;stock = 2;};
			class rvg_bandana_4 {price = 10;stock = 2;};
			class rvg_bandana_5 {price = 10;stock = 2;};
			class rvg_bandanaAvi_1 {price = 10;stock = 2;};
			class rvg_bandanaAvi_2 {price = 10;stock = 2;};
			class rvg_bandanaAvi_3 {price = 10;stock = 2;};
			class rvg_bandanaAvi_4 {price = 10;stock = 2;};
			class rvg_bandanaAvi_5 {price = 10;stock = 2;};
			//RHS
			class rhs_balaclava {price = 10;stock = 10;};
			class rhs_balaclava1_olive {price = 10;stock = 10;};
			class rhs_googles_black {price = 10;stock = 10;};
			class rhs_googles_orange {price = 10;stock = 10;};
			class rhs_googles_yellow {price = 10;stock = 10;};
			class rhs_googles_clear {price = 10;stock = 10;};
			class rhs_ess_black {price = 10;stock = 10;};
			class LBG_Shemagh_gry {price = 10;stock = 10;};
			class rhsusf_shemagh2_white {price = 10;stock = 10;};
			class rhsusf_shemagh_gogg_od {price = 10;stock = 10;};
			class rhsusf_shemagh2_gogg_white {price = 10;stock = 10;};
			class rhsusf_shemagh2_grn {price = 10;stock = 10;};
			class rhsusf_shemagh_grn {price = 10;stock = 10;};
			class rhsusf_shemagh_gogg_tan {price = 10;stock = 10;};
			class rhsusf_shemagh2_od {price = 10;stock = 10;};
			class rhsusf_shemagh2_gogg_tan {price = 10;stock = 10;};
			class rhsusf_shemagh_gogg_white {price = 10;stock = 10;};
			class rhsusf_oakley_goggles_blk {price = 10;stock = 10;};
			class rhsusf_oakley_goggles_clr {price = 10;stock = 10;};
			class rhsusf_oakley_goggles_ylw {price = 10;stock = 10;};
			class rhs_scarf {price = 10;stock = 10;};
		};

		class Helmets {	
			displayName = "Шлем";
			picture = "";

			//RHS
			class rhs_altyn_bala {price = 450;stock = 2;};
			class rhs_6b26_green {price = 450;stock = 2;};
			class rhs_6b26_bala_green {price = 450;stock = 2;};
			class rhs_6b26_ess_green {price = 450;stock = 2;};
			class rhs_6b26_ess_bala_green {price = 450;stock = 2;};
			class rhs_6b26 {price = 450;stock = 2;};
			class rhs_6b26_bala {price = 450;stock = 2;};
			class rhs_6b26_ess {price = 450;stock = 2;};
			class rhs_6b26_ess_bala {price = 450;stock = 2;};
			class rhs_6b27m_green {price = 450;stock = 2;};
			class rhs_6b27m_green_bala {price = 450;stock = 2;};
			class rhs_6b27m_green_ess {price = 450;stock = 2;};
			class rhs_6b27m_green_ess_bala {price = 450;stock = 2;};
			class rhs_6b27m_digi {price = 450;stock = 2;};
			class rhs_6b27m_digi_bala {price = 450;stock = 2;};
			class rhs_6b27m_digi_ess {price = 450;stock = 2;};
			class rhs_6b27m_digi_ess_bala {price = 450;stock = 2;};
			class rhs_6b27m {price = 450;stock = 2;};
			class rhs_6b27m_bala {price = 450;stock = 2;};
			class rhs_6b27m_ess {price = 450;stock = 2;};
			class rhs_6b27m_ess_bala {price = 450;stock = 2;};
			class rhs_6b27m_ml {price = 450;stock = 2;};
			class rhs_6b27m_ml_bala {price = 450;stock = 2;};
			class rhs_6b27m_ml_ess {price = 450;stock = 2;};
			class rhs_6b27m_ML_ess_bala {price = 450;stock = 2;};
			class rhs_6b28_green {price = 450;stock = 2;};
			class rhs_6b28_green_bala {price = 450;stock = 2;};
			class rhs_6b28_green_ess {price = 450;stock = 2;};
			class rhs_6b28_green_ess_bala {price = 450;stock = 2;};
			class rhs_6b28 {price = 450;stock = 2;};
			class rhs_6b28_bala {price = 450;stock = 2;};
			class rhs_6b28_ess {price = 450;stock = 2;};
			class rhs_6b28_ess_bala {price = 450;stock = 2;};
			class rhs_6b28_flora {price = 450;stock = 2;};
			class rhs_6b28_flora_bala {price = 450;stock = 2;};
			class rhs_6b28_flora_ess {price = 450;stock = 2;};
			class rhs_6b28_flora_ess_bala {price = 450;stock = 2;};
			class rhs_6b47 {price = 450;stock = 2;};
			class rhs_6b47_bala {price = 450;stock = 2;};
			class rhs_6b47_ess {price = 450;stock = 2;};
			class rhs_6b47_ess_bala {price = 450;stock = 2;};
			class rhs_6b7_1m {price = 450;stock = 2;};
			class rhs_6b7_1m_bala1 {price = 450;stock = 2;};
			class rhs_6b7_1m_bala2 {price = 450;stock = 2;};
			class rhs_6b7_1m_emr {price = 450;stock = 2;};
			class rhs_6b7_1m_bala1_emr {price = 450;stock = 2;};
			class rhs_6b7_1m_bala2_emr {price = 450;stock = 2;};
			class rhs_6b7_1m_emr_ess {price = 450;stock = 2;};
			class rhs_6b7_1m_emr_ess_bala {price = 450;stock = 2;};
			class rhs_6b7_1m_ess {price = 450;stock = 2;};
			class rhs_6b7_1m_ess_bala {price = 450;stock = 2;};
			class rhs_6b7_1m_flora {price = 450;stock = 2;};
			class rhs_6b7_1m_bala2_flora {price = 450;stock = 2;};
			class rhs_6b7_1m_bala1_flora {price = 450;stock = 2;};
			class rhs_6b7_1m_flora_ns3 {price = 450;stock = 2;};
			class rhs_6b7_1m_olive {price = 450;stock = 2;};
			class rhs_6b7_1m_bala1_olive {price = 450;stock = 2;};
			class rhs_6b7_1m_bala2_olive {price = 450;stock = 2;};
			class rhsusf_ach_bare {price = 450;stock = 2;};
			class rhsusf_ach_bare_des {price = 450;stock = 2;};
			class rhsusf_ach_bare_des_ess {price = 450;stock = 2;};
			class rhsusf_ach_bare_des_headset {price = 450;stock = 2;};
			class rhsusf_ach_bare_des_headset_ess {price = 450;stock = 2;};
			class rhsusf_ach_bare_ess {price = 450;stock = 2;};
			class rhsusf_ach_bare_headset {price = 450;stock = 2;};
			class rhsusf_ach_bare_headset_ess {price = 450;stock = 2;};
			class rhsusf_ach_bare_semi {price = 450;stock = 2;};
			class rhsusf_ach_bare_semi_ess {price = 450;stock = 2;};
			class rhsusf_ach_bare_semi_headset {price = 450;stock = 2;};
			class rhsusf_ach_bare_semi_headset_ess {price = 450;stock = 2;};
			class rhsusf_ach_bare_tan {price = 450;stock = 2;};
			class rhsusf_ach_bare_tan_ess {price = 450;stock = 2;};
			class rhsusf_ach_bare_tan_headset {price = 450;stock = 2;};
			class rhsusf_ach_bare_tan_headset_ess {price = 450;stock = 2;};
			class rhsusf_ach_bare_wood {price = 450;stock = 2;};
			class rhsusf_ach_bare_wood_ess {price = 450;stock = 2;};
			class rhsusf_ach_bare_wood_headset {price = 450;stock = 2;};
			class rhsusf_ach_bare_wood_headset_ess {price = 450;stock = 2;};
			class rhsusf_ach_helmet_M81 {price = 450;stock = 2;};
			class rhsusf_ach_helmet_ocp {price = 450;stock = 2;};
			class rhsusf_ach_helmet_ESS_ocp {price = 450;stock = 2;};
			class rhsusf_ach_helmet_headset_ocp {price = 450;stock = 2;};
			class rhsusf_ach_helmet_headset_ess_ocp {price = 450;stock = 2;};
			class rhsusf_ach_helmet_camo_ocp {price = 450;stock = 2;};
			class rhsusf_ach_helmet_ocp_norotos {price = 450;stock = 2;};
			class rhsusf_ach_helmet_ucp {price = 450;stock = 2;};
			class rhsusf_ach_helmet_ESS_ucp {price = 450;stock = 2;};
			class rhsusf_ach_helmet_headset_ucp {price = 450;stock = 2;};
			class rhsusf_ach_helmet_headset_ess_ucp {price = 450;stock = 2;};
			class rhsusf_ach_helmet_ucp_norotos {price = 450;stock = 2;};
			class rhsusf_cvc_green_helmet {price = 450;stock = 2;};
			class rhsusf_cvc_green_ess {price = 450;stock = 2;};
			class rhsusf_cvc_helmet {price = 450;stock = 2;};
			class rhsusf_cvc_ess {price = 450;stock = 2;};
			class rhsusf_hgu56p_usa {price = 450;stock = 2;};
			class rhsusf_hgu56p_visor_usa {price = 450;stock = 2;};
			class rhsusf_opscore_aor1 {price = 450;stock = 2;};
			class rhsusf_opscore_aor1_pelt {price = 450;stock = 2;};
			class rhsusf_opscore_aor1_pelt_nsw {price = 450;stock = 2;};
			class rhsusf_opscore_aor2 {price = 450;stock = 2;};
			class rhsusf_opscore_aor2_pelt {price = 450;stock = 2;};
			class rhsusf_opscore_aor2_pelt_nsw {price = 450;stock = 2;};
			class rhsusf_opscore_bk {price = 450;stock = 2;};
			class rhsusf_opscore_bk_pelt {price = 450;stock = 2;};
			class rhsusf_opscore_coy_cover {price = 450;stock = 2;};
			class rhsusf_opscore_coy_cover_pelt {price = 450;stock = 2;};
			class rhsusf_opscore_fg {price = 450;stock = 2;};
			class rhsusf_opscore_fg_pelt {price = 450;stock = 2;};
			class rhsusf_opscore_fg_pelt_cam {price = 450;stock = 2;};
			class rhsusf_opscore_fg_pelt_nsw {price = 450;stock = 2;};
			class rhsusf_opscore_mc_cover {price = 450;stock = 2;};
			class rhsusf_opscore_mc_cover_pelt {price = 450;stock = 2;};
			class rhsusf_opscore_mc_cover_pelt_nsw {price = 450;stock = 2;};
			class rhsusf_opscore_mc_cover_pelt_cam {price = 450;stock = 2;};
			class rhsusf_opscore_mc {price = 450;stock = 2;};
			class rhsusf_opscore_mc_pelt {price = 450;stock = 2;};
			class rhsusf_opscore_mc_pelt_nsw {price = 450;stock = 2;};
			class rhsusf_opscore_paint {price = 450;stock = 2;};
			class rhsusf_opscore_paint_pelt {price = 450;stock = 2;};
			class rhsusf_opscore_paint_pelt_nsw {price = 450;stock = 2;};
			class rhsusf_opscore_paint_pelt_nsw_cam {price = 450;stock = 2;};
			class rhsusf_opscore_rg_cover {price = 450;stock = 2;};
			class rhsusf_opscore_rg_cover_pelt {price = 450;stock = 2;};
			class rhsusf_opscore_ut {price = 450;stock = 2;};
			class rhsusf_opscore_ut_pelt {price = 450;stock = 2;};
			class rhsusf_opscore_ut_pelt_cam {price = 450;stock = 2;};
			class rhsusf_opscore_ut_pelt_nsw {price = 450;stock = 2;};
			class rhsusf_opscore_ut_pelt_nsw_cam {price = 450;stock = 2;};
			class rhsusf_hgu56p {price = 450;stock = 2;};
			class rhsusf_hgu56p_mask {price = 450;stock = 2;};
			class rhsusf_lwh_helmet_M1942 {price = 450;stock = 2;};
			class rhsusf_lwh_helmet_marpatd {price = 450;stock = 2;};
			class rhsusf_lwh_helmet_marpatd_ess {price = 450;stock = 2;};
			class rhsusf_lwh_helmet_marpatd_headset {price = 450;stock = 2;};
			class rhsusf_lwh_helmet_marpatwd {price = 450;stock = 2;};
			class rhsusf_lwh_helmet_marpatwd_blk_ess {price = 450;stock = 2;};
			class rhsusf_lwh_helmet_marpatwd_headset_blk {price = 450;stock = 2;};
			class rhsusf_lwh_helmet_marpatwd_headset {price = 450;stock = 2;};
			class rhsusf_lwh_helmet_marpatwd_ess {price = 450;stock = 2;};
			class rhsusf_mich_bare {price = 450;stock = 2;};
			class rhsusf_mich_bare_alt {price = 450;stock = 2;};
			class rhsusf_mich_bare_headset {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos_alt {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos_alt_headset {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos_arc_alt {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos_arc_alt_headset {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos_arc_headset {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos_headset {price = 450;stock = 2;};
			class rhsusf_mich_bare_semi {price = 450;stock = 2;};
			class rhsusf_mich_bare_alt_semi {price = 450;stock = 2;};
			class rhsusf_mich_bare_semi_headset {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos_semi {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos_alt_semi {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos_alt_semi_headset {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos_arc_semi {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos_arc_alt_semi {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos_arc_alt_semi_headset {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos_arc_semi_headset {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos_semi_headset {price = 450;stock = 2;};
			class rhsusf_mich_bare_tan {price = 450;stock = 2;};
			class rhsusf_mich_bare_alt_tan {price = 450;stock = 2;};
			class rhsusf_mich_bare_tan_headset {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos_tan {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos_alt_tan {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos_alt_tan_headset {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos_arc_tan {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos_arc_alt_tan {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos_arc_alt_tan_headset {price = 450;stock = 2;};
			class rhsusf_mich_bare_norotos_tan_headset {price = 450;stock = 2;};
			class rhsusf_mich_helmet_marpatd {price = 450;stock = 2;};
			class rhsusf_mich_helmet_marpatd_alt {price = 450;stock = 2;};
			class rhsusf_mich_helmet_marpatd_alt_headset {price = 450;stock = 2;};
			class rhsusf_mich_helmet_marpatd_headset {price = 450;stock = 2;};
			class rhsusf_mich_helmet_marpatd_norotos {price = 450;stock = 2;};
			class rhsusf_mich_helmet_marpatd_norotos_arc {price = 450;stock = 2;};
			class rhsusf_mich_helmet_marpatd_norotos_arc_headset {price = 450;stock = 2;};
			class rhsusf_mich_helmet_marpatd_norotos_headset {price = 450;stock = 2;};
			class rhsusf_mich_helmet_marpatwd {price = 450;stock = 2;};
			class rhsusf_mich_helmet_marpatwd_alt {price = 450;stock = 2;};
			class rhsusf_mich_helmet_marpatwd_alt_headset {price = 450;stock = 2;};
			class rhsusf_mich_helmet_marpatwd_headset {price = 450;stock = 2;};
			class rhsusf_mich_helmet_marpatwd_norotos {price = 450;stock = 2;};
			class rhsusf_mich_helmet_marpatwd_norotos_arc {price = 450;stock = 2;};
			class rhsusf_mich_helmet_marpatwd_norotos_arc_headset {price = 450;stock = 2;};
			class rhsusf_mich_helmet_marpatwd_norotos_headset {price = 450;stock = 2;};
			class rhsusf_protech_helmet {price = 250;stock = 10;};
			class rhsusf_protech_helmet_ess {price = 250;stock = 10;};
			class rhsusf_protech_helmet_rhino {price = 250;stock = 10;};
			class rhsusf_protech_helmet_rhino_ess {price = 250;stock = 10;};
			class rhs_ssh68_2 {price = 100;stock = 10;};
			class rhs_tsh4 {price = 300;stock = 10;};
			class rhs_tsh4_bala {price = 300;stock = 2;};
			class rhs_tsh4_ess {price = 300;stock = 2;};
			class rhs_tsh4_ess_bala {price = 300;stock = 2;};
			class rhs_zsh12 {price = 300;stock = 2;};
			class rhs_zsh12_bala {price = 300;stock = 2;};
			class rhs_zsh12_black {price = 300;stock = 2;};
			class rhs_zsh7a_mike_green_alt {price = 300;stock = 2;};
			class rhs_zsh7a_mike_alt {price = 300;stock = 2;};
			class rhs_zsh7a_mike_green {price = 300;stock = 2;};
			class rhs_zsh7a_mike {price = 300;stock = 2;};
			class rhs_zsh7a {price = 300;stock = 2;};
			class rhs_zsh7a_alt {price = 300;stock = 2;};
			class rhs_altyn_visordown {price = 450;stock = 2;};
			class rhsusf_hgu56p_visor_white {price = 300;stock = 10;};
			class rhsgref_ssh68_un {price = 100;stock = 10;};
			class rhsgref_ssh68_ttsko_dark {price = 100;stock = 25;};
			class rhsgref_ssh68_ttsko_mountain {price = 100;stock = 10;};
			class rhsgref_ssh68_ttsko_forest {price = 100;stock = 10;};
			class rhsgref_ssh68_ttsko_digi {price = 100;stock = 10;};
			class rhsgref_ssh68_emr {price = 100;stock = 10;};
			class rhsgref_ssh68_vsr {price = 100;stock = 10;};
			class rhs_stsh81_butan {price = 450;stock = 2;};
			class rhs_stsh81 {price = 450;stock = 10;};
			class rhsgref_helmet_pasgt_woodland_rhino {price = 450;stock = 2;};
			class rhsgref_helmet_pasgt_woodland {price = 450;stock = 2;};
			class rhsgref_helmet_pasgt_un {price = 450;stock = 2;};
			class rhsgref_helmet_pasgt_olive {price = 450;stock = 2;};
			class rhsgref_helmet_pasgt_press {price = 450;stock = 2;};
			class rhsgref_helmet_pasgt_flecktarn {price = 450;stock = 2;};
			class rhsgref_helmet_pasgt_erdl_rhino {price = 450;stock = 2;};
			class rhsgref_helmet_pasgt_erdl {price = 450;stock = 2;};
			class rhsgref_helmet_pasgt_altis_lizard {price = 450;stock = 2;};
			class rhsgref_helmet_pasgt_3color_desert_rhino {price = 450;stock = 2;};
			class rhsgref_helmet_pasgt_3color_desert {price = 450;stock = 2;};
			class rhsgref_M56 {price = 30;stock = 10;};
			class rhsgref_helmet_m1942_heerwintercover {price = 30;stock = 10;};
			class rhsgref_helmet_m1942_heermarshcover {price = 30;stock = 10;};
			class rhsgref_helmet_m1942_heersplintercover {price = 30;stock = 10;};
			class rhsgref_helmet_m1942_heergreycover {price = 30;stock = 10;};
			class rhsgref_helmet_m1942_winter {price = 30;stock = 10;};
			class rhsgref_helmet_m1942_winter_alt1 {price = 30;stock = 10;};
			class rhsgref_helmet_m1942_camo01_alt1 {price = 30;stock = 10;};
			class rhsgref_helmet_m1942_alt1 {price = 30;stock = 10;};
			class rhsgref_helmet_m1942_camo01 {price = 30;stock = 10;};
			class rhsgref_helmet_m1942 {price = 30;stock = 10;};
			class rhsgref_helmet_m1940_winter {price = 30;stock = 10;};
			class rhsgref_helmet_m1940_winter_alt1 {price = 30;stock = 10;};
			class rhsgref_helmet_m1940_camo01_alt1 {price = 30;stock = 10;};
			class rhsgref_helmet_m1940_alt1 {price = 30;stock = 10;};
			class rhsgref_helmet_m1940_camo01 {price = 30;stock = 10;};
			class rhsgref_helmet_m1940 {price = 30;stock = 10;};
			class rhsgref_helmet_M1_painted_alt01 {price = 30;stock = 10;};
			class rhsgref_helmet_M1_painted {price = 30;stock = 10;};
			class rhsgref_helmet_M1_bare_alt01 {price = 30;stock = 10;};
			class rhsgref_helmet_M1_bare {price = 30;stock = 10;};
			class rhsgref_helmet_M1_mit {price = 30;stock = 10;};
			class rhsgref_helmet_M1_liner {price = 30;stock = 10;};
			class rhsgref_helmet_M1_erdl {price = 30;stock = 10;};
			class rhsgref_helmet_M1_des {price = 30;stock = 10;};
			class rhsgref_6b27m_ttsko_urban {price = 450;stock = 2;};
			class rhsgref_6b27m_ttsko_mountain {price = 450;stock = 2;};
			class rhsgref_6b27m_ttsko_forest {price = 450;stock = 2;};
			class rhsgref_6b27m_ttsko_digi {price = 450;stock = 2;};
			//vanilla
			class H_HelmetB {price = 450;stock = 2;};
		    class H_HelmetB_black {price = 450;stock = 2;};
		    class H_HelmetB_camo {price = 450;stock = 2;};
		    class H_HelmetB_desert {price = 450;stock = 2;};
		    class H_HelmetB_grass {price = 450;stock = 2;};
			class H_HelmetB_sand {price = 450;stock = 2;};
		    class H_HelmetB_snakeskin {price = 450;stock = 2;};
		    class H_HelmetCrew_I {price = 450;stock = 2;};
			class H_HelmetCrew_B {price = 450;stock = 2;};
		    class H_HelmetSpecB {price = 800;stock = 2;};
			class H_HelmetSpecB_wdl {price = 800;stock = 2;};
			class H_HelmetSpecB_blk {price = 800;stock = 2;};
			class H_HelmetSpecB_paint2 {price = 800;stock = 2;};
			class H_HelmetSpecB_paint1 {price = 800;stock = 2;};
		    class H_HelmetSpecB_sand {price = 800;stock = 2;};
            class H_HelmetSpecB_snakeskin {price = 800;stock = 2;};
		    class H_HelmetB_light {price = 150;stock = 2;};
		    class H_HelmetB_light_black {price = 150;stock = 2;};
			class H_HelmetB_light_desert {price = 150;stock = 2;};
            class H_HelmetB_light_grass {price = 150;stock = 2;};
            class H_HelmetB_light_sand {price = 150;stock = 2;};
			class H_HelmetB_light_snakeskin {price = 150;stock = 2;};
			class H_HelmetB_Light_tna_F {price = 150;stock = 2;};
			class H_HelmetB_tna_F {price = 450;stock = 2;};
		    class H_HelmetB_Enh_tna_F {price = 800;stock = 2;};
			class H_PilotHelmetFighter_I_E {price = 1500;stock = 10;};
            class H_PilotHelmetFighter_B {price = 1500;stock = 5;};
            class H_HelmetB_light_wdl {price = 150;stock = 2;};
            class H_HelmetB_plain_wdl {price = 150;stock = 2;};
			class rvg_presshelmet_1 {price = 400;stock = 2;};
			class rvg_presshelmet_2 {price = 400;stock = 2;};
			class rvg_presshelmet_3 {price = 400;stock = 2;};
		};
		
		class Special {
			displayName = "Навигация и радио";
			picture = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\compass_ca.paa";
            //CUP
			class ItemWatch {price = 200;stock = 10;};
			class ItemCompass {price = 450;stock = 5;};
			class ACE_microDAGR {price = 950;stock =25;};
			class ItemGPS {price = 650;stock = 5;};
			class ItemRadio {price = 200;stock = 5;};
			class Binocular {price = 345;stock = 5;};
			class Rangefinder {price = 970;stock = 5;};
			class Laserdesignator {price = 1500;stock = 5;};
			class Laserbatteries {price = 350;stock = 5;};
			class Laserdesignator_02 {price = 1500;stock = 2;};
			class Laserdesignator_03 {price = 1500;stock = 2;};
			class Laserdesignator_01_khk_F {price = 1500;stock = 2;};
			class Laserdesignator_02_ghex_F {price = 1500;stock = 2;};
			class MineDetector {price = 700;stock = 5;};
			class O_NVGoggles_ghex_F {price = 1400;stock = 2;};
			class O_NVGoggles_hex_F {price = 1400;stock = 2;};
			class O_NVGoggles_urb_F {price = 1400;stock = 2;};
			class NVGoggles {price = 1400;stock = 2;};
			class NVGoggles_tna_F {price = 1400;stock = 2;};
			class NVGogglesB_blk_F {price = 4500;stock = 2;};
			class NVGogglesB_grn_F {price = 4500;stock = 2;};
			class NVGogglesB_gry_F {price = 4500;stock = 2;};
			class NVGoggles_INDEP {price = 1400;stock = 2;};
			class NVGoggles_OPFOR {price = 1400;stock = 2;};
			class O_NVGoggles_grn_F {price = 1400;stock = 2;};
			//RHS
			class rhsusf_Rhino {price = 100;stock = 10;};
			class rhsusf_ANPVS_15 {price = 1400;stock = 10;};
			class rhsusf_ANPVS_14 {price = 1400;stock = 10;};
			class rhs_1PN138 {price = 1000;stock = 10;};
			class rhsusf_bino_m24 {price = 345;stock = 10;};
			class rhsusf_bino_m24_ARD {price = 345;stock = 10;};
			class rhsusf_bino_lrf_Vector21 {price = 600;stock = 10;};
			class rhsusf_bino_lerca_1200_black {price = 500;stock = 10;};
			class rhsusf_bino_lerca_1200_tan {price = 500;stock = 10;};
			class rhsusf_bino_leopold_mk4 {price = 350;stock = 10;};
			class rhs_pdu4 {price = 700;stock = 10;};
			class rhs_radio_R169P1 {price = 200;stock = 25;};
			class rhsusf_radio_anprc152 {price = 200;stock = 25;};
		};

		class Survival {
			displayName = "Выживание / Инструменты";
			picture = "";

			#define HDG_STOCK 20
			//class hgun_Pistol_Signal_F {price = 50;stock = 1;description = "<t size='1' shadow='2'>A flare Gun</t>"};
 		};

		class Moneyitems {
			displayName = "Pre-war Money";
			picture = "";

			class rvg_money {price = 50;stock =0;description = "<t size='1' shadow='2'>Prewar funds that can be sold in bulk for a very nice price...</t>"};
		};

		class Launchers {
			displayName = "Launchers";
			picture = "";

			class rhs_weap_rshg2 {price = 900;stock = 20;};
			class rhs_weap_rpg26 {price = 1300;stock = 20;};
			class rhs_weap_rpg18 {price = 1000;stock = 20;};
			class rhs_weap_rpg7 {price = 1600;stock = 20;};
			class launch_RPG7_F {price = 1600;stock = 20;};
			class rhs_weap_rpg75 {price = 1300;stock = 20;};
			class rhs_weap_m72a7 {price = 1100;stock = 20;};
			class rhs_weap_M136 {price = 1300;stock = 20;};
			class rhs_weap_M136_hedp {price = 1000;stock = 20;};
			class rhs_weap_panzerfaust60 {price = 700;stock = 20;};
			class rhs_weap_M136_hp {price = 1800;stock = 20;};
			class rhs_weap_maaws {price = 2000;stock = 20;};
			class rhs_weap_smaw {price = 2000;stock = 20;};
			class rhs_weap_igla {price = 3300;stock = 5;};
			class rhs_weap_fim92 {price = 3800;stock = 5;};
			class rhs_weap_fgm148 {price = 7000;stock = 2;};
			class launch_O_Vorona_green_F {price = 7000;stock = 2;};
			class launch_O_Vorona_brown_F {price = 7000;stock = 2;};
			class rhs_fgm148_magazine_AT {price = 4000;stock = 3;};
			class rhs_rpg7_PG7V_mag {price = 300;stock = 10;};
			class rhs_rpg7_PG7VM_mag {price = 550;stock = 10;};
			class rhs_rpg7_PG7VS_mag {price = 640;stock = 10;};
			class rhs_rpg7_PG7VL_mag {price = 700;stock = 10;};
			class rhs_rpg7_PG7VR_mag {price = 1200;stock = 5;};
			class rhs_rpg7_TBG7V_mag {price = 800;stock = 5;};
			class rhs_rpg7_OG7V_mag {price = 900;stock = 10;};
			class RPG7_F {price = 550;stock = 10;};
			class rhs_rpg7_type69_airburst_mag {price = 1100;stock = 5;};
			class Vorona_HE {price = 4000;stock = 5;};
 			class Vorona_HEAT {price = 5000;stock = 5;};
 			class rhs_mag_9k38_rocket {price = 3500;stock = 5;};
 			class rhs_mag_9k32_rocket {price = 3500;stock = 5;};
			class rhs_rpg75_mag {price = 1300;stock = 1;};
			class rhs_fim92_mag {price = 3500;stock = 5;};
			class rhs_mag_smaw_HEAA {price = 600;stock = 5;};
			class rhs_mag_smaw_HEDP {price = 400;stock = 10;};
			class rhs_mag_maaws_HEAT {price = 600;stock = 5;};
			class rhs_mag_maaws_HEDP {price = 400;stock = 10;};
			class rhs_mag_maaws_HE {price = 350;stock = 10;};
			class rhs_rshg2_mag {price = 900;stock = 1;};
			class rhs_rpg18_mag {price = 1000;stock = 1;};
			class rhs_rpg26_mag {price = 1300;stock = 1;};
			class rhs_m72a7_mag {price = 1100;stock = 1;};
			class rhs_m136_mag {price = 1300;stock = 1;};
			class rhs_m136_hedp_mag {price = 1000;stock = 1;};
			class rhs_m136_hp_mag {price = 1800;stock = 1;};
			class rhs_panzerfaust60_mag {price = 700;stock = 1;};
 		};
			
		class Explosives {
			displayName = "Гранаты и взрывчатка";
			picture = "";

			//Explosive
			class rhs_grenade_m1939e_mag {price = 150;stock = 25;};
			class rhs_grenade_m1939e_f_mag {price = 150;stock = 25;};
			class rhs_grenade_m15_mag {price = 40;stock = 25;};
			class rhs_GDM40 {price = 70;stock = 20;};
			class rhs_GRD40_Green {price = 70;stock = 20;};
			class rhs_GRD40_Red {price = 70;stock = 20;};
			class rhs_GRD40_White {price = 70;stock = 20;};
			class rhs_VG40OP_green {price = 70;stock = 20;};
			class rhs_VG40OP_red {price = 70;stock = 20;};
			class rhs_VG40OP_white {price = 70;stock = 20;};
			class rhs_VG40TB {price = 350;stock = 20;};
			class rhs_VG40SZ {price = 150;stock = 20;};
			class rhs_VOG25 {price = 200;stock = 20;};
			class rhs_VOG25P {price = 350;stock = 20;};
			class rhs_grenade_mkii_mag {price = 200;stock = 25;};
			class rhs_grenade_nbhgr39_mag {price = 100;stock = 25;};
			class rhs_charge_sb3kg_mag {price = 1000;stock = 25;};
			class rhs_grenade_sthgr24_mag {price = 200;stock = 25;};
			class rhs_grenade_sthgr24_heerfrag_mag {price = 300;stock = 25;};
			class rhs_grenade_sthgr24_SSfrag_mag {price = 300;stock = 25;};
			class rhs_grenade_sthgr24_x7bundle_mag {price = 900;stock = 25;};
			class rhs_grenade_sthgr43_mag {price = 200;stock = 25;};
			class rhs_grenade_sthgr43_heerfrag_mag {price = 300;stock = 25;};
			class rhs_grenade_sthgr43_SSfrag_mag {price = 300;stock = 25;};
			class rhs_charge_tnt_x2_mag {price = 700;stock = 25;};
			class rhs_charge_M2tet_x2_mag {price = 200;stock = 25;};
			class HandGrenade_Stone {price = 5;stock = 20;};
			class HandGrenade {price = 200;stock = 20;};
			class MiniGrenade {price = 25;stock = 20;};
			class SmokeShell {price = 100;stock = 20;};
			class SmokeShellYellow {price = 100;stock = 20;};
			class SmokeShellGreen {price = 100;stock = 20;};
			class SmokeShellRed {price = 100;stock = 20;};
			class SmokeShellPurple {price = 100;stock = 20;};
			class SmokeShellOrange {price = 100;stock = 20;};
			class B_IR_Grenade {price = 350;stock = 20;};
			class O_IR_Grenade {price = 350;stock = 20;};
			class I_IR_Grenade {price = 350;stock = 20;};
			class DemoCharge_Remote_Mag {price = 800;stock = 20;};
			class IEDUrbanSmall_Remote_Mag {price = 500;stock = 20;};
			class IEDLandSmall_Remote_Mag {price = 500;stock = 20;};
			class SatchelCharge_Remote_Mag {price = 2000;stock = 20;};
			class IEDUrbanBig_Remote_Mag {price = 1200;stock = 20;};
			class IEDLandBig_Remote_Mag {price = 1200;stock = 20;};
			class ATMine_Range_Mag {price = 900;stock = 20;};
			class ClaymoreDirectionalMine_Remote_Mag {price = 700;stock = 20;};
			class APERSMine_Range_Mag {price = 500;stock = 20;};
			class APERSMineDispenser_Mag {price = 3000;stock = 20;};
			class APERSBoundingMine_Range_Mag {price = 1000;stock = 20;};
			class SLAMDirectionalMine_Wire_Mag {price = 600;stock = 20;};
			class APERSTripMine_Wire_Mag {price = 500;stock = 20;};
			class rhs_ec75_mag {price = 400;stock = 10;};
			class rhs_ec75_sand_mag {price = 400;stock = 10;};
			class rhs_ec200_mag {price = 1000;stock = 10;};
			class rhs_ec200_sand_mag {price = 1000;stock = 10;};
			class rhs_ec400_mag {price = 2000;stock = 10;};
			class rhs_ec400_sand_mag {price = 2000;stock = 10;};
			//Contact
			class I_E_IR_Grenade {price = 350;stock = 20;};
			class O_R_IR_Grenade {price = 350;stock = 20;};

			//RHS
			class rhs_mag_an_m14_th3 {price = 600;stock = 20;};
			class rhs_mag_m7a3_cs {price = 400;stock = 10;};
			class rhs_mag_rdg2_black {price = 100;stock = 20;};
			class rhs_mag_rdg2_white {price = 100;stock = 20;};
			class rhs_mag_fakel {price = 150;stock = 10;};
			class rhs_mag_fakels {price = 200;stock = 10;};
			class rhs_mag_mk84 {price = 400;stock = 10;};
			class rhs_mag_mk3a2 {price = 100;stock = 10;};
			class rhs_mag_plamyam {price = 300;stock = 10;};
			class rhs_mag_zarya2 {price = 350;stock = 10;};
			class rhs_mag_rgd5 {price = 200;stock = 10;};
			class rhs_mag_rgn {price = 200;stock = 10;};
			class rhs_mag_rgo {price = 200;stock = 10;};
			class rhs_grenade_khattabka_vog17_mag {price = 200;stock = 10;};
			class rhs_grenade_khattabka_vog25_mag {price = 200;stock = 10;};
			class rhs_mag_f1 {price = 250;stock = 10;};
			class rhs_mag_m67 {price = 250;stock = 10;};
			class rhsusf_m112x4_mag {price = 2000;stock = 10;};
			class rhsusf_m112_mag {price = 500;stock = 10;};
		};

		class Medical {
			displayName = "Медицина";
			picture = "";
			//ACE medical items:
			class ACE_bloodIV_250 {price=500;stock=25;};
			class ACE_plasmaIV_250 {price=500;stock=25;};
			class ACE_salineIV_250 {price=500;stock=25;};
			class ACE_splint {price=300;stock=25;};
			class ACE_fieldDressing {price=400;stock=25;};
			class ACE_elasticBandage {price=450;stock=25;};
		};

		class MedicalS {
			displayName = "Спец.медицина";
			picture = "";
			//ACE medical items:
			class ACE_bloodIV {price=1000;stock=25;};
			class ACE_bloodIV_500 {price=750;stock=25;};
			class ACE_bodyBag {price=200;stock=25;};
			class ACE_epinephrine {price=800;stock=25;};
			class ACE_morphine {price=600;stock=25;};
			class ACE_personalAidKit {price=4000;stock=25;};
			class ACE_plasmaIV {price=1000;stock=25;};
			class ACE_plasmaIV_500 {price=750;stock=25;};
			class ACE_salineIV {price=1000;stock=25;};
			class ACE_salineIV_500 {price=750;stock=25;};
			class ACE_surgicalKit {price=600;stock=25;};
			class ACE_tourniquet {price=200;stock=25;};
			class ACE_packingBandage {price=500;stock=25;};
			class ACE_quikclot {price=600;stock=25;};
			class ACE_adenosine {price=1000;stock=25;};
			class rvg_antiRad {price=2500;stock = 25;};
			class rvg_purificationTablets {price=4000;stock = 25;};
		};

		class Food {
			displayName = "Еда и вода";
			picture = "";
 
			class aq_item_food_banana  {price=250; stock=25;};
            class aq_item_food_apple   {price=170; stock=25;};
            class aq_item_food_mre1    {price=1000; stock=25;};
            class aq_item_food_water1  {price=850; stock=25;};
            class aq_item_food_energy1 {price=1900; stock=25;};
		};

		class Tobacco {
			displayName = "Тобак";
			picture = "";

			//class Misery_cigar {price=850;stock = 25;description = "<t size='1' shadow='2'>A rolled Cigar, a Luxury item in Chernarus.</t>"};
		};

		class Alcohol {
			displayName = "Алкоголь";
			picture = "";
			
			//class Misery_wolfbeer {price=500;stock = 25;};
		};

		class Narcotics {
			displayName = "Наркотики";
			picture = "";
			//class	Misery_cocaine {price=4500;stock = 25;};
		};

		class Gasmasks {
			displayName = "Противогазы";
			picture = "";

			class Mask_M40_OD {price = 700;stock = 5;};
			class Mask_M50 {price = 700;stock = 5;};
			class Mask_M40 {price = 700;stock = 5;};
			class G_AirPurifyingRespirator_01_F {price = 700;stock = 5;};
			class G_AirPurifyingRespirator_02_black_F {price = 700;stock = 5;};
			class G_AirPurifyingRespirator_02_olive_F {price = 700;stock = 5;};
			class G_AirPurifyingRespirator_02_sand_F {price = 700;stock = 5;};
			class G_RegulatorMask_F {price = 700;stock = 5;};
		};

		class CBRN {
			displayName = "Спец.костюмы";
			picture = "";

			class U_I_Wetsuit_rvg {price = 7000;stock = 5;};
			class U_O_Wetsuit_rvg {price = 7000;stock = 5;};
			class U_B_Wetsuit_rvg {price = 7000;stock = 5;};
			class U_B_CBRN_Suit_01_MTP_F {price = 7000;stock = 5;};
			class U_B_CBRN_Suit_01_Tropic_F {price = 7000;stock = 5;};
			class U_B_CBRN_Suit_01_Wdl_F {price = 7000;stock = 5;};
			class U_I_CBRN_Suit_01_AAF_F {price = 7000;stock = 5;};
			class U_I_E_CBRN_Suit_01_EAF_F {price = 7000;stock = 5;};
			class U_C_CBRN_Suit_01_Blue_F {price = 7000;stock = 5;};
			class U_C_CBRN_Suit_01_White_F {price = 7000;stock = 5;};
		};

		class Rebreathers {
			displayName = "Ребризеры";
			picture = "";

			class V_O2Tank {price = 8000;stock = 5;};
			class V_O2Tank_1 {price = 8000;stock = 5;};
		};
	};

	class stores {
		class VendorFood {
			displayName = "Продавец провизии";
			categories[] = {"Food"};
		};

		class VendorWeapon_T1 {
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_T1";
			categories[] = {
			"Weapons_Pistols_T1","Weapons_Shotguns_T1","Weapons_SubmachineGuns_T1","Weapons_MachineGun_T1","Weapons_Rifle_T1","Weapons_Sniper_T1","Weapons_Launchers_T1"
			};
		};

		class VendorWeapon_T2 {
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_T2";
			categories[] = {
			"Weapons_Pistols_T2","Weapons_SubmachineGuns_T2","Weapons_MachineGun_T2","Weapons_Rifle_T2","Weapons_Sniper_T2","Weapons_Launchers_T2"
			};
		};

		class VendorWeapon_T3 {
			displayName = "$STR_AQ_STORE_VENDOR_WEAPON_T3";
			categories[] = {
			"Weapons_Pistols_T3","Weapons_SubmachineGuns_T3","Weapons_MachineGun_T3","Weapons_Rifle_T3","Weapons_Sniper_T3","Weapons_Launchers_T3"
			};
		};
	};
};
