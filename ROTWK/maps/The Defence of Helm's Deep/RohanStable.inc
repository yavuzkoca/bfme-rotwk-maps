;----------------------------------------------
; Editing the Rohan Stable


;----------------------------------------------
;Upgrades

Upgrade Upgrade_RohanStableLevel2
	Type			= OBJECT
	BuildCost		= 500
	BuildTime		= 30
	DisplayName		= UPGRADE:RohanStableLevel2
End

Upgrade Upgrade_RohanStableLevel3
	Type			= OBJECT
	BuildCost		= 1000
	BuildTime		= 60
	DisplayName		= UPGRADE:RohanStableLevel3
End
;----------------------------------------------
;The object itself

Object RohanStable
	KindOf              = PRELOAD STRUCTURE SELECTABLE IMMOBILE SCORE NEED_BASE_FOUNDATION FS_FACTORY MP_COUNT_FOR_VICTORY AUTO_RALLYPOINT ATTACK_NEEDS_LINE_OF_SIGHT CAN_ATTACK MADE_OF_WOOD MONSTER
	CommandSet          = RohanStableCommandSetNew
	ReplaceModule ModuleTag_ShowWalls
		Behavior = SubObjectsUpgrade ModuleTag_ShowWallsNew 
			TriggeredBy		= Upgrade_RohanStableLevel2
			ShowSubObjects	= V1 V1A V2HIDE
			HideSubObjects	= V2 V2A
		End
	End
	ReplaceModule ModuleTag_ShowPillars 
		Behavior = SubObjectsUpgrade ModuleTag_ShowPillarsNew
			TriggeredBy		= Upgrade_RohanStableLevel3
			ShowSubObjects	= V2 V2A V1 V1A
			HideSubObjects	= V2HIDE
		End
	End
	ReplaceModule ModuleTag_ThirdLevelBuildingArrows
		Behavior = WeaponSetUpgrade ModuleTag_ThirdLevelBuildingArrowsNew
			TriggeredBy		= Upgrade_RohanStableLevel3
			ConflictsWith	= Upgrade_EasyAIMultiPlayer
		End
	End
	ReplaceModule Geom_ModuleTag_ShowWalls 
		Behavior = GeometryUpgrade Geom_ModuleTag_ShowWallsNew
			TriggeredBy		= Upgrade_RohanStableLevel2
			ShowGeometry	= Geom_Orig
			HideGeometry	= Geom_V2 
		End
	End
	ReplaceModule Geom_ModuleTag_ShowFlagsAndTower
		Behavior = GeometryUpgrade Geom_ModuleTag_ShowFlagsAndTowerNew
			TriggeredBy		= Upgrade_RohanStableLevel3
			ShowGeometry	= Geom_Orig Geom_V2
		End
	End
	ReplaceModule ProductionUpdateModuleTag
		Behavior = ProductionUpdate ProductionUpdateModuleTagNew
			NumDoorAnimations            = 1
			DoorOpeningTime              = 3250  ;in mSeconds how long you want doors to be in open state
			DoorWaitOpenTime             =13000  ;in mSeconds time the door stays open, so units can exit
			DoorCloseTime                = 4000  ;in mSeconds how long you want doors to be in open state
			ConstructionCompleteDuration = 0  ;in mSeconds   wait time so if you have multiple units they don't run over each other
			GiveNoXP		= Yes 
		End
	End
	AddModule
		Behavior = CommandSetUpgrade ModueTag_Level2CommandSet
			TriggeredBy			= Upgrade_RohanStableLevel2
			ConflictsWith		= Upgrade_RohanStableLevel3
			CommandSet			= RohanStableCommandSetNewLevel2
		End   
	End
	AddModule
		Behavior = CommandSetUpgrade ModueTag_Level3CommandSet
			TriggeredBy			= Upgrade_RohanStableLevel3		
			CommandSet			= RohanStableCommandSetNewLevel3
		End  
	End
	AddModule
		Behavior = LevelUpUpgrade ModuleTag_BarracksLevel2
			TriggeredBy    = Upgrade_RohanStableLevel2   
			LevelsToGain   = 1
			LevelCap       = 3
		End
	End
	AddModule
		Behavior = LevelUpUpgrade ModuleTag_BarracksLevel3
			TriggeredBy    = Upgrade_RohanStableLevel3     
			LevelsToGain   = 1
			LevelCap       = 3
		End
	End
