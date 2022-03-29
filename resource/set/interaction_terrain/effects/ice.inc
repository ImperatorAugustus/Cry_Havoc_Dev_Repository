;SDL
{"ice"
(include "\set\interaction_terrain\effects\effects-defines.inc")
	{on hit		
		{if effector "shell_cannon_auto"
			{start_sound "hit/shell/shell_20mm/" use_position}
		else effector "shell_cannon"
			{start_sound "hit/shell/shell_50mm/" use_position}
		else effector "shell_large_rifle"
			{start_sound "hit/shell/shells_small/shared/Concrete/" use_position}
		else effector "shell_rifle"
			{start_sound "hit/shell/shells_small/shared/Concrete/" use_position}
		else effector "shell_9x19mm"
			{start_sound "hit/shell/shells_small/shared/Concrete/" use_position}
		else effector "shell_762x25mm"
			{start_sound "hit/shell/shells_small/shared/Concrete/" use_position}
		else effector "shell_792x33mm"
			{start_sound "hit/shell/shells_small/shared/Concrete/" use_position}
		else min_mass 10
			{spawn "spheredust_tiny"}
		else
		}
	}
	{on detonate
		{if stuff "grenade fire"	; ...........................................................................	Molotov Grenades
			{spawn "ex_molot_ground"}
;----------------------------------------------------------------------------------------------------------------------------	BULLETS
		else stuff "bullet_fx size1"	; ...........................................................................	7.62x25mm - 11.43x23mm
			{spawn "ex_bul_sm_snow"}
		else stuff "bullet_fx size2"	; ...........................................................................	7.62x33mm - 7.92x94mm
			("sonic_crack")
			{spawn "ex_bul_big_snow"}
		else stuff "bullet_fx size3"	; ...........................................................................	12.7x99mm - 14.5x114mm
			("sonic_crack_medium")
			{spawn "ex_bul_big_snow"}
;----------------------------------------------------------------------------------------------------------------------------	20MM TO 40MM AA
		else stuff "auto ap"		; ...........................................................................	AP
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{spawn "ex_ap_autocannon_snow"}
		else stuff "auto apbc"		; ...........................................................................	APBC										
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{spawn "ex_ap_autocannon_snow"}
		else stuff "auto aphe"		; ...........................................................................	APHE									
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{spawn "ex_ap_autocannon_snow"}
		else stuff "auto apcr"		; ...........................................................................	APCR								
			("sonic_crack_medium")
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{spawn "ex_apcr_autocannon_snow"}
		else stuff "auto he"		; ...........................................................................	HE
			("explosion_he_auto")
			{spawn "ex_he_autocannon_snow"}
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
;---------------------------------------------------------------------------------------------------------------------		GRENADES & EXPLOSIVES
		else stuff "grenade size1"	; ...........................................................................	Fillings from 0.0 to 0.10 Kg - f.e. F 1, RGD 33
			("explosion_minimum")
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "ex_grenade_size1_snow"}
		else stuff "grenade size2"	; ...........................................................................	Fillings from 0.10 to 0.60 Kg - f.e. M 24 Stielhandgranate, M 67, Dynamite x3 
			("explosion_grenade")
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "ex_grenade_size2_snow"}
		else stuff "grenade size3"	; ...........................................................................	Fillings from 0.60 to 1.50 Kg - f.e. M 24 Geballte Ladung, RPG 40, RPG 43, Dynamite x7
			("explosion_small")
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "shockwave_sphere"}
			{spawn "ex_grenade_size3_snow"}
		else stuff "grenade size4"	; ...........................................................................	Fillings from 3.00 to 7.00 Kg - f.e. 3kg Geballteladung, TMi 35/44, M 37 Satchel, TMD-B and TMD-44
			("explosion_medium")
			{spawn "shockwave_sphere"}
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "ex_he_size3_snow"}
;------------------------------------------------------------------------------------------------------------------------------------	MORTARS
		else stuff "mortar size1 he"		; ...........................................................................	50-70mm Mortar shells
			("explosion_grenade")
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "ex_grenade_size1_snow"}
		else stuff "mortar size2 he"		; ...........................................................................	80mm Mortar shells
			("explosion_small")
			{spawn "shockwave_sphere"}
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "ex_mort_sm_snow"}
		else stuff "big mortar ic"		; ...........................................................................	107-120mm Mortar incendiary	
			{start_sound "detonation/explosion_medium/mid/" use_position}
			{start_sound "detonation/explosion_medium/far/" use_position}
			{start_sound "fire/bush/" use_position}
			{spawn "ex_ic_120_ground"}
			{spawn "burn_piece" dir_velocity}
			{fire radius 4 time 20 heating 0.25}
		else stuff "mortar size3 he"		; ...........................................................................	107-120mm Mortar shells
			("explosion_large")
			{spawn "shockwave_sphere"}
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "ex_mort_big_snow"}
;------------------------------------------------------------------------------------------------------------------------------------	HEAT SHELLS
		else stuff "heat_shell size1"		; ...........................................................................	37-74mm
			("explosion_HEAT")
			{spawn "shockwave_sphere"}
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "ex_he_size1_snow"}
		else stuff "heat_shell size2"		; ...........................................................................	75-104mm
			("explosion_HEAT")
			{spawn "shockwave_sphere"}
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "ex_he_size2_snow"}
		else stuff "heat_shell size3"		; ...........................................................................	105-149mm
			("explosion_HEAT_large")
			{spawn "shockwave_sphere"}
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "ex_he_size3_snow"}
		else stuff "heat_shell size4"		; ...........................................................................	150-169mm
			("explosion_HEAT_large")
			{spawn "shockwave_sphere"}
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "ex_he_size3_snow"}
;------------------------------------------------------------------------------------------------------------------------------------	AP w/Filler SHELLS
		else stuff "shell size1 hasfiller"	; ...........................................................................	37-74mm
			{spawn "ex_ap_size1_snow"}
		else stuff "shell size2 hasfiller"	; ...........................................................................	75-104mm
			("explosion_ap")
			{spawn "ex_ap_size2_snow"}
		else stuff "shell size3 hasfiller"	; ...........................................................................	105-149mm
			("explosion_ap")
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "ex_ap_size3_snow"}
		else stuff "shell size4 hasfiller"	; ...........................................................................	150-169mm
			("explosion_ap")
			{start_sound "detonation/explosion_mechanical/trickle/Rock/" use_position}
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "ex_ap_size4_snow"}
;------------------------------------------------------------------------------------------------------------------------------------	APCR Shells
		else stuff "shell size1 apcr"		; ...........................................................................	37-74mm
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{spawn "ex_ap_size1_snow"}
		else stuff "shell size2 apcr"		; ...........................................................................	75-104mm
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{spawn "ex_ap_size2_snow"}
		else stuff "shell size3 apcr"		; ...........................................................................	105-149mm
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{start_sound "detonation/explosion_mechanical/trickle/short/" use_position}
			{spawn "ex_ap_size3_snow"}
		else stuff "shell size4 apcr"		; ...........................................................................	150-169mm
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{start_sound "detonation/explosion_mechanical/trickle/short/" use_position}
			{spawn "ex_ap_size4_snow"}
