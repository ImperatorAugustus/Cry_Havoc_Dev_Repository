;/*----------------------*/

;May want to replace infantry killing blast wave with custom spawn zones interact rng.

;https://cdn.discordapp.com/attachments/544232093249437758/1028438515270291557/unknown.png?ex=65f62181&is=65e3ac81&hm=b939f79484836c5396d4a1ae5c4236fe3648eda30e0ecb6c7e20445b64ddecc2&
;https://unsaferguard.org/un-saferguard/blast-damage-estimation
;https://protogetic.com/resources/the-protogetic-blast-calculator/
;https://www.desmos.com/calculator/f9od8zzynj

;kpa-ms seems more accurate
;323000 kpa - 47k psi			to full kill t54														110kpa-ms		25kg 0.3m offset min
;150k - 22k 					to kill btr 															39kpa-ms		9kg
;114k - 16.5k 					to destroy tracks 														31kpa-ms		7kg
;59k - 8.5k 					to set off munitions/destroy 3ft blast reinforced concrete				16kpa-ms		3.5kg
;10k - 1.4k 					to destroy tires 														10kpa-ms		2kg

;The above are set per shell at fixed distances due to lack of in engine explosion calculations
;Contact energy is 1/20th of the filler energy scaled at
;Below are shrapnel damage to infantry area 1 is 50% probability of kill 2 is 50% casualty radius (simplified as percent damage for now), both scaled to 1:8.

;1 blast wave is 625 health to humans
;1 blast wave is 5 health to vehicles * per class modifier 6-10 * per volume modifier with x (base 50%) * volume thickness requirement

;Compensation for game scale and formula limitations
;+0.5/1 for all radius
;6 /12
;7 /20
;8 /32

;// Shell mass < 5 kg
(define "he_level_1" ;"he_small_blast"
	{damage add blastwave ;Infantry Killing/Track and Light Armor Damage. 1.5mm of Plate Penetration.
		{energy 0.5}
		{area (+ 0.5 (/ (- %weight %filler) 8)) (+ 0.5 (/ (- %weight %filler) 8))}
		{ground_interaction_radius 0}		
	}
	{damage add blastwave ;Infantry Wounding
		{energy 0.2}
		{area 0 (+ 1 (/ (+ (* 2 %weight) (* 5 %filler)) 8))}
		{ground_interaction_radius 0}		
	}
)

;// Shell mass > 5kg and Fill mass < 1kg
(define "he_level_2" ;"he_medium_blast"
	{damage add blastwave ;Infantry Killing/Track and Light Armor Damage. 9mm of Plate Penetration
		{energy 3}
		{area (+ 0.5 (/ (- %weight %filler) 8)) (+ 0.5 (/ (- %weight %filler) 8))}
		{ground_interaction_radius 0}		
	}
	{damage add blastwave ;Infantry Wounding
		{energy 0.2}
		{area 0 (+ 1 (/ (+ (* 2 %weight) (* 5 %filler)) 8))}
		{ground_interaction_radius 0}		
	}
)

;// Shell mass 14 - 35kg and Fill mass 1 - 5kg
(define "he_level_3" ;"he_large_blast"
	{damage add blastwave ;Contact Armor Damage
		{energy (+ 8 (* 4 %filler))}
		{area 0.1 0.15}
		{ground_interaction_radius 0}		
	}
	{damage add blastwave ;Infantry Killing/Track and Light Armor Damage. 24mm of Plate Penetration
		{energy 8}
		{area (+ 0.5 (/ (- %weight %filler) 8)) (+ 0.5 (/ (- %weight %filler) 8))}
		{ground_interaction_radius 0}		
	}
	{damage add blastwave ;Infantry Wounding
		{energy 0.2}
		{area 0 (+ 1 (/ (+ (* 2 %weight) (* 5 %filler)) 8))}
		{ground_interaction_radius 0}		
	}
)

;// Shell mass > 35kg and Fill mass 5 - 10kg
(define "he_level_4" ;"he_super_blast"
	{damage add blastwave ;Infantry Killing/Track and Light Armor Damage. 27mm of Plate Penetration
		{energy 9}
		{area (+ 0.5 (/ (- %weight %filler) 8)) (+ 0.5 (/ (- %weight %filler) 8))}
		{ground_interaction_radius 0}		
	}
	{damage add blastwave ;Infantry Wounding
		{energy 0.2}
		{area 0 (+ 1 (/ (+ (* 2 %weight) (* 5 %filler)) 8))}
		{ground_interaction_radius 0}		
	}
)

;// Fill mass 10 - 25kg
(define "he_level_5" ;"he_mega_blast"
	{damage add blastwave ;Infantry Killing/Track and Light Armor Damage. 30mm of Plate Penetration
		{energy 10}
		{area (+ 0.5 (/ (- %weight %filler) 8)) (+ 0.5 (/ (- %weight %filler) 8))}
		{ground_interaction_radius 0}		
	}
	{damage add blastwave ;Infantry Wounding
		{energy 0.2}
		{area 0 (+ 1 (/ (+ (* 2 %weight) (* 5 %filler)) 8))}
		{ground_interaction_radius 0}		
	}
)

