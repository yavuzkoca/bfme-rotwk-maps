;----------------------------------------------
; Editing the Rohan Archer Range


;----------------------------------------------
;Upgrades

Upgrade Upgrade_RohanArcherRangeLevel2
	Type			= OBJECT
	BuildCost		= 500
	BuildTime		= 30
	DisplayName		= UPGRADE:RohanArcherRangeLevel2
End

Upgrade Upgrade_RohanArcherRangeLevel3
	Type			= OBJECT
	BuildCost		= 1000
	BuildTime		= 60
	DisplayName		= UPGRADE:RohanArcherRangeLevel3
End

;----------------------------------------------
;The object itself

Object RohanArcherRange
	KindOf              = PRELOAD STRUCTURE SELECTABLE IMMOBILE SCORE FS_FACTORY AUTO_RALLYPOINT MP_COUNT_FOR_VICTORY NEED_BASE_FOUNDATION ATTACK_NEEDS_LINE_OF_SIGHT CAN_ATTACK MADE_OF_WOOD GIANT_BIRD
	CommandSet          = RohanArcherRangeCommandSetNew
	
	ReplaceModule ModuleTag_ShowWalls
		Behavior = SubObjectsUpgrade ModuleTag_ShowWallsNew 
			TriggeredBy		= Upgrade_RohanArcherRangeLevel2
			ShowSubObjects	= V1 V1A
			HideSubObjects	= V2
		End
	End
	ReplaceModule ModuleTag_ShowPillars
		Behavior = SubObjectsUpgrade ModuleTag_ShowPillarsNew
			TriggeredBy		= Upgrade_RohanArcherRangeLevel3
			ShowSubObjects	= V1 V1A V2 
		End
	End
	ReplaceModule ModuleTag_ThirdLevelBuildingArrows
		Behavior = WeaponSetUpgrade ModuleTag_ThirdLevelBuildingArrowsNew
			TriggeredBy		= Upgrade_RohanArcherRangeLevel3
			ConflictsWith	= Upgrade_EasyAIMultiPlayer
		End
	End
	ReplaceModule Geom_ModuleTag_ShowWalls
		Behavior = GeometryUpgrade Geom_ModuleTag_ShowWallsNew
			TriggeredBy		= Upgrade_RohanArcherRangeLevel2
			ShowGeometry	= Geom_V1
			HideGeometry	= Geom_V2 Geom_V1A
		End
	End
	ReplaceModule Geom_ModuleTag_ShowPillars
		Behavior = GeometryUpgrade Geom_ModuleTag_ShowPillarsNew
			TriggeredBy		= Upgrade_RohanArcherRangeLevel3
			ShowGeometry	= Geom_V2
			HideGeometry	= Geom_V2A
		End
	End
	
	ReplaceModule ProductionUpdateModuleTag  ;So that it doesn't gain xp from producing troops
		Behavior = ProductionUpdate ProductionUpdateModuleTagNew
			GiveNoXP		= Yes    
		End
	End
	AddModule
		Behavior = CommandSetUpgrade ModueTag_Level2CommandSet
			TriggeredBy			= Upgrade_RohanArcherRangeLevel2
			ConflictsWith		= Upgrade_RohanArcherRangeLevel3
			CommandSet			= RohanArcherRangeCommandSetNewLevel2
		End   
	End
	AddModule
		Behavior = CommandSetUpgrade ModueTag_Level3CommandSet
			TriggeredBy			= Upgrade_RohanArcherRangeLevel3		
			CommandSet			= RohanArcherRangeCommandSetNewLevel3
		End  
	End
	AddModule
		Behavior = LevelUpUpgrade ModuleTag_BarracksLevel2
			TriggeredBy    = Upgrade_RohanArcherRangeLevel2     
			LevelsToGain   = 1
			LevelCap       = 3
		End
	End
	AddModule
		Behavior = LevelUpUpgrade ModuleTag_BarracksLevel3
			TriggeredBy    = Upgrade_RohanArcherRangeLevel3     
			LevelsToGain   = 1
			LevelCap       = 3
		End
	End