END

;------------------------------------------
;CommandButtons

CommandButton Command_PurchaseUpgradeGondorStableLevel2
   Command           = OBJECT_UPGRADE
   Options           = CANCELABLE
   Upgrade           = Upgrade_RohanStableLevel2
   TextLabel         = CONTROLBAR:ConstructRohanStableLevel2Upgrade
   ButtonImage       = UCCommon_UpgradeStructureNew
   ButtonBorderType  = UPGRADE
   DescriptLabel     = CONTROLBAR:ToolTipBuildRohanStableLevel2Upgrade
   Radial            = Yes
   InPalantir        = Yes
End
CommandButton Command_PurchaseUpgradeGondorStableLevel3
   Command           = OBJECT_UPGRADE
   Upgrade           = Upgrade_RohanStableLevel3
   Options           = CANCELABLE
   TextLabel         = CONTROLBAR:ConstructRohanStableLevel2Upgrade
   ButtonImage       = UCCommon_UpgradeStructureNew
   ButtonBorderType  = UPGRADE
   DescriptLabel     = CONTROLBAR:ToolTipBuildRohanStableLevel2Upgrade
   Radial            = Yes
   InPalantir        = Yes
End
CommandButton Command_ConstructRohanRohirrimHorde
	Command					= UNIT_BUILD
	Object					= RohanRohirrimHorde
	Options					= CANCELABLE
	TextLabel				= CONTROLBAR:ConstructRohanRohirrimHorde
	ButtonImage				= BGStables_Rohirrim
	ButtonBorderType    	= BUILD 
	DescriptLabel       	= CONTROLBAR:ToolTipBuildRohanRohirrimHorde
	Radial					= Yes
	InPalantir	   			= Yes
	ShowProductionCount		= Yes      
End
CommandButton Command_ConstructRohanRohirrimArcherHorde
	Command				= UNIT_BUILD
	Object				= RohanRohirrimArcherHorde
	Options				= NEED_UPGRADE CANCELABLE
	NeededUpgrade		= Upgrade_RohanStableLevel2
	NeededUpgradeAny	= Yes
	TextLabel			= CONTROLBAR:ConstructRohanRohirrimArcherHorde
	ButtonImage			= BGStables_Rohirrim
	ButtonBorderType    = BUILD 
	DescriptLabel       = CONTROLBAR:ToolTipBuildRohanRohirrimArcherHorde
	Radial				= Yes
	InPalantir	   		= 	Yes
	ShowProductionCount	= Yes   
	LacksPrerequisiteLabel	= TOOLTIP:LackLevel2Stables
End
CommandButton Command_PurchaseTechnologyRohanHorseShield
	Command				= PLAYER_UPGRADE
	Options				= NEED_UPGRADE CANCELABLE
	Upgrade				= Upgrade_TechnologyRohanHorseShieldNew
	NeededUpgrade		= Upgrade_RohanStableLevel3
	TextLabel			= CONTROLBAR:PurchaseTechnologyRohanHorseShield
	ButtonImage			= BRArmory_Shields
	ButtonBorderType	= UPGRADE
	DescriptLabel		= CONTROLBAR:ToolTipPurchaseTechnologyRohanHorseShield
	Radial				= Yes
	InPalantir			= Yes
	LacksPrerequisiteLabel		= TOOLTIP:LackLevel3Stables
End
;------------------------------------------
;CommandSets


CommandSet RohanStableCommandSetNew
	1 = Command_ConstructRohanRohirrimHorde
	2 = Command_ConstructRohanRohirrimArcherHorde
	3 = Command_PurchaseTechnologyRohanHorseShield
	4 = Command_PurchaseUpgradeGondorStableLevel2
	6 = Command_Sell
End
CommandSet RohanStableCommandSetNewLevel2
	1 = Command_ConstructRohanRohirrimHorde
	2 = Command_ConstructRohanRohirrimArcherHorde
	3 = Command_PurchaseTechnologyRohanHorseShield
	4 = Command_PurchaseUpgradeGondorStableLevel3
	6 = Command_Sell
End
CommandSet RohanStableCommandSetNewLevel3
	1 = Command_ConstructRohanRohirrimHorde
	2 = Command_ConstructRohanRohirrimArcherHorde
	3 = Command_PurchaseTechnologyRohanHorseShield
	6 = Command_Sell
End

