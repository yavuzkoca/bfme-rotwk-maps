Object RohanElvenWarrior
	
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeOne
			TriggeredBy		= Upgrade_RohanFireArrowsNew
			Delay			= 0
			GrantUpgrade	= Upgrade_GondorFireArrows
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
			GrantUpgrade	= Upgrade_GondorHeavyArmor
		End
	End
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeFour
			TriggeredBy		= Upgrade_RohanForgedBladesNew
			Delay			= 0
			GrantUpgrade	= Upgrade_GondorForgedBlades
		End
	End
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeSix
			TriggeredBy		= Upgrade_RohanBasicTrainingNew
			Delay			= 0
			GrantUpgrade	= Upgrade_RohanBasicTraining
		End
	End
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeSeven
			TriggeredBy		= Upgrade_RohanHeavyArmorNew
			Delay			= 0
			GrantUpgrade	= Upgrade_RohanHeavyArmorForElves
		End
	End
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeHeight
			TriggeredBy		= Upgrade_RohanForgedBladesNew
			Delay			= 0
			GrantUpgrade	= Upgrade_RohanForgedBladesForElves
		End
	End
END

Object RohanElvenWarriorHorde
CommandSet = RohanElvenWarriorHordeCommandSetNew
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeOne
			TriggeredBy		= Upgrade_RohanFireArrowsNew
			Delay			= 0
			GrantUpgrade	= Upgrade_GondorFireArrows
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
			GrantUpgrade	= Upgrade_GondorHeavyArmor
		End
	End
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeFour
			TriggeredBy		= Upgrade_RohanForgedBladesNew
			Delay			= 0
			GrantUpgrade	= Upgrade_GondorForgedBlades
		End
	End
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeSix
			TriggeredBy		= Upgrade_RohanBasicTrainingNew
			Delay			= 0
			GrantUpgrade	= Upgrade_RohanBasicTraining
		End
	End
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeSeven
			TriggeredBy		= Upgrade_RohanHeavyArmorNew
			Delay			= 0
			GrantUpgrade	= Upgrade_RohanHeavyArmorForElves
		End
	End
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeHeight
			TriggeredBy		= Upgrade_RohanForgedBladesNew
			Delay			= 0
			GrantUpgrade	= Upgrade_RohanForgedBladesForElves
		End
	End
	ReplaceModule ModuleTag_HordeContain
		Behavior = HordeContain ModuleTag_HordeContainNew
			ObjectStatusOfContained = 
			InitialPayload = RohanElvenWarrior GOOD_RIDER_LARGE_HORDE_SIZE
			Slots = 10
			PassengerFilter = NONE +INFANTRY
			ShowPips = No
			ThisFormationIsTheMainFormation = Yes	;Used to determine which armorset to use (and anything else we want!)
			RandomOffset = X:1 Y:1
			
			; Banner Carrier info		
			BannerCarriersAllowed	= RohanBanner										; types of units that are allowed as banner carriers
			BannerCarrierPosition	= UnitType:RohanElvenWarrior	Pos:X:35.0 Y:0.0	; (DEFAULT) position of banner carrier for elven warrior horde
			
			; Positions for 5
			RankInfo = RankNumber:1 UnitType:RohanElvenWarrior Position:X:13 Y:0	Position:X:13 Y:25		Position:X:13 Y:-25		Position:X:13 Y:50		Position:X:13 Y:-50 
			RankInfo = RankNumber:2 UnitType:RohanElvenWarrior Position:X:-5 Y:0 Leader 1 0	Position:X:-5 Y:25 Leader 1 1	Position:X:-5 Y:-25 Leader 1 2	Position:X:-5 Y:50 Leader 1 3	Position:X:-5 Y:-50 Leader 1 4
			
			RanksToReleaseWhenAttacking = 1 2
			MeleeAttackLeashDistance = 25; How far the hordes can move from the center of the horde when melee attacking.
			BackUpMinDelayTime		 = 1	//The minimum amount of	time to	delay before backing up
			BackUpMaxDelayTime		 = 3000	//The maximum amount of	time to	delay before backing up
			BackUpMinDistance		 = 1	//The minimum number of	cells to backup
			BackUpMaxDistance		 = 3	//The maximum number of	cells to backup
			BackupPercentage		 = 80%	//The amount of	chance that	a unit will	back up.
		End
	End
	
END

CommandSet RohanElvenWarriorHordeCommandSetNew
	1 	= Command_ToggleStance
	2 	= Command_ToggleElvenWarriorWeapon
	3 	= Command_PorterConstructMordorOrcPit	;Buy forged blades
	4 	= Command_PorterConstructMordorTrollCage ;Heavy Armor
	5 	= Command_PorterConstructMordorHaradrimPalace  ;Fire Arrows
	6 	= Command_PorterConstructMordorFortress  ;Basic Training
	13 	= Command_AttackMove
	14 	= Command_Stop
	16  	= Command_SetStanceBattle
	17  	= Command_SetStanceAggressive
	18  	= Command_SetStanceHoldGround
