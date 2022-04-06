Object RohanArcher
	WeaponSet
		Conditions = None 
		Weapon = PRIMARY    GondorArcherBow
		AutoChooseSources = PRIMARY FROM_PLAYER FROM_SCRIPT FROM_AI
	End
	WeaponSet
		Conditions = CLOSE_RANGE CONTESTING_BUILDING
		Weapon = PRIMARY   GondorArcherBowMelee
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
			GrantUpgrade	= Upgrade_RohanHeavyArmorForArchers
		End
	End
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeFour
			TriggeredBy		= Upgrade_RohanFireArrowsNew
			Delay			= 0
			GrantUpgrade	= Upgrade_GondorFireArrows
		End
	End
END

Object RohanArcherHorde	
	CommandSet = RohanArcherHordeCommandSetNew
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
			GrantUpgrade	= Upgrade_RohanHeavyArmorForArchers
		End
	End
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeFour
			TriggeredBy		= Upgrade_RohanFireArrowsNew
			Delay			= 0
			GrantUpgrade	= Upgrade_GondorFireArrows
		End
	End
	ReplaceModule ModuleTag_HordeContain
		Behavior = HordeContain ModuleTag_HordeContainNew
			ObjectStatusOfContained = 
			InitialPayload = RohanArcher GOOD_RIDER_LARGE_HORDE_SIZE
			Slots = 10
			PassengerFilter = NONE +INFANTRY
			ShowPips = No
			ThisFormationIsTheMainFormation = Yes	;Used to determine which armorset to use (and anything else we want!)
			AlternateFormation = RohanArcherHordeSkirmishFormation
	
			; Banner Carrier info		
			BannerCarriersAllowed	= RohanBanner										; types of units that are allowed as banner carriers
			BannerCarrierPosition	= UnitType:RohanArcher		Pos:X:20.0 Y:0.0		; (DEFAULT) position of banner carrier for archer horde
		
			; Positions for 5
			RandomOffset = X:0 Y:0
			RankInfo = RankNumber:1 UnitType:RohanArcher Position:X:0 Y:0	Position:X:0 Y:25		Position:X:0 Y:-25		Position:X:0 Y:50		Position:X:0 Y:-50 
			RankInfo = RankNumber:2 UnitType:RohanArcher Position:X:-20 Y:0 Leader 1 0	Position:X:-20 Y:25 Leader 1 1	Position:X:-20 Y:-25 Leader 1 2	Position:X:-20 Y:50 Leader 1 3	Position:X:-20 Y:-50 Leader 1 4

			RanksToReleaseWhenAttacking = 1 2

			; Example of Eva event for horde death
			;EvaEventLastMemberDeath = ArchersDie ; Play this Eva event when the last member dies
			MeleeAttackLeashDistance = 25; How far the hordes can move from the center of the horde when melee attacking.
			BackUpMinDelayTime		 = 1	//The minimum amount of	time to	delay before backing up
			BackUpMaxDelayTime		 = 3000	//The maximum amount of	time to	delay before backing up
			BackUpMinDistance		 = 1	//The minimum number of	cells to backup
			BackUpMaxDistance		 = 3	//The maximum number of	cells to backup
			BackupPercentage		 = 80%	//The amount of	chance that	a unit will	back up.
		End
	End
	
END

Object RohanArcherHordeSkirmishFormation
	CommandSet = RohanArcherHordeCommandSetNew
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
			GrantUpgrade	= Upgrade_RohanHeavyArmorForArchers
		End
	End
	ReplaceModule ModuleTag_HordeContain
		Behavior = HordeContain ModuleTag_HordeContainNew
			ObjectStatusOfContained = 
			InitialPayload = RohanArcher GOOD_RIDER_LARGE_HORDE_SIZE
			Slots = 10
			PassengerFilter = NONE +INFANTRY
			ShowPips = No
			ThisFormationIsTheMainFormation = No	;Used to determine which armorset to use (and anything else we want!)
			RandomOffset = X:7 Y:7
			
			; Banner Carrier info		
			BannerCarriersAllowed	= RohanBanner										; types of units that are allowed as banner carriers
			BannerCarrierPosition	= UnitType:RohanArcher	Pos:X:15.0 Y:0.0		; (DEFAULT) position of banner carrier
			
			RankInfo = RankNumber:1 UnitType:RohanArcher Position:X:0 Y:-40	 Position:X:-25 Y:-25	Position:X:0 Y:0	Position:X:-25 Y:25	 Position:X:0 Y:40 
			RankInfo = RankNumber:2 UnitType:RohanArcher Position:X:-20 Y:-40 Leader 1 0	Position:X:-45 Y:-25 Leader 1 1	Position:X:-20 Y:0 Leader 1 2	Position:X:-45 Y:25 Leader 1 3	Position:X:-20 Y:40 Leader 1 4
			
			
			RanksToReleaseWhenAttacking = 1 2
			AlternateFormation = RohanArcherHorde
			AttributeModifiers = RohanArcherSkirmish
		End
	End
END

CommandSet RohanArcherHordeCommandSetNew
	1 	= Command_ToggleStance
	2 	= Command_ToggleFormationRohanArcherHorde
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
