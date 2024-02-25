{easy
	{unitset
		{value %period}
	}
	{balancingFactorBonus
		{cp 0.80}
		{mpStart 1.10}
		{mpFinish 0.8}
		{payback 0.8}
		{chargeDelay 1.0}	;// adjusts the inital delay only
		{charge 1.0}		;// adjusts the interval only
	}
	{unitScore 1.2}
}
{normal
	{unitset
		{value %period}
	}
	{balancingFactorBonus
		{cp 0.90}
		{mpStart 1.10}
		{mpFinish 0.90}
		{payback 0.90}
		{chargeDelay 1.0}	;// adjusts the inital delay only
		{charge 1.0}		;// adjusts the interval only
	}
	{unitScore 1.0}
}
{hard
	{unitset
		{value %period}
	}
	{balancingFactorBonus
		{cp 1.00}
		{mpStart 1.10}
		{mpFinish 1.25}
		{payback 3.50}
		{chargeDelay 1.0}	;// adjusts the inital delay only
		{charge 1.0}		;// adjusts the interval only
	}
	{unitScore 0.8}
}
{heroic
	{unitset
		{value %period}
	}
	{balancingFactorBonus
		{cp 1.20}
		{mpStart 1.10}
		{mpFinish 1.75}
		{payback 4.00}
		{chargeDelay 1.0}	;// adjusts the inital delay only
		{charge 1.0}		;// adjusts the interval only
	}
	{unitScore 0.5}
}