End

ChildObject RohanElvenWarrior_Summoned RohanElvenWarrior
	IsTrainable = No
	CommandPoints = 0
	EquivalentTo = RohanElvenWarrior
	AddModule
		Behavior = LifetimeUpdate ModuleTag_LifetimeUpdate
		; This one does the work, but the one in the horde displays the timer
			MinLifetime		= 180000
			MaxLifetime		= 180000
			DeathType		= FADED
		End	
	End
	AddModule
		Behavior = GrantUpgradeCreate ModuleTag_GrantFireArrows
			UpgradeToGrant = Upgrade_RohanFireArrows
		End
	End
	AddModule
		Behavior = GrantUpgradeCreate ModuleTag_GrantForgedBlades
			UpgradeToGrant = Upgrade_RohanForgedBlades
		End
	End
	AddModule
		Behavior = GrantUpgradeCreate ModuleTag_GrantHeavyArmor
			UpgradeToGrant = Upgrade_RohanHeavyArmor
		End
	End
	AddModule
		Behavior = GrantUpgradeCreate ModuleTag_GrantBasicTraining
			UpgradeToGrant = Upgrade_RohanBasicTraining
		End
	End
	AddModule
		Behavior = GrantUpgradeCreate ModuleTag_GrantFireArrowsNew
			UpgradeToGrant = Upgrade_GondorFireArrows
		End
	End
	AddModule
		Behavior = GrantUpgradeCreate ModuleTag_GrantForgedBladesNew
			UpgradeToGrant = Upgrade_GondorForgedBlades
		End
	End
	AddModule
		Behavior = GrantUpgradeCreate ModuleTag_GrantHeavyArmorNew
			UpgradeToGrant = Upgrade_GondorHeavyArmor
		End
	End
	AddModule
		Behavior = GrantUpgradeCreate ModuleTag_GrantBasicTrainingNew
			UpgradeToGrant = Upgrade_GondorBasicTraining
		End
	End
	
	
End

ChildObject RohanElvenWarriorHorde_Summoned RohanElvenWarriorHorde
	IsTrainable = No
	CommandPoints = 0
	CommandSet = RohanElvenWarriorHordeCommandSet_Summoned
	EquivalentTo = RohanElvenWarriorHorde

	KindOf = SELECTABLE CAN_ATTACK ATTACK_NEEDS_LINE_OF_SIGHT INFANTRY HORDE ARCHER MELEE_HORDE SUMMONED
	AddModule
		Behavior = LifetimeUpdate ModuleTag_LifetimeUpdate
		; This one displays the timer, but the one in the uint does the work 
			MinLifetime		= 180000
			MaxLifetime		= 180000
			DeathType		= FADED
		End	
	End
	AddModule
		Behavior = ExperienceLevelCreate ModuleTag_MPLevelBonus
			LevelToGrant = 5
			MPOnly = No
		End
	End
	ReplaceModule ModuleTag_HordeContain
		Behavior = HordeContain ModuleTag_HordeContainNewNew
			ObjectStatusOfContained = 
			InitialPayload = RohanElvenWarrior_Summoned GOOD_RIDER_LARGE_HORDE_SIZE
			Slots = 10
			PassengerFilter = NONE +INFANTRY
			ShowPips = No
			ThisFormationIsTheMainFormation = Yes	;Used to determine which armorset to use (and anything else we want!)
			RandomOffset = X:1 Y:1
			
			; Positions for 5
			RankInfo = RankNumber:1 UnitType:RohanElvenWarrior_Summoned Position:X:13 Y:0	Position:X:13 Y:25		Position:X:13 Y:-25		Position:X:13 Y:50		Position:X:13 Y:-50 
			RankInfo = RankNumber:2 UnitType:RohanElvenWarrior_Summoned Position:X:-5 Y:0 Leader 1 0	Position:X:-5 Y:25 Leader 1 1	Position:X:-5 Y:-25 Leader 1 2	Position:X:-5 Y:50 Leader 1 3	Position:X:-5 Y:-50 Leader 1 4
			
			RanksToReleaseWhenAttacking = 1 2
			MeleeAttackLeashDistance = 25; How far the hordes can move from the center of the horde when melee attacking.
			BackUpMinDelayTime		 = 1	//The minimum amount of	time to	delay before backing up
			BackUpMaxDelayTime		 = 3000	//The maximum amount of	time to	delay before backing up
			BackUpMinDistance		 = 1	//The minimum number of	cells to backup
			BackUpMaxDistance		 = 3	//The maximum number of	cells to backup
			BackupPercentage		 = 80%	//The amount of	chance that	a unit will	back up.
		End
	End
	
End