END
;------------------------------------------
;CommandButtons

CommandButton Command_PurchaseUpgradeGondorBarracksLevel2
   Command           = OBJECT_UPGRADE
   Options           = CANCELABLE
   Upgrade           = Upgrade_RohanArcherRangeLevel2
   TextLabel         = CONTROLBAR:ConstructRohanArcherRangeLevel2Upgrade
   ButtonImage       = UCCommon_UpgradeStructureNew
   ButtonBorderType  = UPGRADE
   DescriptLabel     = CONTROLBAR:ToolTipBuildRohanArcherRangeLevel2Upgrade
   Radial            = Yes
   InPalantir        = Yes
End
CommandButton Command_PurchaseUpgradeGondorBarracksLevel3
   Command           = OBJECT_UPGRADE
   Upgrade           = Upgrade_RohanArcherRangeLevel3
   Options           = CANCELABLE
   TextLabel         = CONTROLBAR:ConstructRohanArcherRangeLevel3Upgrade
   ButtonImage       = UCCommon_UpgradeStructureNew
   ButtonBorderType  = UPGRADE
   DescriptLabel     = CONTROLBAR:ToolTipBuildRohanArcherRangeLevel3Upgrade
   Radial            = Yes
   InPalantir        = Yes
End

CommandButton Command_ConstructRohanElvenWarriorHorde
	Command				= UNIT_BUILD
	Object				= RohanElvenWarriorHorde
	TextLabel			= CONTROLBAR:ConstructElvenWarriorHorde
	ButtonImage			= BEElvenBarracks_LorienWarrior
	ButtonBorderType		= BUILD 
	DescriptLabel			= CONTROLBAR:ToolTipBuildElvenWarriorHorde
	Radial				= Yes
	InPalantir	   		= Yes
	IsClickable			= Yes
	Options				= NEED_UPGRADE CANCELABLE
	NeededUpgrade		= Upgrade_StructureLevel2
	ShowProductionCount	= Yes    
	LacksPrerequisiteLabel		= TOOLTIP:LackLevel2ArcheryRange
End

CommandButton Command_PurchaseTechnologyRohanFireArrows
	Command				= PLAYER_UPGRADE
	Options				= NEED_UPGRADE CANCELABLE
	Upgrade				= Upgrade_TechnologyRohanFireArrowsNew
	NeededUpgrade		= Upgrade_StructureLevel3
	TextLabel			= CONTROLBAR:PurchaseTechnologyRohanFireArrows
	ButtonImage			= BRArcheryRange_FireArrows
	ButtonBorderType	= UPGRADE
	DescriptLabel		= CONTROLBAR:ToolTipPurchaseTechnologyRohanFireArrows
	Radial				= Yes
	InPalantir			= Yes
	LacksPrerequisiteLabel		= TOOLTIP:LackLevel3ArcheryRange
End
;------------------------------------------
;CommandSets

CommandSet RohanArcherRangeCommandSetNew
	1 = Command_ConstructRohanArcherHorde
	2 = Command_ConstructRohanElvenWarriorHorde
	3 = Command_PurchaseTechnologyRohanFireArrows
	4 = Command_PurchaseUpgradeGondorBarracksLevel2
	6 = Command_Sell
End
CommandSet RohanArcherRangeCommandSetNewLevel2
	1 = Command_ConstructRohanArcherHorde
	2 = Command_ConstructRohanElvenWarriorHorde
	3 = Command_PurchaseTechnologyRohanFireArrows
	4 = Command_PurchaseUpgradeGondorBarracksLevel3
	6 = Command_Sell
End
CommandSet RohanArcherRangeCommandSetNewLevel3
	1 = Command_ConstructRohanArcherHorde
	2 = Command_ConstructRohanElvenWarriorHorde
	3 = Command_PurchaseTechnologyRohanFireArrows
	6 = Command_Sell
End


