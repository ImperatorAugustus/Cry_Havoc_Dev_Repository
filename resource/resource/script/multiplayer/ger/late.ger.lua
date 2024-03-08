Purchases["late.ger"] = {
	{Repeat = 0,  --infinite
		Units = { 
				-- Old Squads
				{priority = 1.0, type = {"Class3", "Infantry", "Squad",}, unit = "squad_lw_fusilier_late(ger)"},
				{priority = 1.0, type = {"Class2", "Infantry", "Squad",}, unit = "squad_recon_late(ger)"},
				{priority = 1.0, type = {"Class2", "Infantry", "Squad",}, unit = "squad_grenadiere_late(ger)"},
				{priority = 1.0, type = {"Class2", "Infantry", "Squad",}, unit = "squad_pionier_late(ger)"},
				{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_pzgrenadiere_late(ger)"},
				{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_jager_late(ger)"},
				{priority = 1.0, type = {"Class3", "Infantry", "Squad",}, unit = "squad_fusilier_late(ger)"},
				{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_gebirgsjaeger_late(ger)"},
				{priority = 1.0, type = {"Class3", "Infantry", "Squad",}, unit = "squad_pzgrenadiere_gd_late(ger)"},
				--]]
			-- Infantry Singles / Teams
				---[[
				{priority = 1.0, type = {"Class3", "Infantry", "Team", "Aux",}, unit = "single_rifle(ger)"},
				{priority = 1.0, type = {"Class3", "Infantry", "Team", "Aux",}, unit = "single_smg(ger)"},
				{priority = 1.0, type = {"Class3", "Infantry", "Team", "Aux",}, unit = "single_sa(ger)"},
				{priority = 1.0, type = {"Class1", "Infantry", "Team",}, unit = "single_mg(ger)"},
				{priority = 1.0, type = {"Class1", "Infantry", "Team", "AT",}, unit = "single_bazooker(ger)"},
				{priority = 1.0, type = {"Class3", "Infantry", "Team",}, unit = "single_riflegrenade(ger)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_ap_miner(ger)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_at_miner(ger)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_engineer(ger)"},
				{priority = 1.0, type = {"Class3", "Infantry", "Team",}, unit = "single_flamer(ger)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_tankman(ger)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_medic(ger)"},
				{priority = 1.0, type = {"Class2", "Infantry", "Team",}, unit = "single_sniper(ger)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_officer(ger)"},
				--]]

			-- Cannons
				---[[
				--{priority = 1.0, type = {"Cannon", "Supply", "Ammo",}, unit = "inf_crate_ger"},

				{priority = 1.0, type = {"Class2", "Cannon", "MG",}, unit = "mg42_lafette"},
				{priority = 1.0, type = {"Class2", "Cannon", "AA",}, unit = "20mm_flak30"},

				{priority = 1.0, type = {"Class3", "Cannon", "AT",}, unit = "28mm_pzb41"},
				{priority = 1.0, type = {"Class2", "Cannon", "AT",}, unit = "37mm_pak36_late"},
				{priority = 1.0, type = {"Class3", "Cannon", "AT",}, unit = "50mm_pak38_late"},
				{priority = 1.0, type = {"Class1", "Cannon", "AT",}, unit = "75mm_pak40"},

				{priority = 1.0, type = {"Class1", "Cannon", "Support",}, unit = "75mm_leig18"},
				{priority = 1.0, type = {"Class1", "Cannon", "Mortar",}, unit = "80mm_sgrw34"},
				{priority = 1.0, type = {"Class3", "Cannon", "Artillery",}, unit = "105mm_lefh18"},
				--]]

			-- Wheeled vehicles
				---[[
				{priority = 1.0, type = {"Class3", "Vehicle", "MG",}, unit = "bmw_r71"},
				{priority = 1.0, type = {"Class3", "Vehicle", "MG",}, unit = "kubelwagen_mg"},
				{priority = 1.0, type = {"Class1", "Vehicle", "AA",}, unit = "blitz3_6_flak30"},

				{priority = 1.0, type = {"Class2", "Armored", "MG",}, unit = "sdkfz221"},
				{priority = 1.0, type = {"Class3", "Armored", "AA",}, unit = "sdkfz222a"},
				{priority = 1.0, type = {"Class1", "Armored", "AA",}, unit = "sdkfz231"},

				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Transport",}, unit = "blitz3_6"},
				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Supply", "Ammo",}, unit = "blitz3_6_art_ammo"},
				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Supply", "Fuel",}, unit = "blitz3_6_fuel"},
				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Supply", "Engineer",}, unit = "blitz3_6_engineering"},
				--]]

			-- Half Tracks
				---[[
				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Transport",}, unit = "kettenkrad"},
				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Transport",}, unit = "sdkfz10"},
				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Transport",}, unit = "sdkfz7"},
				{priority = 1.0, type = {"Class3", "Armored", "MG", "Transport",}, unit = "sdkfz251d_1"},
				--]]

			-- Tanks
				---[[
				{priority = 1.0, type = {"Class3", "Tank", "Medium",}, unit = "panzer3m"}, -- long 50mm
				{priority = 1.0, type = {"Class2", "Tank", "Medium",}, unit = "panzer3n"}, -- short 75mm
				{priority = 1.0, type = {"Class3", "Tank", "Medium",}, unit = "panzer4g"},
				{priority = 1.0, type = {"Class2", "Tank", "Medium",}, unit = "panzer4h"},
				{priority = 1.0, type = {"Class3", "Tank", "Medium",}, unit = "panzer5a"},

				--{priority = 1.0, type = {"Class2", "Tank", "Heavy",}, unit = "tiger1e_ss"},
				--]]

			-- Self-Propelled Guns
				---[[
				{priority = 1.0, type = {"Class3", "Tank", "Light", "AT",}, unit = "marder3m"},
				{priority = 1.0, type = {"Class2", "Tank", "Light", "AT",}, unit = "hetzer"},
				{priority = 1.0, type = {"Class2", "Tank", "Medium", "AT",}, unit = "stug3g_late"},
				{priority = 1.0, type = {"Class2", "Tank", "Medium", "AT",}, unit = "panzer4_70_v"},
				{priority = 1.0, type = {"Class3", "Tank", "Medium", "AT",}, unit = "stuh42"},
				--]]


			-- Doctrine Point Units 
				
				--  All-round Doctrine
					---[[
					--{priority = 1.0, type = {"Class3", "Tier1", "Infantry",}, unit = "doctrine_squad_volksgrenadieredetach(ger)"},
					{priority = 1.0, type = {"Class2", "Armored", "AA",}, unit = "sdkfz234_1"},
					{priority = 1.0, type = {"Class1", "Armored", "AA",}, unit = "sdkfz234_2"},

					--{priority = 1.0, type = {"Class", "Doctrine", "Tier2", "Infantry",}, unit = "doctrine_squad_ger_signaller_late(ger)"},
					{priority = 1.0, type = {"Class2", "Cannon", "Mortar",}, unit = "200mm_ldgw40"},
					{priority = 1.0, type = {"Class1", "Tank", "Medium", "AT",}, unit = "jagdpanzer4_l48"},

					{priority = 1.0, type = {"Class3", "Cannon", "Artillery",}, unit = "105mm_sk18"},
					{priority = 1.0, type = {"Class2", "Armored", "Artillery",}, unit = "sdkfz251d_1_stuka"},
					{priority = 1.0, type = {"Class1", "Tank", "Medium", "AT",}, unit = "jagdpanther"},
					--]]

				--  Defensive Doctrine
					---[[
					--{priority = 1.0, type = {"Class", "Doctrine", "Tier1", "Vehicle", "Unarmed", "Support", "Engineer",}, unit = "doctrine_kettenkrad_goliath_late"},
					{priority = 1.0, type = {"Class2", "Cannon", "AA",}, unit = "37mm_flak37"},
					--{priority = 1.0, type = {"Class1", "Cannon", "Support",}, unit = "75mm_legebig18"},

					{priority = 1.0, type = {"Class2", "Cannon", "Mortar",}, unit = "120mm_sgrw42"},
					{priority = 1.0, type = {"Class1", "Cannon", "AA", "AT",}, unit = "88mm_flak36"},
					{priority = 1.0, type = {"Class2", "Tank", "Medium", "AT",}, unit = "jagdpanzer4_l48_early"},

					{priority = 1.0, type = {"Class2", "Cannon", "Artillery",}, unit = "150mm_sfh18"},
					{priority = 1.0, type = {"Class2", "Cannon", "Artillery",}, unit = "150mm_nebelwerfer41"},
					--{priority = 1.0, type = {"Class1", "Tier3", "Tank", "Heavy", "AT",}, unit = "ferdinand_ss"},
					--]]

				--  Irregular Doctrine
					--[[
					--{priority = 1.0, type = {"Class3", "Tier1", "Infantry",}, unit = "doctrine_squad_brandenburger_late(ger)"},
					{priority = 1.0, type = {"Class2", "Tank", "Light",}, unit = "panzer1f"},
					{priority = 1.0, type = {"Class1", "Tank", "Medium",}, unit = "panzer3_flamm"},

					--{priority = 1.0, type = {"Class", "Doctrine", "Tier2", "Plane", "Airstrike",}, unit = "doctrine_bf109_late"},
					{priority = 1.0, type = {"Class1", "Cannon", "Support",}, unit = "150mm_sig33_late"},
					{priority = 1.0, type = {"Class2", "Tank", "Medium",}, unit = "panzer4j"},

					--{priority = 1.0, type = {"Class", "Doctrine", "Tier3", "Plane", "Airstrike",}, unit = "doctrine_bf110_late"},
					{priority = 1.0, type = {"Class2", "Cannon", "Artillery",}, unit = "300mm_nebelwerfer42"},
					{priority = 1.0, type = {"Class1", "Tank", "Heavy",}, unit = "tiger1hunt_ss"},
					--]]

				--  Offensive Doctrine
					--[[
					{priority = 1.0, type = {"Class3", "Armored", "MG",}, unit = "sdkfz250a_3"},
					{priority = 1.0, type = {"Class2", "Tank", "Light",}, unit = "panzer2l"},
					{priority = 1.0, type = {"Class2", "Tank", "Light", "AA",}, unit = "grille_m_ss"},

					--{priority = 1.0, type = {"Class3", "Tier2", "Infantry", "Tank", "Medium", "AT",}, unit = "doctrine_sturmartillerie_unit"},
					{priority = 1.0, type = {"Class2", "Tank", "Medium",}, unit = "sturmpanzer4"},
					{priority = 1.0, type = {"Class2", "Tank", "Light", "Artillery",}, unit = "wespe"},

					{priority = 1.0, type = {"Class2", "Tank", "Medium",}, unit = "panzer5g"},
					{priority = 1.0, type = {"Class3", "Tank", "Heavy",}, unit = "sturmtiger_ss"},
					{priority = 1.0, type = {"Class1", "Tank", "Heavy",}, unit = "tiger2h_ss"},
					--]]

				--  Support Doctrine
					--[[
					--{priority = 1.0, type = {"Class", "Doctrine", "Tier1", "Infantry", "Team",}, unit = "doctrine_squad_ger_officer_lw_late(ger)"},
					{priority = 1.0, type = {"Class2", "Tank", "Medium", "AA",}, unit = "wirbelwind"},
					{priority = 1.0, type = {"Class3", "Tank", "Medium", "AA",}, unit = "ostwind"},
					{priority = 1.0, type = {"Class2", "Armored", "AT",}, unit = "sdkfz234_3"},

					--{priority = 1.0, type = {"Class", "Doctrine", "Tier2", "Plane", "Recon",}, unit = "doctrine_fi156_late"},
					{priority = 1.0, type = {"Class3", "Armored", "AT",}, unit = "sdkfz234_4"},
					{priority = 1.0, type = {"Class2", "Tank", "Light", "Artillery",}, unit = "grille_k"},

					{priority = 1.0, type = {"Class2", "Cannon", "AT",}, unit = "88mm_pak4341"},
					{priority = 1.0, type = {"Class3", "Cannon", "Artillery",}, unit = "170mm_k18_ss"},
					{priority = 1.0, type = {"Class1", "Cannon", "Artillery",}, unit = "600mm_thor"},
					{priority = 1.0, type = {"Class1", "Tank", "Heavy", "AT",}, unit = "jagdtiger_ss"},
					--]]

				--  All-Round 2 (WEST) Doctrine
					--[[
					{priority = 1.0, type = {"Class2", "Armored", "AA",}, unit = "sdkfz251d_17"},
					{priority = 1.0, type = {"Class2", "Armored", "AA",}, unit = "sdkfz251d_21"},
					{priority = 1.0, type = {"Class3", "Armored", "MG",}, unit = "sdkfz251d_16"},
					
					{priority = 1.0, type = {"Class2", "Armored", "AT",}, unit = "sdkfz251d_22"},
					--{priority = 1.0, type = {"Class", "Doctrine", "Tier2", "Infantry",}, unit = "doctrine_squad_ger_signaller_2_late(ger)"},

					{priority = 1.0, type = {"Class2", "Tank", "Medium", "AT",}, unit = "nashorn"},
					{priority = 1.0, type = {"Class1", "Tank", "Medium", "Artillery",}, unit = "hummel"},
					{priority = 1.0, type = {"Class2", "Armored", "Artillery",}, unit = "panzerwerfer42"},
					--{priority = 1.0, type = {"Class1", "Tank", "Heavy",}, unit = "tiger2p_ss"},
					--]]
		
		}
	}
}