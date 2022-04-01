;/*----------------------*/

	(define "velocity"				;// muzzle velocity in meters per second
		{speed (* 0.70 %mps)}
	)
	(define "fire rate"				;// rate of fire in rounds per minute 
		{recoveryTime (/ 60 %rpm)}
	)
	(define "reload time"			;// reload time for magazine or shell
		{rechargeTime %seconds}
	)
	(define "human health"
		{healthDamage (* 1.0 %damage)}
	)
	(define "armor health"
		{minimumDamageModifier (* 1.0 %damage)}
	)

;/*----------------------*/

	(define "accuracy_pistol"
		("pistol_range"  r1(0.4) r2(1.3) globalaccuracy(0.75))
	)

;/*----------------------*/

	(define "accuracy_smg"
		("smg_range"  r1(0.9) r2(2.5) globalaccuracy(0.75))
	)

;/*----------------------*/

	(define "accuracy_rifle"
		("rifle_range"	r0(0.2) r1(0.4) r2(0.9) r3(1.3) globalaccuracy(0.75))
	)
	(define "accuracy_rifle_sniper"
		("sniper_range" r0(0.2) r1(0.4) r2(0.9) r3(1.3) globalaccuracy(0.75))
	)
	(define "accuracy_rifle_auto"
		("rifle_range"	r0(0.4) r1(0.8) r2(1.7) r3(2.4) globalaccuracy(0.75))
	)
	(define "accuracy_rifle_auto_sniper"
		("sniper_range" r0(0.4) r1(0.8) r2(1.7) r3(2.4) globalaccuracy(0.75))
	)
	(define "accuracy_shotgun"
		("rifle_range"	r0(0.2) r1(1.4) r2(0.9) r3(1.3) globalaccuracy(0.75))
	)
	(define "accuracy_rifle_at"
		("rifle_range"	r0(0.4) r1(1.0) r2(1.5) r3(2.0) globalaccuracy(0.75))
	)

	(define "accuracy_mg"
		("mg_range" r1(0.5) r2(1.3) r3(1.7) globalaccuracy(0.75))
	)
	(define "accuracy_hmg"
		("hmg_range" r1(0.5) r2(1.3) r3(1.7) globalaccuracy(0.75))
	)

	(define "accuracy_mg_plane"
		("plane_range" r1(1.0) globalaccuracy(0.75))
	)
;/*----------- MoA Based Weapon Accuracy Model -----------*/
;Human MOA=0.0254* MOA * n * 1.05^n 
	(define "accuracy_1_MoA"
		("range"	r0(0.0263) r1(0.056) r2(0.0882) r3(0.1235) r4(0.1621) r5(0.204) r6(0.4137) globalaccuracy(6))
	)
	(define "accuracy_2_MoA"
		("range"	r0(0.0533) r1(0.112) r2(0.1764) r3(0.247) r4(0.3242) r5(0.4085) r6(0.8275) globalaccuracy(6))
	)
	(define "accuracy_3_MoA"
		("range"	r0(0.08) r1(0.168) r2(0.246) r3(0.3705) r4(0.4863) r5(0.6127) r6(1.24) globalaccuracy(6))
	)
	(define "accuracy_3_MoA_Pistol"
		("pistol_range"	r0(0.08) r1(0.168) r2(0.6127) globalaccuracy(6.75))
	)
	(define "accuracy_4_MoA"
		("range"	r0(0.1067) r1(0.224) r2(0.3528) r3(0.494) r4(0.6484) r5(0.8169) r6(1.655) globalaccuracy(6))
	)
	(define "accuracy_4_MoA_Pistol"
		("pistol_range"	r0(0.1067) r1(0.224) r2(0.8169) globalaccuracy(6.75))
	)
;/*----------- MoA Based Weapon Accuracy Model -----------*/

