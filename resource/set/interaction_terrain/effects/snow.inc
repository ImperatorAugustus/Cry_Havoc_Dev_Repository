;SDL
{"snow"
(include "\set\interaction_terrain\effects\effects-defines.inc")
	{on hit
		{if min_mass 100
			{if effector "tree"
				{spawn "tree_crush"}
			else
				{spawn "spheredust_small"}
			}
		else min_mass 10
			{spawn "spheredust_tiny"}
;---------------------------------------------------------------------------------------------------------------------	Empty Casings
		else effector "shell_cannon_auto"
			{start_sound "hit/shell/shell_20mm/" use_position}
		else effector "shell_cannon"
			{start_sound "hit/shell/shell_50mm/" use_position}
		else effector "shell_large_rifle"
			{start_sound "hit/shell/shells_small/shared/Soft/" use_position}
		else effector "shell_rifle"
			{start_sound "hit/shell/shells_small/shared/Soft/" use_position}
		else effector "shell_9x19mm"
			{start_sound "hit/shell/shells_small/shared/Soft/" use_position}
		else effector "shell_762x25mm"
			{start_sound "hit/shell/shells_small/shared/Soft/" use_position}
		else effector "shell_792x33mm"
			{start_sound "hit/shell/shells_small/shared/Soft/" use_position}
		else
		}
	}
	{on detonate
		{if stuff "grenade fire"	; ...........................................................................	Molotov Grenades
			{spawn "ex_molot_ground"}
;----------------------------------------------------------------------------------------------------------------------------	BULLETS
		else stuff "bullet_fx size1"		; ...........................................................................	7.62x25mm - 11.43x23mm
			{spawn "ex_bul_sm_snow"}
		else stuff "bullet_fx size2	"	; ...........................................................................	7.62x33mm - 7.92x94mm
			("sonic_crack")
			{spawn "ex_bul_sm_snow"}
		else stuff "bullet_fx size3"		; ...........................................................................	12.7x99mm - 14.5x114mm
			("sonic_crack_medium")
			{spawn "ex_bul_big_snow"}
;----------------------------------------------------------------------------------------------------------------------------	20MM TO 40MM AA
		else stuff "auto ap"			; ...........................................................................	AP
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{spawn "ex_ap_size1_snow"}
		else stuff "auto apbc"			; ...........................................................................	APBC										
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{spawn "ex_ap_size1_snow"}
		else stuff "auto aphe"			; ...........................................................................	APHE									
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{spawn "ex_ap_size1_snow"}
		else stuff "auto apcr"			; ...........................................................................	APCR								
			("sonic_crack_medium")
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{spawn "ex_apcr_autocannon_snow"}
		else stuff "auto he"			; ...........................................................................	HE
			("explosion_he_auto")
			{spawn "ex_he_autocannon_snow"}
;---------------------------------------------------------------------------------------------------------------------		GRENADES & EXPLOSIVES
		else stuff "grenade size1"		; ...........................................................................	Fillings from 0.0 to 0.10 Kg - f.e. F 1, RGD 33
			("explosion_minimum")
			{spawn "ex_grenade_size1_snow"}
			{spawn "grenade_shellhole" terrain_texmod}
		else stuff "grenade size2"		; ...........................................................................	Fillings from 0.10 to 0.60 Kg - f.e. M 24 Stielhandgranate, M 67, Dynamite x3 
			("explosion_grenade")
			{spawn "ex_grenade_size2_snow"}
			{spawn "grenade_shellhole" terrain_texmod}
		else stuff "grenade size3"		; ...........................................................................	Fillings from 0.60 to 1.50 Kg - f.e. M 24 Geballte Ladung, RPG 40, RPG 43, Dynamite x7
			("explosion_small")
			{spawn "shockwave_sphere"}
			{spawn "ex_grenade_size3_snow"}
			{spawn "grenade_at_shellhole" terrain_texmod}
		else stuff "grenade size4"		; ...........................................................................	Fillings from 3.00 to 7.00 Kg - f.e. 3kg Geballteladung, TMi 35/44, M 37 Satchel, TMD-B and TMD-44
			("explosion_medium")
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size3_snow"}
			{spawn "crater_tiny" terrain_texmod}
;------------------------------------------------------------------------------------------------------------------------------------	MORTARS
		else stuff "mortar size1 he"		; ...........................................................................	50-70mm Mortar shells
			("explosion_grenade")
			{spawn "ex_grenade_size2_snow"}
			{spawn "grenade_shellhole" terrain_texmod}
		else stuff "mortar size2 he"		; ...........................................................................	80mm Mortar shells
			("explosion_small")
			{spawn "shockwave_sphere"}
			{spawn "ex_mort_sm_snow"}
			{spawn "crater_tiny" terrain_texmod}
		else stuff "big mortar ic"		; ...........................................................................	107-120mm Mortar incendiary	
			{start_sound "detonation/explosion_medium/mid/" use_position}
			{start_sound "detonation/explosion_medium/far/" use_position}
			{start_sound "fire/bush/" use_position}
			{spawn "ex_ic_120_ground"}
			{spawn "burn_piece" dir_velocity}
			{spawn "burned_spot_round2" scale 1.4 random_orientation}
			{fire radius 4 time 20 heating 0.25}
		else stuff "mortar size3 he"		; ...........................................................................	107-120mm Mortar shells
			("explosion_large")
			{spawn "shockwave_sphere"}
			{spawn "ex_mort_big_snow"}
			{spawn "crater_small" terrain_texmod} 
;------------------------------------------------------------------------------------------------------------------------------------	HEAT SHELLS
		else stuff "heat_shell size1"	; ...........................................................................	37-74mm
			("explosion_HEAT")
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size1_snow"}
			{spawn "grenade_at_shellhole" terrain_texmod}
		else stuff "heat_shell size2"	; ...........................................................................	75-104mm
			("explosion_HEAT")
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size2_snow"}
			{spawn "crater_tiny" terrain_texmod}
		else stuff "heat_shell size3"	; ...........................................................................	105-149mm
			("explosion_HEAT_large")
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size3_snow"}
			{spawn "crater_small" terrain_texmod}
		else stuff "heat_shell size4"	; ...........................................................................	150-169mm
			("explosion_HEAT_large")
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size3_snow"}
			{spawn "crater_small" terrain_texmod}
;------------------------------------------------------------------------------------------------------------------------------------	AP w/Filler SHELLS
		else stuff "shell size1 hasfiller"	; ...........................................................................	37-74mm
			{spawn "ap_shellhole" scale 0.5}
			{spawn "ex_ap_size1_snow"}
		else stuff "shell size2 hasfiller"	; ...........................................................................	75-104mm
			("explosion_ap")
			{spawn "ap_shellhole" scale 0.75}
			{spawn "ex_ap_size2_snow"}
		else stuff "shell size3 hasfiller"	; ...........................................................................	105-149mm
			("explosion_ap")
			{spawn "ap_shellhole"}
			{spawn "ex_ap_size3_snow"}
		else stuff "shell size4 hasfiller"	; ...........................................................................	150-169mm
			("explosion_ap")
			{start_sound "detonation/explosion_mechanical/trickle/short/" use_position}
			{spawn "ex_ap_size4_snow"}
			{spawn "grenade_shellhole" terrain_texmod}
;------------------------------------------------------------------------------------------------------------------------------------	APCR Shells
		else stuff "shell size1 apcr"		; ...........................................................................	37-74mm
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{spawn "ap_shellhole" scale 0.5}
			{spawn "ex_ap_size1_snow"}
		else stuff "shell size2 apcr"		; ...........................................................................	75-104mm
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{spawn "ap_shellhole" scale 0.75}
			{spawn "ex_ap_size2_snow"}
		else stuff "shell size3 apcr"		; ...........................................................................	105-149mm
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{start_sound "detonation/explosion_mechanical/trickle/short/" use_position}
			{spawn "ap_shellhole"}
			{spawn "ex_ap_size3_snow"}
		else stuff "shell size4 apcr"		; ...........................................................................	150-169mm
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{start_sound "detonation/explosion_mechanical/trickle/short/" use_position}
			{spawn "ap_shellhole" scale 1.25}
			{spawn "ex_ap_size4_snow"}
;------------------------------------------------------------------------------------------------------------------------------------	HE SHELLS
		else stuff "shell size1 he"		; ...........................................................................	Fillings from 0.0 to 0.20 Kg
			("explosion_minimum")
			{spawn "ex_he_size1_snow"}
			{spawn "grenade_shellhole" terrain_texmod scale 0.75}
		else stuff "shell size2 he"		; ...........................................................................	Fillings from 0.20 to 1.00 Kg
			("explosion_small")
			{spawn "ex_he_size2_snow"}
			{spawn "crater_tiny" terrain_texmod}
		else stuff "shell size3 he"		; ...........................................................................	Fillings from 1.00 to 3.50 Kg
			("explosion_medium")
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size3_snow"}
			{spawn "crater_small" terrain_texmod}
		else stuff "shell size4 he"		; ...........................................................................	Fillings from 3.50 to 7.00 Kg
			("explosion_large")
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size4_snow"}
			{spawn "crater_medium" terrain_texmod}
		else stuff "shell size5"		; ...........................................................................	Fillings from 7.00 to 12.00 Kg
			("explosion_massive")
			{spawn "ex_he_size5_snow"}
			{spawn "crater_massive" terrain_texmod}
		else stuff "shell size6"		; ...........................................................................	Fillings 12.00+ Kg
			("explosion_massive")
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size6_snow"}
			{spawn "crater_massive" terrain_texmod}
;------------------------------------------------------------------------------------------------------------------------------------	AIRCRAFT BOMBS
		else stuff "bomb size1"			; ...........................................................................	50-60kg bombs / explosives
			("explosion_large")
			{spawn "shockwave_sphere"}
			{spawn "ex_bomb_50kg_snow"}
			{spawn "crater_medium" terrain_texmod}
		else stuff "bomb size2"			; ...........................................................................	100-200kg bombs / explosives
			("explosion_massive")
			{spawn "shockwave_sphere"}
			{spawn "ex_bomb_100kg_snow"}
			{spawn "crater_big" terrain_texmod}
		else stuff "bomb size3"			; ...........................................................................	250kg+ bomb
			("explosion_massive")
			{spawn "shockwave_sphere"}
			{spawn "ex_bomb_250kg_snow"}
			{spawn "crater_big" terrain_texmod}
;------------------------------------------------------------------------------------------------------------------------------------	MINES
		else stuff "mine antipersonnel"		; ...........................................................................	Anti-Personnel Mines
			("explosion_grenade")
			{spawn "ex_he_size1_snow"}
			{spawn "grenade_shellhole" terrain_texmod}
		else stuff "mine antitank"		; ...........................................................................	Anti-Tank Mines
			("explosion_medium")
			{spawn "shockwave_sphere"}
			{spawn "ex_at_mine_snow"}
			{spawn "grenade_at_shellhole" terrain_texmod}
;------------------------------------------------------------------------------------------------------------------------------------	OTHERS
		else stuff "shell smoke"		; ...........................................................................	All cannon Smoke shells
			{start_sound "detonation/explosion_smoke/mid/" use_position}
			{start_sound "detonation/explosion_smoke/far/" use_position}
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{start_sound "detonation/explosion_mechanical/terrain/Snow/" use_position}
			{spawn "mortar_smoke"}										; initial explosion fx
			{spawn "shell_smoke"}										; actual smoke and vision volumes
			{spawn "ap_shellhole"}
		else stuff "flare marker"		; ...........................................................................	Special Flare ammo for mission scripts
		{if rain
			{spawn "flare_marker"}
		else
			{spawn "flare_marker"}
			{spawn "spheredust_small"}
		}
		else stuff "flare artillery"		; ...........................................................................	Flare for off-map Artillery
		{if rain
			{spawn "flare_artillery"}
		else
			{spawn "flare_artillery"}
			{spawn "spheredust_small"}
		}	
		else stuff "glass ic"											; Ampulomet glass ball
			{spawn "ex_glass_ic_ground"}
			{spawn "burn_piece" dir_velocity}
			{spawn "burned_spot_round2" random_orientation}
			{fire radius 2 time 20 heating 0.25}
		}
	}
}