
; Presets for health and stamina levels

(include "/set/breed/presets/perks/skills.inc")


;/*=========== Unique Presets Begin ===========*/

(define "spetsnaz"			;// Soviet Spetsnaz
	{"stealth"}
	{"stamina" "400%"}
	{"telescope"}
	{"vision" human_elite}
	{"aimedshot"}			;// Silenced Nagant Pistol
)

(define "sniper_rus"		;// Soviet Snipers
	{"stamina" "150%"}
)

(define "paratrooper"		;// Soviet Paratroopers
	{"speed" 1.00}
	{"stamina" "130%"}
)

(define "mountain_rifle"	;// Soviet Mountain rifles
	{"stamina" "130%"}
)

(define "assault_sapper"	;// Soviet Assault Sappers
	{"speed" 1.00}
)

(define "guards"		;// Soviet Guards infantry
	{"stamina" "125%"}
	{"stamina_regeneration" "125%"}
)

(define "guards_marines"	;// Soviet Guards marine infantry
	{"stamina" "150%"}
	{"stamina_regeneration" "125%"}
)

(define "blau"				;// Blau division
	{"speed" 1.00}
)

(define "brandenburger"		;// German Brandenburgers
	{"stealth"}
	{"stamina" "150%"}
)

(define "vet_reg"		;// Veteran regular units
	{"stamina" "125%"}
	{"stamina_regeneration" "125%"}
)

(define "grossdeutschland"		;// German Grossdeutschland division inf/panzergrenadiers
	{"stamina" "150%"}
	{"stamina_regeneration" "150%"}
)

(define "gebirgsjager"		;// German Gebirgsjäger
	{"stamina" "150%"}
)

(define "fallschirmjager"		;// German Fallschirmjäger
	{"stamina" "150%"}
)

(define "partisan"			;// Partisans
	{"health" "175%"}
)

(define "volkssturm"
	{"pistol" lvl_1}
	{"smg" lvl_1}
	{"mgun" lvl_1}
	{"rifle" lvl_1}
	{"melee" lvl_1}
	{"avoidance" lvl_1}
	("at_rank_1")
	("health_rank_1")
	("fortification")
	("basic_repair")
	{"health" "175%"}
)

(define "recon"		;// recon soldiers
	{"health" "175%"}
	{"stamina" "110%"}
	{"stamina_regeneration" "110%"}
	("recon_vision")
)


(define "tank_commander"	;// Tank Commander
	("loader_skill_smg_rank_2")
	("skilled_repair")
	{"health" "175%"}
	("expert_gun")
)

(define "tankman"			;// Tank Crew
	("loader_skill_smg_rank_2")
	("skilled_repair")
	{"health" "175%"}
	("skilled_gun")
)

;/*=========== Unique Presets End ===========*/