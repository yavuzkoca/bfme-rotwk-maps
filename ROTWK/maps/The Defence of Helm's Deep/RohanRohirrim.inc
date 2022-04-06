Object RohanRohirrim
	CommandSet 	= RohanRohirrimCommandSetNEW
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeOne
			TriggeredBy		= Upgrade_RohanHorseShieldNew
			Delay			= 0
			GrantUpgrade	= Upgrade_RohanHorseShield
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
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeFour
			TriggeredBy		= Upgrade_RohanForgedBladesNew
			Delay			= 0
			GrantUpgrade	= Upgrade_RohanForgedBladesForRohirrim
		End
	End
	
	ReplaceModule Armor_Upgrade
		Behavior = SubObjectsUpgrade Armor_UpgradeNew
			TriggeredBy				= Upgrade_RohanHeavyArmorNew
			UpgradeTexture			= RURohrm01.tga 0 RURohrm01HA.tga
			UpgradeTexture			= RURohrm02.tga 0 RURohrm02HA.tga
			UpgradeTexture			= RURohrm03.tga 0 RURohrm03HA.tga
			UpgradeTexture			= RURohrm04.tga 0 RURohrm04HA.tga
			
			UpgradeTexture			= RUHorse01.tga 0 RUHorse01HA.tga
			UpgradeTexture			= RUHorse02.tga 0 RUHorse02HA.tga
			UpgradeTexture			= RUHorse03.tga 0 RUHorse03HA.tga
			UpgradeTexture			= RUHorse04.tga 0 RUHorse04HA.tga
	
			RecolorHouse			= Yes
			ExcludeSubobjects		= Forged_Blade
		End
	End
	
END

Object RohanRohirrimHorde
	CommandSet = RohirrimHordeCommandSetNEW
	RemoveModule ModuleTag_CommandSetSwapper
	
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeOne
			TriggeredBy		= Upgrade_RohanHorseShieldNew
			Delay			= 0
			GrantUpgrade	= Upgrade_RohanHorseShield
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
	AddModule
		Behavior = ObjectCreationUpgrade AddUpgradeFour
			TriggeredBy		= Upgrade_RohanForgedBladesNew
			Delay			= 0
			GrantUpgrade	= Upgrade_RohanForgedBladesForRohirrim
		End
	End
	
END

CommandSet RohanRohirrimCommandSetNEW
	1	= Command_ToggleStance 	
	;2 = Command_ToggleRohirrimWeapon
	13	= Command_AttackMove
	14	= Command_Stop
	16  	= Command_SetStanceBattle
	17  	= Command_SetStanceAggressive
	18  	= Command_SetStanceHoldGround
End

CommandSet RohirrimHordeCommandSetNEW
	1 = Command_ToggleStance
	2 = Command_PorterConstructMordorSiegeWorks ; Buy shields
	3 = Command_PorterConstructMordorOrcPit	;Buy forged blades
	4 = Command_PorterConstructMordorTrollCage 	;buy Heavy Armor
	5 = Command_PorterConstructMordorFortress				;Buy Basic Training
	12 = Command_CaptureBuilding
	13 = Command_AttackMove
	14 = Command_Stop
	16  = Command_SetStanceBattle
	17  = Command_SetStanceAggressive
	18  = Command_SetStanceHoldGround
End
