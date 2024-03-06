;/*----------------------*/

;// Shell mass < 5 kg
(define "he_level_1" ;"he_small_blast"
	{damage blastwave
		{energy (+ (/ %weight 20) (+ 5 (* %filler 1)))}
		{area (* %filler 0.25) (* %filler 0.5)}
		{ground_interaction_radius 1.25}
	}
	{damage add blastwave
		{energy (+ 2 (+ (/ %weight 20) (* 1 (- 1 (/ %filler %weight)))))}
		{area (+ (* %weight 0.1) (+ 0 (* 0.1 %filler)))			(+ (* %weight 0.2) (+ 0 (* 0.1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
	{damage add blastwave
		{energy (+ 0.55 (- 1 (/ %filler %weight)))}
		{area (+ (* %weight 0.1) (+ 5.5 (* 0.75 %filler)))			(+ (* %weight 0.11) (+ 9 (* 1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
)

;// Shell mass > 5kg and Fill mass < 1kg
(define "he_level_2" ;"he_medium_blast"
	{damage blastwave
		{energy (+ (/ %weight 20) (+ 5 (* %filler 1)))}
		{area (* %filler 0.25) (* %filler 0.5)}
		{ground_interaction_radius 1.25}
	}
	{damage add blastwave
		{energy (+ 2 (+ (/ %weight 20) (* 1 (- 1 (/ %filler %weight)))))}
		{area (+ (* %weight 0.1) (+ 0 (* 0.1 %filler)))			(+ (* %weight 0.2) (+ 0 (* 0.1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
	{damage add blastwave
		{energy (+ 0.55 (- 1 (/ %filler %weight)))}
		{area (+ (* %weight 0.1) (+ 5.5 (* 0.75 %filler)))			(+ (* %weight 0.11) (+ 9 (* 1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
)

;// Shell mass 14 - 35kg and Fill mass 1 - 5kg
(define "he_level_3" ;"he_large_blast"
	{damage blastwave
		{energy (+ (/ %weight 20) (+ 5 (* %filler 1)))}
		{area (* %filler 0.25) (* %filler 0.5)}
		{ground_interaction_radius 1.25}
	}
	{damage add blastwave
		{energy (+ 2 (+ (/ %weight 20) (* 1 (- 1 (/ %filler %weight)))))}
		{area (+ (* %weight 0.1) (+ 0 (* 0.1 %filler)))			(+ (* %weight 0.2) (+ 0 (* 0.1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
	{damage add blastwave
		{energy (+ 0.55 (- 1 (/ %filler %weight)))}
		{area (+ (* %weight 0.1) (+ 5.5 (* 0.75 %filler)))			(+ (* %weight 0.11) (+ 9 (* 1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
)

;// Shell mass > 35kg and Fill mass 5 - 10kg
(define "he_level_4" ;"he_super_blast"
	{damage blastwave
		{energy (+ (/ %weight 20) (+ 5 (* %filler 1)))}
		{area (* %filler 0.25) (* %filler 0.5)}
		{ground_interaction_radius 1.25}
	}
	{damage add blastwave
		{energy (+ 2 (+ (/ %weight 20) (* 1 (- 1 (/ %filler %weight)))))}
		{area (+ (* %weight 0.1) (+ 0 (* 0.1 %filler)))			(+ (* %weight 0.2) (+ 0 (* 0.1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
	{damage add blastwave
		{energy (+ 0.55 (- 1 (/ %filler %weight)))}
		{area (+ (* %weight 0.1) (+ 5.5 (* 0.75 %filler)))			(+ (* %weight 0.11) (+ 9 (* 1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
)

;// Fill mass 10 - 25kg
(define "he_level_5" ;"he_mega_blast"
	{damage blastwave
		{energy (+ (/ %weight 20) (+ 5 (* %filler 1)))}
		{area (* %filler 0.25) (* %filler 0.5)}
		{ground_interaction_radius 1.25}
	}
	{damage add blastwave
		{energy (+ 2 (+ (/ %weight 20) (* 1 (- 1 (/ %filler %weight)))))}
		{area (+ (* %weight 0.1) (+ 0 (* 0.1 %filler)))			(+ (* %weight 0.2) (+ 0 (* 0.1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
	{damage add blastwave
		{energy (+ 0.55 (- 1 (/ %filler %weight)))}
		{area (+ (* %weight 0.1) (+ 5.5 (* 0.75 %filler)))			(+ (* %weight 0.11) (+ 9 (* 1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
)

;// Fill mass 25 - 100kg
(define "he_level_6"
	{damage blastwave
		{energy (+ (/ %weight 20) (+ 5 (* %filler 1)))}
		{area (* %filler 0.25) (* %filler 0.5)}
		{ground_interaction_radius 1.25}
	}
	{damage add blastwave
		{energy (+ 2 (+ (/ %weight 20) (* 1 (- 1 (/ %filler %weight)))))}
		{area (+ (* %weight 0.1) (+ 0 (* 0.1 %filler)))			(+ (* %weight 0.2) (+ 0 (* 0.1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
	{damage add blastwave
		{energy (+ 0.55 (- 1 (/ %filler %weight)))}
		{area (+ (* %weight 0.1) (+ 5.5 (* 0.75 %filler)))			(+ (* %weight 0.11) (+ 9 (* 1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
)

;// Fill mass 100kg +
(define "he_level_7"
	{damage blastwave
		{energy (+ (/ %weight 20) (+ 5 (* %filler 1)))}
		{area (* %filler 0.25) (* %filler 0.5)}
		{ground_interaction_radius 1.25}
	}
	{damage add blastwave
		{energy (+ 2 (+ (/ %weight 20) (* 1 (- 1 (/ %filler %weight)))))}
		{area (+ (* %weight 0.1) (+ 0 (* 0.1 %filler)))			(+ (* %weight 0.2) (+ 0 (* 0.1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
	{damage add blastwave
		{energy (+ 0.55 (- 1 (/ %filler %weight)))}
		{area (+ (* %weight 0.1) (+ 5.5 (* 0.75 %filler)))			(+ (* %weight 0.11) (+ 9 (* 1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
)

;// Fill mass 1000kg +
(define "he_level_8"
	{damage blastwave
		{energy (+ (/ %weight 20) (+ 5 (* %filler 1)))}
		{area (* %filler 0.25) (* %filler 0.5)}
		{ground_interaction_radius 1.25}
	}
	{damage add blastwave
		{energy (+ 2 (+ (/ %weight 20) (* 1 (- 1 (/ %filler %weight)))))}
		{area (+ (* %weight 0.1) (+ 0 (* 0.1 %filler)))			(+ (* %weight 0.2) (+ 0 (* 0.1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
	{damage add blastwave
		{energy (+ 0.55 (- 1 (/ %filler %weight)))}
		{area (+ (* %weight 0.1) (+ 5.5 (* 0.75 %filler)))			(+ (* %weight 0.11) (+ 9 (* 1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
)


(define "wp"								;// All White Phosphorus Shells
	{damage fire
		{radius (- (* %cal 0.05) 1.5)}
		{heating 10}
		{time 0.5}
	}
	{damage blastwave
		{energy 1.5}
		{area (* %cal 0.03) (* %cal 0.05)}
		{ground_interaction_radius 0.2}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
)

(define "smoke_blast"						;// All cannon Smoke Shells
	{damage blastwave
		{energy 1.5}
		{area (* %cal 0.03) (* %cal 0.05)}
		{ground_interaction_radius 0.2}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
)

;/*----------------------*/

;/*----------------------*/

;// Rocket mass > 5kg and Fill mass < 1kg
(define "rocket_level_2" 
	{damage blastwave
		{energy (+ (/ %weight 20) (+ 5 (* %filler 1)))}
		{area (* %filler 0.25) (* %filler 0.5)}
		{ground_interaction_radius 1.25}
	}
	{damage add blastwave
		{energy (+ 2 (+ (/ %weight 20) (* 1 (- 1 (/ %filler %weight)))))}
		{area 1.3			(+ (* %weight 0.2) (+ 0 (* 0.1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
	{damage add blastwave
		{energy (+ 0.55 (- 1 (/ %filler %weight)))}
		{area (+ (* %weight 0.1) (+ 5.5 (* 0.75 %filler)))			(+ (* %weight 0.11) (+ 9 (* 1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
)

;// Rocket mass 14 - 35kg and Fill mass 1 - 5kg
(define "rocket_level_3" ;
	{damage blastwave
		{energy (+ (/ %weight 20) (+ 5 (* %filler 1)))}
		{area (* %filler 0.25) (* %filler 0.5)}
		{ground_interaction_radius 1.25}
	}
	{damage add blastwave
		{energy (+ 2 (+ (/ %weight 20) (* 1 (- 1 (/ %filler %weight)))))}
		{area 2			(+ (* %weight 0.2) (+ 0 (* 0.1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
	{damage add blastwave
		{energy (+ 0.55 (- 1 (/ %filler %weight)))}
		{area (+ (* %weight 0.1) (+ 5.5 (* 0.75 %filler)))			(+ (* %weight 0.11) (+ 9 (* 1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
)

;// Rocket mass > 35kg and Fill mass 5 - 10kg
(define "rocket_level_4" ;
	{damage blastwave
		{energy (+ (/ %weight 20) (+ 5 (* %filler 1)))}
		{area (* %filler 0.25) (* %filler 0.5)}
		{ground_interaction_radius 1.25}
	}
	{damage add blastwave
		{energy (+ 2 (+ (/ %weight 20) (* 1 (- 1 (/ %filler %weight)))))}
		{area 2			(+ (* %weight 0.2) (+ 0 (* 0.1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
	{damage add blastwave
		{energy (+ 0.55 (- 1 (/ %filler %weight)))}
		{area (+ (* %weight 0.1) (+ 5.5 (* 0.75 %filler)))			(+ (* %weight 0.11) (+ 9 (* 1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
)

;// Rocket mass 10 - 25kg
(define "rocket_level_5" ;
	{damage blastwave
		{energy (+ (/ %weight 20) (+ 5 (* %filler 1)))}
		{area (* %filler 0.25) (* %filler 0.5)}
		{ground_interaction_radius 1.25}
	}
	{damage add blastwave
		{energy (+ 2 (+ (/ %weight 20) (* 1 (- 1 (/ %filler %weight)))))}
		{area 2			(+ (* %weight 0.2) (+ 0 (* 0.1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
	{damage add blastwave
		{energy (+ 0.55 (- 1 (/ %filler %weight)))}
		{area (+ (* %weight 0.1) (+ 5.5 (* 0.75 %filler)))			(+ (* %weight 0.11) (+ 9 (* 1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
)

;// Rocket mass 25 - 100kg
(define "rocket_level_6"
	{damage blastwave
		{energy (+ (/ %weight 20) (+ 5 (* %filler 1)))}
		{area (* %filler 0.25) (* %filler 0.5)}
		{ground_interaction_radius 1.25}
	}
	{damage add blastwave
		{energy (+ 2 (+ (/ %weight 20) (* 1 (- 1 (/ %filler %weight)))))}
		{area 2			(+ (* %weight 0.2) (+ 0 (* 0.1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
	{damage add blastwave
		{energy (+ 0.55 (- 1 (/ %filler %weight)))}
		{area (+ (* %weight 0.1) (+ 5.5 (* 0.75 %filler)))			(+ (* %weight 0.11) (+ 9 (* 1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
)

;// Fill mass 100kg +
(define "rocket_level_7"
	{damage blastwave
		{energy (+ (/ %weight 20) (+ 5 (* %filler 1)))}
		{area (* %filler 0.25) (* %filler 0.5)}
		{ground_interaction_radius 1.25}
	}
	{damage add blastwave
		{energy (+ 2 (+ (/ %weight 20) (* 1 (- 1 (/ %filler %weight)))))}
		{area 2			(+ (* %weight 0.2) (+ 0 (* 0.1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
	{damage add blastwave
		{energy (+ 0.55 (- 1 (/ %filler %weight)))}
		{area (+ (* %weight 0.1) (+ 5.5 (* 0.75 %filler)))			(+ (* %weight 0.11) (+ 9 (* 1 %filler)))}
		{ground_interaction_radius 0}		;// value is multiplied by 2nd value of area to deterimine is blast is close enough to ground to trigger terrain fx
	}
)