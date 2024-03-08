Purchases["late.usa"] = {
	{Repeat = 0,  --infinite
		Units = { 
		
		-- All-round Doctrine Squads
		{priority = 1.0, type = {"Class3", "Infantry", "Squad",}, unit = "squad_cav_late_all_1(usa)"},
		{priority = 1.0, type = {"Class3", "Infantry", "Squad",}, unit = "squad_mp_late_all(usa)"},
		{priority = 1.0, type = {"Class2", "Infantry", "Squad",}, unit = "squad_arm_rifle_late_off_1(usa)"},
		
		{priority = 1.0, type = {"Class2", "Infantry", "Squad",}, unit = "squad_rifle(usa)"},
		{priority = 1.0, type = {"Class2", "Infantry", "Squad",}, unit = "squad_rifle_assault(usa)"},
		{priority = 1.0, type = {"Class2", "Infantry", "Squad",}, unit = "squad_rifle_bar(usa)"},
		{priority = 1.0, type = {"Class2", "Infantry", "Squad",}, unit = "squad_arm_rifle_mech_late_off_1(usa)"},
		{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_eng_late_def_1(usa)"},
		
		{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_101st_glider_late_def_1(usa)"},
		{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_10th_mountain_late_off_1(usa)"},
		{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_vet_rifle_late_def_1(usa)"},
		{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_1st_arm_rifle_late_off_1(usa)"},
		--{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_1st_rifle_late_all_1(usa)"},
		--{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_82nd_glider_late_irr_1(usa)"},
		{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_ranger_assault_sub_late_all(usa)"},
		{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_ranger_assault_late_all(usa)"},
		{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_ranger_special_late_all(usa)"},
		{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_101st_late_def_1(usa)"},
		{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_101st_eng_late_def(usa)"},
		{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_82nd_late_irr_1(usa)"},
		{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_82nd_demo_late_irr(usa)"},


			-- Infantry Singles / Teams
				---[[
				{priority = 1.0, type = {"Class3", "Infantry", "Team", "Aux",}, unit = "single_rifle(usa)"},
				{priority = 1.0, type = {"Class3", "Infantry", "Team", "Aux",}, unit = "single_smg(usa)"},
				{priority = 1.0, type = {"Class1", "Infantry", "Team",}, unit = "single_mg(usa)"},
				{priority = 1.0, type = {"Class3", "Infantry", "Team", "AT",}, unit = "single_at(usa)"},
				{priority = 1.0, type = {"Class3", "Infantry", "Team",}, unit = "single_riflegrenade(usa)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_ap_miner(usa)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_at_miner(usa)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_engineer(usa)"},
				{priority = 1.0, type = {"Class3", "Infantry", "Team",}, unit = "single_flamer(usa)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_tankman(usa)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_medic(usa)"},
				{priority = 1.0, type = {"Class2", "Infantry", "Team",}, unit = "single_sniper(usa)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_officer(usa)"},
				--]]

			-- Cannons
				---[[
				--{priority = 1.0, type = {"Cannon", "Supply", "Ammo",}, unit = "inf_crate_usa"},

				--{priority = 1.0, type = {"Class2", "Cannon", "MG",}, unit = "m1917_30cal"},
				{priority = 1.0, type = {"Class2", "Cannon", "MG",}, unit = "m2_30cal_tripod"},
				{priority = 1.0, type = {"Class2", "Cannon", "MG",}, unit = "m2_50cal_tripod"},
				{priority = 1.0, type = {"Class2", "Cannon", "AA",}, unit = "50cal_quad_m45"},

				{priority = 1.0, type = {"Class3", "Cannon", "AT",}, unit = "37mm_m3a1"},
				{priority = 1.0, type = {"Class2", "Cannon", "AT",}, unit = "57mm_m1"},
				{priority = 1.0, type = {"Class2", "Cannon", "AT",}, unit = "76mm_m5_m6"},

				--{priority = 1.0, type = {"Class1", "Cannon", "Support",}, unit = "75mm_m3a3"},
				{priority = 1.0, type = {"Class3", "Cannon", "Mortar",}, unit = "60mm_m2_late"},
				{priority = 1.0, type = {"Class2", "Cannon", "Mortar",}, unit = "81mm_m1"},
				{priority = 1.0, type = {"Class3", "Cannon", "Artillery",}, unit = "105mm_m2a1"},
				--]]

			-- Wheeled vehicles
				---[[
				{priority = 1.0, type = {"Class3", "Vehicle", "MG",}, unit = "willys_mb_30cal"},
				{priority = 1.0, type = {"Class3", "Vehicle", "MG",}, unit = "m3a1_scout"},
				{priority = 1.0, type = {"Class2", "Vehicle", "MG",}, unit = "m20"},
				{priority = 1.0, type = {"Class1", "Vehicle", "AT",}, unit = "m8_greyhound"},

				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Transport",}, unit = "willys_mb"},
				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Transport",}, unit = "wc51"},
				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Transport",}, unit = "cckw"},
				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Transport",}, unit = "m3a1_transport"},
				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Supply", "Ammo",}, unit = "cckw_art_ammo"},
				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Supply", "Fuel",}, unit = "cckw_fuel"},
				--{priority = 1.0, type = {"Class", "Vehicle", "MG", "Supply", "Engineer",}, unit = "cckw_engineer_late"},
				--]]

			-- Half Tracks
				---[[
				--{priority = 1.0, type = {"Class3", "Armored", "MG", "Transport",}, unit = "m5_hst"},
				{priority = 1.0, type = {"Class3", "Armored", "MG", "Transport",}, unit = "m2_halftrack"},
				{priority = 1.0, type = {"Class3", "Armored", "MG", "Transport",}, unit = "m3a1_halftrack"},
				{priority = 1.0, type = {"Class3", "Armored", "MG", "Transport",}, unit = "lvt4"},
				{priority = 1.0, type = {"Class2", "Armored", "AA",}, unit = "m13_mgmc"},
				--]]

			-- Tanks
				---[[
				{priority = 1.0, type = {"Class2", "Tank", "Light",}, unit = "m5a1_stuart"},
				{priority = 1.0, type = {"Class1", "Tank", "Light",}, unit = "m24_chaffee"},

				--{priority = 1.0, type = {"Class2", "Tank", "Medium",}, unit = "m4_75_late"},
				{priority = 1.0, type = {"Class3", "Tank", "Medium",}, unit = "m4a1_75_late"},
				{priority = 1.0, type = {"Class2", "Tank", "Medium",}, unit = "m4a3_75_late"},
				--{priority = 1.0, type = {"Class1", "Tank", "Medium",}, unit = "m4a3_75w_early"},
				--{priority = 1.0, type = {"Class3", "Tank", "Medium",}, unit = "m4a1_76w_mid"},
				--{priority = 1.0, type = {"Class2", "Tank", "Medium",}, unit = "m4a3_76w"},
				{priority = 1.0, type = {"Class1", "Tank", "Medium",}, unit = "m4a3_76w_hvss"},
				{priority = 1.0, type = {"Class2", "Tank", "Medium",}, unit = "m4a3e2_75"},
				{priority = 1.0, type = {"Class1", "Tank", "Medium",}, unit = "m4a3e2_76"},
				--]]

			-- Self-Propelled Guns
				---[[
				{priority = 1.0, type = {"Class2", "Tank", "Light", "AT",}, unit = "m18_hellcat_late"},
				{priority = 1.0, type = {"Class3", "Tank", "Medium", "AT",}, unit = "m10_gmc_late"},
				{priority = 1.0, type = {"Class1", "Tank", "Medium", "AT",}, unit = "m36_gmc_late"},
				--{priority = 1.0, type = {"Class1", "Tank", "Medium", "AT",}, unit = "m36b1_gmc_late"},
				--{priority = 1.0, type = {"Class2", "Tank", "Medium", "Support",}, unit = "m4_105"},
				--{priority = 1.0, type = {"Class1", "Tank", "Medium", "Support",}, unit = "m4a3_105"},
				--]]


			-- Doctrine Point Units 
				
				--  All-round Doctrine
					---[[
					{priority = 1.0, type = {"Class2","Armored", "AA",}, unit = "m16_mgmc"},
					--{priority = 1.0, type = {"Class3", "Doctrine", "Tier1", "Armored", "Mortar",}, unit = "doctrine_m4a1_mortar_carrier_late"},
					--{priority = 1.0, type = {"Class2", "Cannon", "Support",}, unit = "75mm_m3a3"},

					{priority = 1.0, type = {"Class2", "Tank", "Medium", "Support",}, unit = "m4a3_105_hvss"},
					--{priority = 1.0, type = {"Class", "Doctrine", "Tier2", "Infantry", "Team",}, unit = "doctrine_squad_usa_signaller_155_late(usa)"},
					{priority = 1.0, type = {"Class1", "Tank", "Medium", "Artillery",}, unit = "m7b1_hmc"},
					
					--{priority = 1.0, type = {"Class", "Doctrine", "Tier3", "Infantry", "Team",}, unit = "doctrine_squad_usa_signaller_240_late(usa)"},
					{priority = 1.0, type = {"Class1", "Tank", "Heavy",}, unit = "m26_pershing"},
					{priority = 1.0, type = {"Class2", "Tank", "Medium", "Artillery",}, unit = "m12_gmc"},
					--]]

				--  Defensive Doctrine
					---[[
					--{priority = 1.0, type = {"Class", "Doctrine", "Tier1", "Vehicle", "MG", "Support", "Engineer",}, unit = "doctrine_cckw_engineer_late"},
					{priority = 1.0, type = {"Class3", "Cannon", "AA",}, unit = "40mm_m1"},
					{priority = 1.0, type = {"Class2", "Armored", "AT",}, unit = "m3a1_gmc"},
					
					{priority = 1.0, type = {"Class2", "Cannon", "Mortar",}, unit = "107mm_m2"},
					{priority = 1.0, type = {"Class1", "Cannon", "AA", "AT",}, unit = "90mm_m1a1"},
					{priority = 1.0, type = {"Class3", "Armored", "Artillery",}, unit = "t19_hmc"},
					
					{priority = 1.0, type = {"Class1", "Tank", "Medium", "AT",}, unit = "m36b1_gmc_t33"},
					{priority = 1.0, type = {"Class3", "Cannon", "Artillery",}, unit = "203mm_m1"},
					{priority = 1.0, type = {"Class1", "Cannon", "Artillery", "AT",}, unit = "155mm_m1a1_longtom"},
					--]]

				--  Irregular Doctrine
					---[[
					--{priority = 1.0, type = {"Class3", "Tier1", "Infantry",}, unit = "doctrine_squad_1st_special_late(usa)"},
					{priority = 1.0, type = {"Class2", "Cannon", "Support",}, unit = "75mm_m1a1"},
					--{priority = 1.0, type = {"Class3", "Doctrine", "Tier1", "Vehicle", "MG", "Supply", "Ammo",}, unit = "doctrine_cckw_redball_late"},
					
					--{priority = 1.0, type = {"Class", "Doctrine", "Tier2", "Plane", "Airstrike",}, unit = "doctrine_p47_250_late"},
					{priority = 1.0, type = {"Class1", "Tank", "Medium", "AT",}, unit = "m4a3_75w_e4_5"},
					{priority = 1.0, type = {"Class2", "Cannon", "Artillery",}, unit = "105mm_m3"},

					--{priority = 1.0, type = {"Class", "Doctrine", "Tier3", "Plane", "Airstrike",}, unit = "doctrine_p47_500_late"},
					{priority = 1.0, type = {"Class3", "Cannon", "Artillery",}, unit = "114mm_m1"},
					{priority = 1.0, type = {"Class1", "Tank", "Medium", "Artillery",}, unit = "m4a3_calliope"},
					--]]

				--  Offensive Doctrine
					---[[
					{priority = 1.0, type = {"Class3", "Armored", "MG",}, unit = "m3a1_commander"},
					{priority = 1.0, type = {"Class2", "Armored", "AA",}, unit = "m15a1_cgmc"},
					{priority = 1.0, type = {"Class1", "Tank", "Light", "Support",}, unit = "m8_hmc"},

					{priority = 1.0, type = {"Class3", "Tank", "Light", "AT",}, unit = "m18_hellcat_late"},
					{priority = 1.0, type = {"Class2", "Tank", "Medium",}, unit = "m4a3_76w_field3"},
					--{priority = 1.0, type = {"Class", "Doctrine", "Tier2", "Infantry", "Team",}, unit = "doctrine_squad_usa_signaller_155_vt_late(usa)"},
					
					--{priority = 1.0, type = {"Class", "Doctrine", "Tier3", "Infantry", "Team",}, unit = "doctrine_squad_usa_signaller_203_vt_late(usa)"},
					{priority = 1.0, type = {"Class3", "Cannon", "Artillery",}, unit = "155mm_m1"},
					{priority = 1.0, type = {"Class1", "Tank", "Heavy",}, unit = "t26e4"},
					--]]
		}
	}
}