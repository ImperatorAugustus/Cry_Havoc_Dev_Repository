Purchases["late.fin"] = {
	{Repeat = 0,  --infinite
		Units = { 
		-- Infantry Squads
		{priority = 1.0, type = {"Class3", "Infantry", "Squad",}, unit = "squad_reserves_late(fin)"},
		{priority = 1.0, type = {"Class2", "Infantry", "Squad",}, unit = "squad_scout_late(fin)"},
		{priority = 1.0, type = {"Class2", "Infantry", "Squad",}, unit = "squad_rifle_late(fin)"},
		{priority = 1.0, type = {"Class2", "Infantry", "Squad", "AT",}, unit = "squad_antitank_late(fin)"},
		{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_assault(fin)"},
		{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_cav_late(fin)"},
		{priority = 1.0, type = {"Class2", "Infantry", "Squad",}, unit = "squad_jag_late(fin)"},
		{priority = 1.0, type = {"Class3", "Infantry", "Squad", "AT",}, unit = "squad_jag_antitank_late(fin)"},
		{priority = 1.0, type = {"Class1", "Infantry", "Squad",}, unit = "squad_border_jag_late(fin)"},
		{priority = 1.0, type = {"Class3", "Infantry", "Squad",}, unit = "squad_reserves_late(fin)"},
		{priority = 1.0, type = {"Class2", "Infantry", "Squad",}, unit = "squad_scout_late(fin)"},
		
		-- Infantry Singles / Teams
				---[[
				{priority = 1.0, type = {"Class3", "Infantry", "Team", "Aux",}, unit = "single_rifle(fin)"},
				{priority = 1.0, type = {"Class3", "Infantry", "Team", "Aux",}, unit = "single_smg(fin)"},
				{priority = 1.0, type = {"Class3", "Infantry", "Team", "Aux",}, unit = "single_sa(fin)"},
				{priority = 1.0, type = {"Class2", "Infantry", "Team",}, unit = "single_mg(fin)"},
				{priority = 1.0, type = {"Class1", "Infantry", "Team", "AT",}, unit = "single_at(fin)"},
				{priority = 1.0, type = {"Class2", "Infantry", "Team", "AT",}, unit = "single_bazooker(fin)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_ap_miner(fin)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_at_miner(fin)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_engineer(fin)"},
				{priority = 1.0, type = {"Class3", "Infantry", "Team",}, unit = "single_flamer(fin)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_tankman(fin)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_medic(fin)"},
				{priority = 1.0, type = {"Class2", "Infantry", "Team",}, unit = "single_sniper(fin)"},
				--{priority = 1.0, type = {"Class", "Infantry", "Team",}, unit = "single_officer(fin)"},
				--]]

			-- Cannons
				---[[
				--{priority = 1.0, type = {"Class", "Cannon", "Supply", "Ammo",}, unit = "inf_crate_fin"},
				
				{priority = 1.0, type = {"Class2", "Cannon", "MG",}, unit = "maxim_m1910_30"},
				{priority = 1.0, type = {"Class2", "Cannon", "MG",}, unit = "ds39_stand_fin"},
				{priority = 1.0, type = {"Class2", "Cannon", "AA",}, unit = "20mm_itk35"},
				{priority = 1.0, type = {"Class2", "Cannon", "AA",}, unit = "20mm_itk40"},

				{priority = 1.0, type = {"Class2", "Cannon", "AT",}, unit = "20mm_l39"},
				{priority = 1.0, type = {"Class3", "Cannon", "AT",}, unit = "37mm_pstk36"},
				{priority = 1.0, type = {"Class3", "Cannon", "AT",}, unit = "45mm_pstk32"},
				{priority = 1.0, type = {"Class3", "Cannon", "AT",}, unit = "47mm_pstk39"},
				{priority = 1.0, type = {"Class3", "Cannon", "AT",}, unit = "76mm_k02"},
				{priority = 1.0, type = {"Class2", "Cannon", "AT",}, unit = "75mm_pstk9738"},
				{priority = 1.0, type = {"Class2", "Cannon", "AT",}, unit = "76mm_k36"},
				{priority = 1.0, type = {"Class1", "Cannon", "AA", "AT",}, unit = "75mm_itk37"},

				{priority = 1.0, type = {"Class1", "Cannon", "Mortar",}, unit = "50mm_krh38"},
				{priority = 1.0, type = {"Class1", "Cannon", "Mortar",}, unit = "81mm_krh36"},

				{priority = 1.0, type = {"Class1", "Cannon", "Support",}, unit = "76mm_m1927_fin"},
				{priority = 1.0, type = {"Class3", "Cannon", "Artillery",}, unit = "105mm_k13"},
				--]]

			-- Wheeled vehicles
				---[[
				{priority = 1.0, type = {"Class1", "Vehicle", "AA",}, unit = "ford_3ton_breda"},
				{priority = 1.0, type = {"Class2", "Armored", "MG",}, unit = "l182"},
				{priority = 1.0, type = {"Class3", "Armored",}, unit = "ba10_fin"},

				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Transport",}, unit = "m42_truppenfahrrad"},
				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Transport",}, unit = "ford_v3000"},
				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Supply", "Ammo",}, unit = "ford_v3000_ammo"},
				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Supply", "Fuel",}, unit = "ford_v3000_fuel"},
				--{priority = 1.0, type = {"Class", "Vehicle", "Unarmed", "Supply", "Engineer",}, unit = "ford_v3000_eng"},
				--]]

			-- Tankettes
				---[[
				{priority = 1.0, type = {"Class3", "Armored", "MG",}, unit = "t20_fin"},
				--]]

			-- Tanks
				---[[
				--{priority = 1.0, type = {"Class", "Tank", "Light",}, unit = "ft17_mg_fin"},
				--{priority = 1.0, type = {"Class", "Tank", "Light",}, unit = "ft17_fin"},
				{priority = 1.0, type = {"Class1", "Tank", "Light",}, unit = "fin_captured_v_t26_late"},
				{priority = 1.0, type = {"Class3", "Tank", "Light",}, unit = "vickers_6t_altb"},
				{priority = 1.0, type = {"Class3", "Tank", "Light",}, unit = "t26e"},
				{priority = 1.0, type = {"Class3", "Tank", "Light",}, unit = "kht130_fin"},
				{priority = 1.0, type = {"Class2", "Tank", "Light",}, unit = "bt42"},

				{priority = 1.0, type = {"Class3", "Tank", "Medium",}, unit = "t28_38_fin"},
				{priority = 1.0, type = {"Class1", "Tank", "Medium",}, unit = "fin_captured_v_t3476"},
				{priority = 1.0, type = {"Class1", "Tank", "Medium",}, unit = "fin_captured_v_t3485"},
				--]]

			--- Self-Propelled Guns
				---[[
				{priority = 1.0, type = {"Class2", "Tank", "Medium", "AT",}, unit = "stug3g_fin"},
				--]]
		}
	}
}
