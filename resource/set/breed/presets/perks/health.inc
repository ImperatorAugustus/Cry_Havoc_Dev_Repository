
; Presets for health and stamina levels

(include "/set/breed/presets/perks/vision.inc")

;/*=========== Standard Presets End ===========*/


;// TIER I // 

(define "tier1_standard"
	{"health" "150%"}
	{"health_regeneration" "0%"}
	{"stamina" "75%"}
	{"stamina_regeneration" "75%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	("standard_vision")
	{"speed" 1.00}
)

(define "tier1_recon"
	{"health" "100%"}
	{"health_regeneration" "10%"}
	{"stamina" "150%"}
	{"stamina_regeneration" "75%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	("recon_vision")
	{"speed" 1.15}
)

(define "tier1_defense"
	{"health" "150%"}
	{"health_regeneration" "0%"}
	{"stamina" "75%"}
	{"stamina_regeneration" "75%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	("standard_vision")
	{"speed" 0.85}
)


;// TIER II // 

(define "tier2_standard"
	{"health" "175%"}
	{"health_regeneration" "0%"}
	{"stamina" "125%"}
	{"stamina_regeneration" "100%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	("standard_vision")
	{"speed" 1.00}
)

(define "tier2_recon"
	{"health" "175%"}
	{"health_regeneration" "0%"}
	{"stamina" "225%"}
	{"stamina_regeneration" "100%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	("recon_vision")
	{"speed" 1.15}
)

(define "tier2_defense"
	{"health" "175%"}
	{"health_regeneration" "0%"}
	{"stamina" "125%"}
	{"stamina_regeneration" "100%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	("standard_vision")
	{"speed" 0.85}
)

;// TIER III // 

(define "tier3_standard"
	{"health" "200%"}
	{"health_regeneration" "0%"}
	{"stamina" "200%"}
	{"stamina_regeneration" "150%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	("standard_vision")
	{"speed" 1.00}
)

(define "tier3_recon"
	{"health" "200%"}
	{"health_regeneration" "0%"}
	{"stamina" "300%"}
	{"stamina_regeneration" "150%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	("recon_vision")
	{"speed" 1.15}
)

(define "tier3_defense"
	{"health" "200%"}
	{"health_regeneration" "0%"}
	{"stamina" "200%"}
	{"stamina_regeneration" "150%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	("standard_vision")
	{"speed" 0.85}
)

;// TIER IV // 

(define "tier4_standard"
	{"health" "200%"}
	{"health_regeneration" "0%"}
	{"stamina" "300%"}
	{"stamina_regeneration" "250%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	;("elite_vision")
	("standard_vision")
	{"speed" 1.00}
)

(define "tier4_recon"
	{"health" "200%"}
	{"health_regeneration" "0%"}
	{"stamina" "400%"}
	{"stamina_regeneration" "250%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	;("elite_vision")
	("recon_vision")
	{"speed" 1.15}
)

(define "tier4_defense"
	{"health" "200%"}
	{"health_regeneration" "0%"}
	{"stamina" "300%"}
	{"stamina_regeneration" "250%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	;("elite_vision")
	("standard_vision")
	{"speed" 0.85}
)