;// Fill mass 25 - 100kg
(define "he_level_6"
	{damage add blastwave ;Infantry Killing/Track and Light Armor Damage. 33mm of Plate Penetration
		{energy 11}
		{area (+ 0.5 (/ (- %weight %filler) 12)) (+ 0.5 (/ (- %weight %filler) 12))}
		{ground_interaction_radius 0}		
	}
	{damage add blastwave ;Infantry Wounding
		{energy 0.2}
		{area 0 (+ 1 (/ (+ (* 2 %weight) (* 5 %filler)) 12))}
		{ground_interaction_radius 0}		
	}
)

;// Fill mass 100kg +
(define "he_level_7"
	{damage add blastwave ;Infantry Killing/Track and Light Armor Damage. 36mm of Plate Penetration
		{energy 12}
		{area (+ 0.5 (/ (- %weight %filler) 20)) (+ 0.5 (/ (- %weight %filler) 20))}
		{ground_interaction_radius 0}		
	}
	{damage add blastwave ;Infantry Wounding
		{energy 0.2}
		{area 0 (+ 1 (/ (+ (* 2 %weight) (* 5 %filler)) 20))}
		{ground_interaction_radius 0}		
	}
)

;// Fill mass 1000kg +
(define "he_level_8"
	{damage add blastwave ;Infantry Killing/Track and Light Armor Damage. 39mm of Plate Penetration
		{energy 13}
		{area (+ 0.5 (/ (- %weight %filler) 32)) (+ 0.5 (/ (- %weight %filler) 32))}
		{ground_interaction_radius 0}		
	}
	{damage add blastwave ;Infantry Wounding
		{energy 0.2}
		{area 0 (+ 1 (/ (+ (* 2 %weight) (* 5 %filler)) 32))}
		{ground_interaction_radius 0}		
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
	{damage add blastwave ;Infantry Killing/Track and Light Armor Damage. 9mm of Plate Penetration
		{energy 3}
		{area (+ 0.5 (/ (- (* 0.7 %weight) %filler) 8)) (+ 0.5 (/ (- (* 0.7 %weight) %filler) 8))}
		{ground_interaction_radius 0}		
	}
	{damage add blastwave ;Infantry Wounding
		{energy 0.2}
		{area 0 (+ 1 (/ (+ (* 1.4 %weight) (* 5 %filler)) 8))}
		{ground_interaction_radius 0}		
	}
)

;// Rocket mass 14 - 35kg and Fill mass 1 - 5kg
(define "rocket_level_3" ;
	{damage add blastwave ;Infantry Killing/Track and Light Armor Damage. 24mm of Plate Penetration
		{energy 8}
		{area (+ 0.5 (/ (- (* 0.7 %weight) %filler) 8)) (+ 0.5 (/ (- (* 0.7 %weight) %filler) 8))}
		{ground_interaction_radius 0}		
	}
	{damage add blastwave ;Infantry Wounding
		{energy 0.2}
		{area 0 (+ 1 (/ (+ (* 1.4 %weight) (* 5 %filler)) 8))}
		{ground_interaction_radius 0}		
	}
)

;// Rocket mass > 35kg and Fill mass 5 - 10kg
(define "rocket_level_4" ;
	{damage add blastwave ;Infantry Killing/Track and Light Armor Damage. 27mm of Plate Penetration
		{energy 9}
		{area (+ 0.5 (/ (- (* 0.7 %weight) %filler) 8)) (+ 0.5 (/ (- (* 0.7 %weight) %filler) 8))}
		{ground_interaction_radius 0}		
	}
	{damage add blastwave ;Infantry Wounding
		{energy 0.2}
		{area 0 (+ 1 (/ (+ (* 1.4 %weight) (* 5 %filler)) 8))}
		{ground_interaction_radius 0}		
	}
)

;// Rocket mass 10 - 25kg
(define "rocket_level_5" ;
	{damage add blastwave ;Infantry Killing/Track and Light Armor Damage. 30mm of Plate Penetration
		{energy 10}
		{area (+ 0.5 (/ (- (* 0.7 %weight) %filler) 8)) (+ 0.5 (/ (- (* 0.7 %weight) %filler) 8))}
		{ground_interaction_radius 0}		
	}
	{damage add blastwave ;Infantry Wounding
		{energy 0.2}
		{area 0 (+ 1 (/ (+ (* 1.4 %weight) (* 5 %filler)) 8))}
		{ground_interaction_radius 0}		
	}
)

;// Rocket mass 25 - 100kg
(define "rocket_level_6"
	{damage add blastwave ;Infantry Killing/Track and Light Armor Damage. 33mm of Plate Penetration
		{energy 11}
		{area (+ 0.5 (/ (- (* 0.7 %weight) %filler) 12)) (+ 0.5 (/ (- (* 0.7 %weight) %filler) 12))}
		{ground_interaction_radius 0}		
	}
	{damage add blastwave ;Infantry Wounding
		{energy 0.2}
		{area 0 (+ 1 (/ (+ (* 1.4 %weight) (* 5 %filler)) 12))}
		{ground_interaction_radius 0}		
	}
)

;// Fill mass 100kg +
(define "rocket_level_7"
	{damage add blastwave ;Infantry Killing/Track and Light Armor Damage. 36mm of Plate Penetration
		{energy 12}
		{area (+ 0.5 (/ (- (* 0.7 %weight) %filler) 20)) (+ 0.5 (/ (- (* 0.7 %weight) %filler) 20))}
		{ground_interaction_radius 0}		
	}
	{damage add blastwave ;Infantry Wounding
		{energy 0.2}
		{area 0 (+ 1 (/ (+ (* 1.4 %weight) (* 5 %filler)) 20))}
		{ground_interaction_radius 0}		
	}
)