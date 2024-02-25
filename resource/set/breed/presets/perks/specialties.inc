
; Presets for health and stamina levels

(include "/set/breed/presets/perks/skills.inc")


;/*=========== Unique Presets Begin ===========*/

(define "medic"
	{"medic" 10.0}
	{"speed" 1.20}
	{"stamina" "180%"}
)

(define "stealth"
	{"stealth"}
	("recon_vision") 
	{"speed" 1.20}
)

(define "marksman"		;// elite sharpshooters (non sniper)
	{"rifle" lvl_8}
)

(define "tank_commander"	;// Tank Commander
	("loader_skill_smg_rank_2")
	("skilled_repair")
	{"health" "150%"}
	("expert_gun")
)

(define "tankman"			;// Tank Crew
	("loader_skill_smg_rank_2")
	("skilled_repair")
	{"health" "150%"}
	("skilled_gun")
)


;/*=========== Unique Presets End ===========*/

