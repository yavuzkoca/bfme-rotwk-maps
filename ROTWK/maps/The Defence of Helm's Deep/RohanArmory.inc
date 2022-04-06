;----------------------------------------------
; Editing the Rohan Armory




;-----------------------------------------------
;The armory itself

Object RohanArmory
	CommandSet =  RohanArmoryCommandSetNew
	KindOf     = PRELOAD STRUCTURE SELECTABLE IMMOBILE SCORE NEED_BASE_FOUNDATION MP_COUNT_FOR_VICTORY FS_FACTORY ATTACK_NEEDS_LINE_OF_SIGHT CAN_ATTACK MADE_OF_WOOD WEBBED
	
	ReplaceModule ModuleTag_ShowWalls
		Behavior = SubObjectsUpgrade ModuleTag_ShowWallsNew
			TriggeredBy		= Upgrade_GondorForgeLevel2
			ShowSubObjects	= V1 V1A 
			HideSubObjects	= V1HIDE V1AHIDE V2 V2A
		End
	End
	ReplaceModule Geom_ModuleTag_ShowWalls
		Behavior = GeometryUpgrade Geom_ModuleTag_ShowWallsNew 
			TriggeredBy		= Upgrade_GondorForgeLevel2
			ShowGeometry	= Geom_Orig Geom_V1
		End
	End
	ReplaceModule ModuleTag_ShowPillars
		Behavior = SubObjectsUpgrade ModuleTag_ShowPillarsNew 
			TriggeredBy		= Upgrade_GondorForgeLevel3
			ShowSubObjects	= V2 V2A
			HideSubObjects	= V1HIDE V1AHIDE V1 V1A 
		End
	End
	ReplaceModule ModuleTag_ThirdLevelBuildingArrows
		Behavior = WeaponSetUpgrade ModuleTag_ThirdLevelBuildingArrowsNew
			TriggeredBy		= Upgrade_GondorForgeLevel3
			ConflictsWith	= Upgrade_EasyAIMultiPlayer
		End
	End
	ReplaceModule ProductionUpdateModuleTag
		Behavior = ProductionUpdate ProductionUpdateModuleTagNew
			GiveNoXP		= Yes  
		End
	End
	AddModule
		Behavior = CommandSetUpgrade ModueTag_Level2CommandSet
			TriggeredBy			= Upgrade_GondorForgeLevel2
			ConflictsWith		= Upgrade_GondorForgeLevel3
			CommandSet			= RohanArmoryCommandSetNewLevel2
		End   
	End
	AddModule
		Behavior = CommandSetUpgrade ModueTag_Level3CommandSet
			TriggeredBy			= Upgrade_GondorForgeLevel3	
			CommandSet			= RohanArmoryCommandSetNewLevel3
		End  
	End
	AddModule
		Behavior = LevelUpUpgrade ModuleTag_BarracksLevel2
			TriggeredBy    = Upgrade_GondorForgeLevel2  
			LevelsToGain   = 1
			LevelCap       = 3
		End
	End
	AddModule
		Behavior = LevelUpUpgrade ModuleTag_BarracksLevel3
			TriggeredBy    = Upgrade_GondorForgeLevel3     
			LevelsToGain   = 1
			LevelCap       = 3
		End
	End
	
END
;--------------------------------------------------
;Button images

MappedImage BGBlacksmith_SilverTreeBanner ;Replacing with rohan version
  Texture = BuildingRadialButtons_124.tga
  TextureWidth = 256
  TextureHeight = 256
  Coords = Left:0 Top:192 Right:64 Bottom:256
  Status = NONE
End
;--------------------------------------------------
;Command buttons

CommandButton Command_PurchaseUpgradeGondorForgeLevel2
   Command           = OBJECT_UPGRADE
   Upgrade           = Upgrade_GondorForgeLevel2
   Options           = CANCELABLE
   TextLabel         = CONTROLBAR:ConstructRohanArmoryLevel2Upgrade
   ButtonImage       = UCCommon_UpgradeStructureNew
   ButtonBorderType  = UPGRADE
   DescriptLabel     = CONTROLBAR:ToolTipBuildRohanArmoryLevel2Upgrade
   Radial            = Yes
   InPalantir        = Yes
