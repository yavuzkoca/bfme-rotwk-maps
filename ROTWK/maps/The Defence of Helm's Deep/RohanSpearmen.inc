Object RohanSpearmen
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeOne
			TriggeredBy		= Upgrade_RohanBasicTrainingNew
			Delay			= 0
			GrantUpgrade	= Upgrade_RohanBasicTraining
		End
	End
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeTwo
			TriggeredBy		= Upgrade_RohanBasicTrainingNew
			Delay			= 0
			GrantUpgrade	= Upgrade_GondorBasicTraining
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
END

Object RohanSpearmenHorde
	CommandSet = RohanPikeCommandSetNew
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeOne
			TriggeredBy		= Upgrade_RohanBasicTrainingNew
			Delay			= 0
			GrantUpgrade	= Upgrade_RohanBasicTraining
		End
	End
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeTwo
			TriggeredBy		= Upgrade_RohanBasicTrainingNew
			Delay			= 0
			GrantUpgrade	= Upgrade_GondorBasicTraining
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
END
Object RohanSpearmenHordeHordePorcupine
	CommandSet = RohanPikeCommandSetNew
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeOne
			TriggeredBy		= Upgrade_RohanBasicTrainingNew
			Delay			= 0
			GrantUpgrade	= Upgrade_RohanBasicTraining
		End
	End
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeTwo
			TriggeredBy		= Upgrade_RohanBasicTrainingNew
			Delay			= 0
			GrantUpgrade	= Upgrade_GondorBasicTraining
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
END
CommandSet RohanPikeCommandSetNew
	1 	= Command_ToggleStance		
	2	= Command_RohanPorcupineFormation
	3 	= Command_PorterConstructMordorOrcPit	;Buy forged blades
	4 	= Command_PorterConstructMordorTrollCage 	;buy Heavy Armor
	5 	= Command_PorterConstructMordorFortress				;Buy Basic Training
	12 	= Command_CaptureBuilding
	13 	= Command_AttackMove
	14 	= Command_Stop
	16  	= Command_SetStanceBattle
	17  	= Command_SetStanceAggressive
	18  	= Command_SetStanceHoldGround
End