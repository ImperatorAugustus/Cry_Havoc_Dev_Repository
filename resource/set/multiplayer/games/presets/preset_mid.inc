; == mid WAR STANDARD RESOURCES ==
(define "standard_all"
	{common
		{unitset
			{value "mid^conquestonly|doctrineonly"}
		}
		{commandPoints "*=%cp"}
		(include "global_parameters/unitlimits.inc")
		{chargeFactors
			{value "*=1.00"}
		}
		(include "global_parameters/budget.inc" s(%start) f(%finish) d(%doctrine))
	}
	{bots
		(include "global_parameters/bots_generic.inc")
		("deploy_bots" period("mid"))
	}
)

; == mid WAR CUSTOM RESOURCES ==
(define "custom_all"
	{common
		{unitset
			{value "mid^conquestonly|doctrineonly"}
		}
		{commandPoints "*=%cp"}
		(include "global_parameters/unitlimits.inc")
		{chargeFactors
			{value "*=1.00"}
			{customize "0;0.25;0.5;1;2"}
		}
		(include "global_parameters/budget_custom.inc" s(%start) f(%finish) d(%doctrine))
	}
	{bots
		(include "global_parameters/bots_generic.inc")
		("deploy_bots" period("mid"))
	}
)

;------------------------------------------------------------------------------------------------------------
{presets
	{"s:mid_standard_100"
		{gameMode "standard"}
		{unitMode "mid"}
		{specMode "all_normal"}
		{apply "only_roster_mid"}
		("standard_all"			start(500) finish(10000) doctrine(100) cp(0:150,900:200))
	}
;------------------------------------------------------------------------------------------------------------
}