End

CommandButton Command_PurchaseUpgradeGondorForgeLevel3
   Command           = OBJECT_UPGRADE
   Upgrade           = Upgrade_GondorForgeLevel3
   Options           = CANCELABLE
   TextLabel         = CONTROLBAR:ConstructRohanArmoryLevel3Upgrade
   ButtonImage       = UCCommon_UpgradeStructureNew
   ButtonBorderType  = UPGRADE
   DescriptLabel     = CONTROLBAR:ToolTipBuildRohanArmoryLevel3Upgrade
   Radial            = Yes
   InPalantir        = Yes
End

CommandButton Command_PurchaseTechnologyGondorBasicTraining
	Command				= PLAYER_UPGRADE
	Options				= CANCELABLE
	Upgrade				= Upgrade_TechnologyRohanBasicTrainingNew
	TextLabel			= CONTROLBAR:PurchaseTechnologyGondorBasicTraining
	ButtonImage			= BGBlacksmith_SilverTreeBanner
	ButtonBorderType	= UPGRADE
	DescriptLabel		= CONTROLBAR:ToolTipPurchaseTechnologyGondorBasicTraining
	Radial				= Yes
	InPalantir			= Yes
	;LacksPrerequisiteLabel		= TOOLTIP:LackLevel2BlackSmithBanner
End
CommandButton Command_PurchaseTechnologyGondorForgedBlades
	Command				= PLAYER_UPGRADE
	Options				= NEED_UPGRADE CANCELABLE
	Upgrade				= Upgrade_TechnologyRohanForgedBladesNew
	NeededUpgrade		= Upgrade_GondorForgeLevel2
	TextLabel			= CONTROLBAR:PurchaseTechnologyGondorForgedBlades
	ButtonImage			= BRArmory_ForgedBlades
	ButtonBorderType	= UPGRADE
	DescriptLabel		= CONTROLBAR:ToolTipPurchaseTechnologyGondorForgedBlades
	Radial				= Yes
	InPalantir			= Yes
	LacksPrerequisiteLabel		= TOOLTIP:LackLevel2BlackSmithForgedBlades
End
CommandButton Command_PurchaseTechnologyGondorHeavyArmor
	Command				= PLAYER_UPGRADE
	Options				= NEED_UPGRADE CANCELABLE
	Upgrade				= Upgrade_TechnologyRohanHeavyArmorNew
	NeededUpgrade		= Upgrade_GondorForgeLevel3
	TextLabel			= CONTROLBAR:PurchaseTechnologyGondorHeavyArmor
	ButtonImage			= BGBlacksmith_HeavyArmor
	ButtonBorderType	= UPGRADE
	DescriptLabel		= CONTROLBAR:ToolTipPurchaseTechnologyGondorHeavyArmor
	Radial				= Yes
	InPalantir	   		= Yes
	LacksPrerequisiteLabel		= TOOLTIP:LackLevel2BlacksmithHeavyArmor
End



;--------------------------------------------------
;commandsets

CommandSet RohanArmoryCommandSetNew
	1 	= Command_PurchaseTechnologyGondorBasicTraining 
	2 	= Command_PurchaseTechnologyGondorForgedBlades
	3 	= Command_PurchaseTechnologyGondorHeavyArmor
	4 	= Command_PurchaseUpgradeGondorForgeLevel2
	6 	= Command_Sell
End

CommandSet RohanArmoryCommandSetNewLevel2
	1 	= Command_PurchaseTechnologyGondorBasicTraining 
	2 	= Command_PurchaseTechnologyGondorForgedBlades
	3 	= Command_PurchaseTechnologyGondorHeavyArmor
	4 	= Command_PurchaseUpgradeGondorForgeLevel3
	6 	= Command_Sell
End

CommandSet RohanArmoryCommandSetNewLevel3
	1 	= Command_PurchaseTechnologyGondorBasicTraining 
	2 	= Command_PurchaseTechnologyGondorForgedBlades
	3 	= Command_PurchaseTechnologyGondorHeavyArmor
	6 	= Command_Sell
End
