Object RohanRohirrimArcher
	CommandPoints 	= 8
	ButtonImage		= WOR_Rohirrim
	SelectPortrait	= UPGondor_Rohirrim
	WeaponSet
		Conditions = None 
		Weapon = PRIMARY    RohanArcherBow
		AutoChooseSources = PRIMARY FROM_PLAYER FROM_SCRIPT FROM_AI
	End
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeOne
			TriggeredBy		= Upgrade_RohanFireArrowsNew
			Delay			= 0
			GrantUpgrade	= Upgrade_RohanFireArrows
		End
	End
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeTwo
			TriggeredBy		= Upgrade_RohanBasicTrainingNew
			Delay			= 0
			GrantUpgrade	= Upgrade_RohanBasicTraining
		End
	End
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeThree
			TriggeredBy		= Upgrade_RohanHeavyArmorNew
			Delay			= 0
			GrantUpgrade	= Upgrade_RohanHeavyArmorForRohirrimArchers
		End
	End
	
	
END

Object RohanRohirrimArcherHorde
	CommandPoints = 80
	ButtonImage		= WOR_Rohirrim
	SelectPortrait	= UPGondor_Rohirrim
	CommandSet = RohirrimArcherHordeCommandSetNew
	ReplaceModule ModuleTag_HordeContain
		Behavior = HorseHordeContain ModuleTag_HordeContainNew
			ObjectStatusOfContained = 
			InitialPayload = RohanRohirrimArcher GOOD_RIDER_LARGE_HORDE_SIZE
			Slots = 10
			PassengerFilter = NONE +CAVALRY +RohanBanner
			ShowPips = No
			RandomOffset = X:0 Y:0
			ThisFormationIsTheMainFormation = Yes	;Used to determine which armorset to use (and anything else we want!)
	
			; Banner Carrier info		
			BannerCarriersAllowed	= RohanBanner										; types of units that are allowed as banner carriers
			BannerCarrierPosition	= UnitType:RohanRohirrimArcher	Pos:X:75.0 Y:0.0		; (DEFAULT) position of banner carrier for archer horde
		
			RankInfo = RankNumber:1 UnitType:RohanRohirrimArcher Position:X:45 Y:0		Position:X:45 Y:20		Position:X:45 Y:-20		Position:X:45 Y:40		Position:X:45 Y:-40 
			RankInfo = RankNumber:2 UnitType:RohanRohirrimArcher Position:X:10 Y:0 Leader 1 0	Position:X:10 Y:20 Leader 1 1	Position:X:10 Y:-20 Leader 1 2	Position:X:10 Y:40 Leader 1 3	Position:X:10 Y:-40 Leader 1 4

			RanksToReleaseWhenAttacking = 1 2
			AlternateFormation = RohanRohirrimArcherHordeWedgeFormation
			MeleeAttackLeashDistance = 1   //How far the hordes	can	move from the center of	the	horde when melee attacking.				  
			BackUpMinDelayTime		 = 1	//The minimum amount of	time to	delay before backing up
			BackUpMaxDelayTime		 = 3000	//The maximum amount of	time to	delay before backing up
			BackUpMinDistance		 = 1	//The minimum number of	cells to backup
			BackUpMaxDistance		 = 3	//The maximum number of	cells to backup
			BackupPercentage		 = 80%	//The amount of	chance that	a unit will	back up.
		End
	End
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeOne
			TriggeredBy		= Upgrade_RohanFireArrowsNew
			Delay			= 0
			GrantUpgrade	= Upgrade_RohanFireArrows
		End
	End
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeTwo
			TriggeredBy		= Upgrade_RohanBasicTrainingNew
			Delay			= 0
			GrantUpgrade	= Upgrade_RohanBasicTraining
		End
	End
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeThree
			TriggeredBy		= Upgrade_RohanHeavyArmorNew
			Delay			= 0
			GrantUpgrade	= Upgrade_RohanHeavyArmorForRohirrimArchers
		End
	End
	
END


Object RohanRohirrimArcherHordeWedgeFormation
	CommandSet = RohirrimArcherHordeCommandSetNew
	ReplaceModule ModuleTag_HordeContain
		Behavior = HorseHordeContain ModuleTag_HordeContainNew
			ObjectStatusOfContained = 
			InitialPayload = RohanRohirrimArcher GOOD_RIDER_LARGE_HORDE_SIZE
			Slots = 10
			PassengerFilter = NONE +CAVALRY +RohanBanner
			ShowPips = No
			RandomOffset = X:0 Y:0
			ThisFormationIsTheMainFormation = No	;Used to determine which armorset to use (and anything else we want!)
	
			; Banner Carrier info		
			BannerCarriersAllowed	= RohanBanner										; types of units that are allowed as banner carriers
			BannerCarrierPosition	= UnitType:RohanRohirrimArcher	Pos:X:30.0 Y:0.0		; (DEFAULT) position of banner carrier for archer horde
		
			RankInfo = RankNumber:1 UnitType:RohanRohirrimArcher Position:X:0 Y:0		Position:X:-30 Y:30		Position:X:-30 Y:-30		Position:X:-60 Y:60		Position:X:-60 Y:-60  
			RankInfo = RankNumber:2 UnitType:RohanRohirrimArcher Position:X:-35 Y:0 Leader 1 0	Position:X:-65 Y:30 Leader 1 1	Position:X:-65 Y:-30 Leader 1 2	Position:X:-95 Y:60 Leader 1 3	Position:X:-95 Y:-60 Leader 1 4

			RanksToReleaseWhenAttacking = 1 2
			AlternateFormation = RohanRohirrimArcherHorde
			AttributeModifiers = RohanHorseWegde
			MeleeAttackLeashDistance = 1   //How far the hordes	can	move from the center of	the	horde when melee attacking.				  
			BackUpMinDelayTime		 = 1	//The minimum amount of	time to	delay before backing up
			BackUpMaxDelayTime		 = 3000	//The maximum amount of	time to	delay before backing up
			BackUpMinDistance		 = 1	//The minimum number of	cells to backup
			BackUpMaxDistance		 = 3	//The maximum number of	cells to backup
			BackupPercentage		 = 80%	//The amount of	chance that	a unit will	back up.
		End
	End
	

END

CommandSet RohirrimArcherHordeCommandSetNew
	1 	= Command_ToggleStance
	2 	= Command_ToggleFormationRohirrimArcher
	3 	= Command_PorterConstructMordorTrollCage ;HeavyArmor
	4 	= Command_PorterConstructMordorHaradrimPalace  ;Fire Arrows
	5 	= Command_PorterConstructMordorFortress  ;Basic Training
	12 	= Command_CaptureBuilding
	13 	= Command_AttackMove
	14 	= Command_Stop
	16  	= Command_SetStanceBattle
	17  	= Command_SetStanceAggressive
	18  	= Command_SetStanceHoldGround
End
