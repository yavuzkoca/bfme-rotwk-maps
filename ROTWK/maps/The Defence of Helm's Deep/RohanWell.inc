

Object RohanWell

	RemoveModule ModuleTag_CostModifier
	ReplaceModule ModuleTag_SplashOfHealingWater_Ahh
		Behavior = PassiveAreaEffectBehavior ModuleTag_SplashOfHealingWater_AhhNEW
			EffectRadius			= GONDOR_WELL_AOE_RADIUS
			PingDelay			= 3000	;2000;msec
			HealPercentPerSecond		= 2%	;3%
			AllowFilter			= ANY +INFANTRY +CAVALRY -MACHINE -IMMOBILE +DOZER
			NonStackable			= Yes
			HealFX				= FX_SpellHealUnitHealBuff
		End
	End
	ReplaceModule BannerCarrierUpdateModuleTag
		Behavior = BannerCarrierUpdate BannerCarrierUpdateModuleTagNew
			IdleSpawnRate				= 10000	;5000							; spawn a new member every n seconds when idle (in miliseconds)		
			UnitSpawnFX				= FX_BannerCarrierSpawnUnit		; name of particle FX to use when the BannerCarrier spawns a new unit		
	
			; This well object acts like a banner carrier except it spawns unit on nearby hordes instead of itself.
			ReplenishNearbyHorde		= Yes
			ReplenishAllNearbyHordes	= Yes
			ScanHordeDistance		= GONDOR_WELL_AOE_RADIUS
		End
	End
END

