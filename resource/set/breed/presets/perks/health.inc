
; Presets for health and stamina levels

(include "/set/breed/presets/perks/vision.inc")


;/*=========== Standard Presets Begin ===========*/

(define "health_rank_1"		;// concripts or replacement soldiers
	{"health" "175%"}
	{"health_regeneration" "2.5%"}
	{"stamina" "90%"}
	{"stamina_regeneration" "75%"}
	{"personage" 0}
	("standard_vision")
)

(define "health_rank_2"		;// standard soldier, most infantry use this level
	{"health" "200%"}
	{"health_regeneration" "5%"}
	{"stamina" "100%"}
	{"stamina_regeneration" "100%"}
	{"personage" 0}
	("standard_vision")
)

(define "health_rank_3"		;// elite soldier with better training
	{"health" "225%"}
	{"health_regeneration" "7.5%"}
	{"stamina" "110%"}
	{"stamina_regeneration" "100%"}
	{"personage" 0}
)

(define "health_rank_4"		;// super elite units
	{"health" "250%"}
	{"health_regeneration" "10%"}
	{"stamina" "120%"}
	{"stamina_regeneration" "100%"}
	{"personage" 0}
)



;/*=========== Standard Presets End ===========*/