;/*=========================Curves======================*/


 	(define "range"
		{spreading
			{radiusTable {0 0.01} {25 (* %globalaccuracy %r0)} {50 (* %globalaccuracy %r1)} {75 (* %globalaccuracy %r2)} {100 (* %globalaccuracy %r3)} {125 (* %globalaccuracy %r4)} {150 (* %globalaccuracy %r5)} {250 (* %globalaccuracy %r6)}}
		}
	)
 	(define "pistol_range"
		{spreading
			{radiusTable {0 0.01} {25 (* %globalaccuracy %r0)} {50 (* %globalaccuracy %r1)} {150 (* %globalaccuracy %r2)}}
		}
	)
	(define "smg_range"
		{spreading
			{radiusTable {0 0.01} {20 (* %globalaccuracy %r0)} {40 (* %globalaccuracy %r1)} {60 (* %globalaccuracy %r2)} {80 (* %globalaccuracy %r3)} {100 (* %globalaccuracy %r4)} {120 (* %globalaccuracy %r5)} {200 (* %globalaccuracy %r6)}}
		}
	)
 	(define "rifle_range"
		{spreading
			{radiusTable {0 0.01} {30 %r0} {60 (* %globalaccuracy %r1)} {95 (* %globalaccuracy %r2)} {120 (* %globalaccuracy %r3)}}
		}
	)
	(define "sniper_range"
		{spreading
			{radiusTable {0 0.01} {30 %r0} {60 (* %globalaccuracy %r1)} {95 (* %globalaccuracy %r2)} {120 (* %globalaccuracy %r3)} {130 (* %globalaccuracy %r3)} {180 5}}
		}
	)
	(define "mg_range"
		{spreading
			{radiusTable {0 0.02} {40 (* %globalaccuracy %r1)} {80 (* %globalaccuracy %r2)} {110 (* %globalaccuracy %r3)} {120 (* %globalaccuracy %r3)} {180 5}}
		}
	)
	(define "hmg_range"
		{spreading
			{radiusTable {0 0.02} {40 (* %globalaccuracy %r1)} {80 (* %globalaccuracy %r2)} {110 (* %globalaccuracy %r3)} {140 (* %globalaccuracy %r3)} {200 5}}
		}
	)
	(define "plane_range"
		{spreading
			{radiusTable {0 1} {100 (* 3 (* %globalaccuracy %r1))} {200 (* 5 (* %globalaccuracy %r1))} {300 (* 8 (* %globalaccuracy %r1))} {400 (* 10 (* %globalaccuracy %r1))}}
		}
	)


;/*====================Slope Multiplier==================*/


	(define "ap_slope_multiplier"	;use for AP and for any other Projectiles not specifically defined below
		{overmatchCalibre
			{0		0.1			0.0637	}
			{5		0.96297		0.0637	}
			{10		0.98297		0.0637	}
			{15		1.00066		0.0969	}
			{20		1.0361		0.13561	}
			{25		1.1116		0.16164	}
			{30		1.2195		0.19702	}
			{35		1.3771		0.22546	}
			{40		1.6263		0.26313	}
			{45		2.0033		0.34717	}
			{50		2.6447		0.57353	}
			{55		3.231		0.69075	}
			{60		4.0708		0.81826	}
			{65		6.2655		0.9192	}
			{70		8.6492		1.00539	}
			{75		13.7512		1.074	}
			{80		21.8713		1.17973	}
			{85		34.4862		1.28631	}
			{90		99.0000		0.00000	}
		}
	)

	(define "apcr_slope_multiplier"	;use for APCR & HVAP Projectiles 76mm Caliber or below
		{overmatchFixed
			{0  1.00	}
			{10	1.01	}
			{10	1.03	}
			{15	1.07	}
			{20	1.13	}
			{25	1.23	}
			{30	1.36	}
			{35	1.59	}
			{40	1.90	}
			{45	2.28	}
			{50	2.78	}
			{55	3.41	}
			{60	4.23	}
			{65	5.29	}
			{70	6.69	}
			{75	8.52	}
			{80	10.93	}
			{85	14.15	}
			{90 99		}
		}
	)