;------------------------------------------------------------------------------------------------------------------------------------	HE SHELLS
		else stuff "shell size1 he"		; ...........................................................................	Fillings from 0.0 to 0.20 Kg
			("explosion_minimum")
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "ex_he_size1_snow"}
		else stuff "shell size2 he"		; ...........................................................................	Fillings from 0.20 to 1.00 Kg
			("explosion_small")
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "ex_he_size2_snow"}
		else stuff "shell size3 he"		; ...........................................................................	Fillings from 1.00 to 3.50 Kg
			("explosion_medium")
			{spawn "shockwave_sphere"}
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "ex_he_size3_snow"}
		else stuff "shell size4 he"		; ...........................................................................	Fillings from 3.50 to 7.00 Kg
			("explosion_large")
			{spawn "shockwave_sphere"}
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "ex_he_size4_snow"}
		else stuff "shell size5"		; ...........................................................................	Fillings from 7.00 to 12.00 Kg
			("explosion_massive")
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "ex_he_size5_snow"}
		else stuff "shell size6"		; ...........................................................................	Fillings 12.00+ Kg
			("explosion_massive")
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size6_snow"}
;------------------------------------------------------------------------------------------------------------------------------------	AIRCRAFT BOMBS
		else stuff "bomb size1"			; ...........................................................................	50-60kg bombs / explosives
			("explosion_large")
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "shockwave_sphere"}
			{spawn "ex_bomb_50kg_snow"}
		else stuff "bomb size2"			; ...........................................................................	100-200kg bombs / explosives
			("explosion_massive")
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "shockwave_sphere"}
			{spawn "ex_bomb_100kg_snow"}
		else stuff "bomb size3"			; ...........................................................................	250kg+ bomb
			("explosion_massive")
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "shockwave_sphere"}
			{spawn "ex_bomb_250kg_snow"}
;------------------------------------------------------------------------------------------------------------------------------------	MINES
		else stuff "mine antipersonnel"		; ...........................................................................	Anti-Personnel Mines
			("explosion_grenade")
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "ex_grenade_size2_snow"}
		else stuff "mine antitank"		; ...........................................................................	Anti-Tank Mines
			("explosion_medium")
			{spawn "shockwave_sphere"}
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "ex_at_mine_snow"}
;------------------------------------------------------------------------------------------------------------------------------------	OTHERS
		else stuff "shell smoke"		; ...........................................................................	All cannon Smoke shells
			{start_sound "detonation/explosion_smoke/mid/" use_position}
			{start_sound "detonation/explosion_smoke/far/" use_position}
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
			{spawn "mortar_smoke"}										; initial explosion fx
			{spawn "shell_smoke"}										; actual smoke and vision volumes
			{spawn "ex_ap_size2_snow"}
		else stuff "flare marker"		; ...........................................................................	Special Flare ammo for mission scripts
			{spawn "flare_marker"}
			{spawn "ex_bul_sm_snow"}
		else stuff "flare artillery"		; ...........................................................................	Flare for off-map Artillery
			{spawn "flare_artillery"}
			{spawn "ex_bul_sm_snow"}
		else stuff "glass ic"											; Ampulomet glass ball
			{spawn "ex_glass_ic_ground"}
			{spawn "burn_piece" dir_velocity}
			{fire radius 2 time 20 heating 0.25}
		}
	}
}
