Purchases["late.rus"] = {
	{Repeat = 0,  --infinite
		Units = { 
		-- Infantry Squads
				---[[
				-- Old Squads
				{priority = 1.0, type = {"Class3", "Infantry", "Squad",}, unit = "squad_conscripts_late(rus)"},
				{priority = 1.0, type = {"Class3", "Infantry", "Squad",}, unit = "squad_partisan(rus)"},
				{priority = 1.0, type = {"Class2", "Infantry", "Squad",}, unit = "squad_recon_late(rus)"},
				{priority = 1.0, type = {"Class2", "Infantry", "Squad",}, unit = "squad_rifleunit(rus)"},
				{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_smg(rus)"},
				--{priority = 1.0, type = {"Class3", "Infantry", "Squad", "AT",}, unit = "squad_at_rifle(rus)"},
				{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_guardsrifle(rus)"},
				--{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_guards_smg_heavy(rus)"},
				{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_marines_late(rus)"},
				--]]
			-- Infantry Singles / Teams
				---[[
				{priority = 1.0, type = {"Class3", "Infantry", "Team", "Aux",}, unit = "single_rifle(rus)"},
				{priority = 1.0, type = {"Class3", "Infantry", "Team", "Aux",}, unit = "single_smg(rus)"},
				{priority = 1.0, type = {"Class3", "Infantry", "Team", "Aux",}, unit = "single_sa(rus)"},
				{priority = 1.0, type = {"Class2", "Infantry", "Team",}, unit = "single_mg(rus)"},
				{priority = 1.0, type = {"Class1", "Infantry", "Team", "AT",}, unit = "single_at(rus)"},
				{priority = 1.0, type = {"Class2", "Infantry", "Team", "AT",}, unit = "single_bazooker(rus)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_ap_miner(rus)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_at_miner(rus)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_engineer(rus)"},
				{priority = 1.0, type = {"Class3", "Infantry", "Team",}, unit = "single_flamer(rus)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_tankman(rus)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_medic(rus)"},
				{priority = 1.0, type = {"Class2", "Infantry", "Team",}, unit = "single_sniper(rus)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_officer(rus)"},
				--]]

			-- Cannons
				---[[
				--{priority = 1.0, type = {"Class", "Cannon", "Supply", "Ammo",}, unit = "inf_crate_rus"},

				{priority = 1.0, type = {"Class2", "Cannon", "MG",}, unit = "sg43_stand"},
				{priority = 1.0, type = {"Class2", "Cannon", "MG",}, unit = "dshk_stan"},
				{priority = 1.0, type = {"Class2", "Cannon", "AA",}, unit = "25mm_72k"},

				{priority = 1.0, type = {"Class3", "Cannon", "AT",}, unit = "45mm_m42"},
				{priority = 1.0, type = {"Class2", "Cannon", "AT",}, unit = "76mm_zis3"},
				{priority = 1.0, type = {"Class1", "Cannon", "AT",}, unit = "57mm_zis2_late"},

				{priority = 1.0, type = {"Class1", "Cannon", "Support",}, unit = "76mm_m1927_late"},
				{priority = 1.0, type = {"Class1", "Cannon", "Mortar",}, unit = "82mm_bm37"},
				{priority = 1.0, type = {"Class3", "Cannon", "Artillery",}, unit = "122mm_m30"},
				--]]

			-- Wheeled vehicles
				---[[
				{priority = 1.0, type = {"Class3", "Vehicle", "MG",}, unit = "m72"},
				{priority = 1.0, type = {"Class3", "Vehicle", "MG",}, unit = "gaz67b"},
				{priority = 1.0, type = {"Class2", "Vehicle", "AA",}, unit = "zis5_dshk"},
				{priority = 1.0, type = {"Class1", "Vehicle", "AA",}, unit = "gaz_aaa_72k"},

				{priority = 1.0, type = {"Class2", "Armored", "MG",}, unit = "ba64"},
				{priority = 1.0, type = {"Class3", "Armored",}, unit = "ba10"},

				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Transport",}, unit = "zis5"},
				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Transport",}, unit = "gaz_aaa"},
				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Supply", "Ammo",}, unit = "gaz_aaa_supply"},
				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Supply", "Fuel",}, unit = "gaz_fuel"},
				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Supply", "Engineer",}, unit = "zis5eng"},
				--]]

			-- Tankettes
				---[[
				{priority = 1.0, type = {"Class3", "Armored", "MG",}, unit = "t20"},
				--]]

			-- Tanks
				---[[
				{priority = 1.0, type = {"Class3", "Tank", "Light",}, unit = "t70"},

				{priority = 1.0, type = {"Class2", "Tank", "Medium",}, unit = "t3476_43"},
				{priority = 1.0, type = {"Class1", "Tank", "Medium",}, unit = "t3485_44"},

				{priority = 1.0, type = {"Class3", "Tank", "Heavy",}, unit = "kv1s"},
				{priority = 1.0, type = {"Class3", "Tank", "Heavy",}, unit = "kv1_42"},
				{priority = 1.0, type = {"Class2", "Tank", "Heavy",}, unit = "is1_43"},
				{priority = 1.0, type = {"Class3", "Tank", "Heavy",}, unit = "is2_43"},
				--]]

			-- Self-Propelled Guns
				---[[
				{priority = 1.0, type = {"Class3", "Tank", "Light", "Support",}, unit = "su76"},
				{priority = 1.0, type = {"Class2", "Tank", "Medium", "AT",}, unit = "su85"},
				{priority = 1.0, type = {"Class3", "Tank", "Medium", "Support",}, unit = "su122"},
				{priority = 1.0, type = {"Class2", "Tank", "Heavy", "AT",}, unit = "su152"},
				--]]


			-- Doctrine Point Units 

				--  All-round Doctrine
					---[[
					{priority = 1.0, type = {"Class3", "Armored", "MG",}, unit = "ba20_command"},
					{priority = 1.0, type = {"Class2", "Tank", "Light",}, unit = "t60"},
					{priority = 1.0, type = {"Class1", "Tank", "Light",}, unit = "t70m"},

					--{priority = 1.0, type = {"Class", "Doctrine", "Tier2", "Infantry",}, unit = "doctrine_squad_rus_signaller_late(rus)"},
					{priority = 1.0, type = {"Class2", "Tank", "Light", "Artillery",}, unit = "t60_bm8_24"},
					{priority = 1.0, type = {"Class2", "Tank", "Heavy",}, unit = "kv85"},
													  
					{priority = 1.0, type = {"Class2", "Cannon", "Artillery",}, unit = "122mm_a19"},
					{priority = 1.0, type = {"Class1", "Tank", "Heavy", "AT",}, unit = "isu152"},
					{priority = 1.0, type = {"Class1", "Tank", "Heavy",}, unit = "is2_44"},
					--]]

				--  Defensive Doctrine
					---[[
					--{priority = 1.0, type = {"Class", "Doctrine", "Tier1", "Infantry",}, unit = "doctrine_squad_sapper_motorised_late(rus)"},
					{priority = 1.0, type = {"Class3", "Cannon", "AA",}, unit = "37mm_61k"},
					{priority = 1.0, type = {"Class2", "Cannon", "Support",}, unit = "76mm_m43"},

					{priority = 1.0, type = {"Class2", "Cannon", "Mortar",}, unit = "120mm_pm38"},
					{priority = 1.0, type = {"Class2", "Vehicle", "Artillery",}, unit = "zis6_bm8_48"},
					{priority = 1.0, type = {"Class2", "Cannon", "AA", "AT",}, unit = "85mm_52k"},

					{priority = 1.0, type = {"Class1", "Cannon", "Artillery",}, unit = "152mm_ml20"},
					{priority = 1.0, type = {"Class3", "Cannon", "Artillery",}, unit = "203mm_b4"},
					{priority = 1.0, type = {"Class1", "Tank", "Medium", "AT",}, unit = "su100"},
					--]]

				--  Irregular Doctrine
					---[[
					--{priority = 1.0, type = {"Class2", "Tier1", "Infantry",}, unit = "doctrine_squad_heavyrecon(rus)"},
					--{priority = 1.0, type = {"Class3", "Tier1", "Vehicle", "MG", "Infantry", "Team",}, unit = "doctrine_m72_snipers_late"},
					--{priority = 1.0, type = {"Class1", "Tier1", "Cannon", "MG",}, unit = "doctrine_dshk_late"},

					--{priority = 1.0, type = {"Class", "Doctrine", "Tier2", "Plane", "Airstrike",}, unit = "doctrine_yak1_late"},
					{priority = 1.0, type = {"Class2", "Tank", "Medium",}, unit = "t3457_43"},
					{priority = 1.0, type = {"Class2", "Tank", "Medium",}, unit = "t3476_43_flame"},

					--{priority = 1.0, type = {"Class", "Doctrine", "Tier3", "Plane", "Airstrike",}, unit = "doctrine_il2_late"},
					--{priority = 1.0, type = {"Class2", "Doctrine", "Tier3", "Vehicle", "Artillery",}, unit = "doctrine_zis6_bm13_16_late"},
					{priority = 1.0, type = {"Class2", "Cannon", "Artillery",}, unit = "300mm_m31"},
					{priority = 1.0, type = {"Class1", "Tank", "Heavy", "AT",}, unit = "isu122s"},
					--]]

				--  Lend-Lease Doctrine
					---[[
					--{priority = 1.0, type = {"Class2", "Tier1", "Tank", "Light",}, unit = "doctrine_m3a1_stuart_rus"},
					--{priority = 1.0, type = {"Class1", "Tier1", "Tank", "Light",}, unit = "doctrine_valentine7"},
					--{priority = 1.0, type = {"Class3", "Tier1", "Infantry",}, unit = "doctrine_squad_scoutcar_marines"},

					--{priority = 1.0, type = {"Class2", "Tier2", "Tank", "Medium",}, unit = "doctrine_m4a2_75_late_rus"},
					--{priority = 1.0, type = {"Class2", "Tier2", "Tank", "Heavy",}, unit = "doctrine_churchill3_valentine9"},
					{priority = 1.0, type = {"Class3", "Cannon", "Artillery",}, unit = "107mm_m1910_30"},

					--{priority = 1.0, type = {"Class1", "Tier3", "Tank", "Medium",}, unit = "doctrine_2m4a2_76_rus"},
					{priority = 1.0, type = {"Class2", "Vehicle", "Artillery",}, unit = "bm31_12"},
					{priority = 1.0, type = {"Class1", "Cannon", "AT",}, unit = "100mm_bs3"},
					--]]

				--  Support Doctrine
					---[[
					--{priority = 1.0, type = {"Class", "Tier1", "Infantry", "Team",}, unit = "doctrine_squad_rus_politicalofficer_late(rus)"},
					{priority = 1.0, type = {"Class3", "Tank", "Light", "Support",}, unit = "bt7a"},
					--{priority = 1.0, type = {"Class2", "Tier1", "Tank", "Light",}, unit = "t50"},

					--{priority = 1.0, type = {"Class", "Tier2", "Plane", "Recon",}, unit = "doctrine_po2_late"},
					{priority = 1.0, type = {"Class2", "Tank", "Medium", "AT",}, unit = "su85m"},
					{priority = 1.0, type = {"Class2", "Tank", "Medium",}, unit = "t3485_44b"},
													   
					{priority = 1.0, type = {"Class2", "Vehicle", "Artillery",}, unit = "bm13_studebaker"},
					{priority = 1.0, type = {"Class1", "Cannon", "Artillery",}, unit = "280mm_br5"},
					{priority = 1.0, type = {"Class1", "Tank", "Heavy",}, unit = "is2_45"},
					--]]
		
		}
	}
}