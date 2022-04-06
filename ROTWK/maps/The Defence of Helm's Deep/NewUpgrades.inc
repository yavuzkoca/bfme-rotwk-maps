;----------------------------------------------
;Upgrades Technologies

Upgrade Upgrade_TechnologyRohanBasicTrainingNew
	DisplayName       = UPGRADE:GondorBasicTraining
	Type              = PLAYER
	BuildCost		= ROHAN_TECH_BASIC_TRAINING_BUILDCOST
	BuildTime		= ROHAN_TECH_BASIC_TRAINING_BUILDTIME
	ResearchCompleteEvaEvent	= UpgradeBannerCarrierTechnologyReady		//RohanBannerVoiceSalute
End

Upgrade Upgrade_TechnologyRohanForgedBladesNew
	DisplayName       = UPGRADE:GondorForgedBlades
	Type              = PLAYER
	BuildCost		= ROHAN_TECH_FORGED_BLADES_BUILDCOST
	BuildTime		= ROHAN_TECH_FORGED_BLADES_BUILDTIME
	ResearchCompleteEvaEvent	= UpgradeForgedBladesReady
End
Upgrade Upgrade_TechnologyRohanHeavyArmorNew
	DisplayName       = UPGRADE:GondorHeavyArmor
	Type              = PLAYER
	BuildCost		= ROHAN_TECH_HEAVY_ARMOR_BUILDCOST
	BuildTime		= ROHAN_TECH_HEAVY_ARMOR_BUILDTIME
	ResearchCompleteEvaEvent	= UpgradeHeavyArmorReady
End

Upgrade Upgrade_TechnologyRohanHorseShieldNew
	DisplayName       = UPGRADE:GondorKnightShield
	Type              = PLAYER
	BuildCost		= ROHAN_TECH_HORSE_SHIELD_BUILDCOST
	BuildTime		= ROHAN_TECH_HORSE_SHIELD_BUILDTIME
	ResearchCompleteEvaEvent	= UpgradeHorseShieldsReady
End
Upgrade Upgrade_TechnologyRohanFireArrowsNew
	DisplayName       = UPGRADE:GondorFireArrowUpgrade
	Type              = PLAYER
	BuildCost		= ROHAN_TECH_FIRE_ARROWS_BUILDCOST
	BuildTime		= ROHAN_TECH_FIRE_ARROWS_BUILDTIME
	ResearchCompleteEvaEvent	= UpgradeFlameArrowsReady
	SkirmishAIHeuristic = AI_UPGRADEHEURISTIC_IMPORTANT
End

;----------------------------------------------
;Upgrades 
Upgrade Upgrade_RohanBasicTrainingNew
	DisplayName			= UPGRADE:GondorBasicTraining
	Type				= OBJECT
	Tooltip				= TOOLTIP:GondorBasicTraining
	BuildCost			= GONDOR_PERSONAL_BASIC_TRAINING_BUILDCOST
	BuildTime			= GONDOR_PERSONAL_BASIC_TRAINING_BUILDTIME
	ResearchCompleteEvaEvent		= UpgradeBannerCarrierReady			;GondorBannerVoiceSalute
	RequiredObjectFilter = NONE +WEBBED
	StrategicIcon		= AptStrategicUnitUpgradeBannerCarrier
End



Upgrade Upgrade_RohanForgedBladesNew
	DisplayName       = UPGRADE:GondorForgedBlades
	Type              = OBJECT
	Tooltip			= TOOLTIP:GondorForgedBlades
	BuildCost		= GONDOR_PERSONAL_FORGED_BLADES_BUILDCOST
	BuildTime		= GONDOR_PERSONAL_FORGED_BLADES_BUILDTIME
	ResearchSound	= UpgradeForgedBlades
	UpgradeFX		= FX_PorterDeliverForgedBlades
	RequiredObjectFilter = NONE +WEBBED
	StrategicIcon	= AptStrategicUnitUpgradeBlade
End

Upgrade Upgrade_RohanHeavyArmorNew
	DisplayName       = UPGRADE:GondorHeavyArmor
	Type              = OBJECT
	Tooltip			= TOOLTIP:GondorHeavyArmor
	BuildCost		= GONDOR_PERSONAL_HEAVY_ARMOR_BUILDCOST
	BuildTime		= GONDOR_PERSONAL_HEAVY_ARMOR_BUILDTIME
	ResearchSound	= UpgradeHeavyArmor
	UpgradeFX		= FX_PorterDeliverHeavyArmor
	ButtonImage     = BRArmory_HeavyArmor
	Cursor			= ArmorUpgrade
	RequiredObjectFilter = NONE +WEBBED
	StrategicIcon	= AptStrategicUnitUpgradeArmor
End

Upgrade Upgrade_RohanHorseShieldNew
	DisplayName       = UPGRADE:GondorKnightShield
	Type              = OBJECT
	Tooltip			  = TOOLTIP:GondorKnightShields
	BuildCost		  = GONDOR_PERSONAL_KNIGHT_SHIELD_BUILDCOST
	BuildTime	      = GONDOR_PERSONAL_KNIGHT_SHIELD_BUILDTIME
	ResearchSound	  = UpgradeHeavyArmor
	UpgradeFX		  = FX_PorterDeliverHorseShields
	RequiredObjectFilter = NONE +MONSTER
	StrategicIcon	= AptStrategicUnitUpgradeHorseShield
End
Upgrade Upgrade_RohanFireArrowsNew
	DisplayName       = UPGRADE:GondorFireArrowUpgrade
	Type              = OBJECT
	Tooltip			= TOOLTIP:GondorFlamingArrows
	BuildCost		= GONDOR_PERSONAL_FIRE_ARROWS_BUILDCOST
	BuildTime		= GONDOR_PERSONAL_FIRE_ARROWS_BUILDTIME
	ResearchSound	= UpgradeFlamingArrows
	UpgradeFX		= FX_PorterDeliverFlamingArrows
	RequiredObjectFilter = NONE +GIANT_BIRD
	StrategicIcon	= AptStrategicUnitUpgradeArrow
End

;New Buttons to buy them !!!
MappedImage BMFortress ;Basic Training
  Texture = BuildingRadialButtons_124.tga
  TextureWidth = 256
  TextureHeight = 256
  Coords = Left:0 Top:192 Right:64 Bottom:256
  Status = NONE
End
CommandButton Command_PorterConstructMordorFortress ;Basic Training
	Command				= OBJECT_UPGRADE
	Options				= NEED_UPGRADE OK_FOR_MULTI_SELECT CANCELABLE
	Upgrade				= Upgrade_RohanBasicTrainingNew  ;Upgrade_GondorBasicTraining
	NeededUpgrade		= Upgrade_TechnologyRohanBasicTrainingNew
	TextLabel			= CONTROLBAR:PurchaseUpgradeRohanBasicTraining
	ButtonImage			= BMFortress
	ButtonBorderType	= UPGRADE
	DescriptLabel		= CONTROLBAR:ToolTipPurchaseUpgradeRohanBasicTraining
	InPalantir			= Yes
	Radial				= No
	LacksPrerequisiteLabel		= TOOLTIP:LackRohanBasicTraining
End

MappedImage BMOrcPit ;Forged Blades
  Texture = BuildingRadialButtons_124.tga
  TextureWidth = 256
  TextureHeight = 256
  Coords = Left:192 Top:128 Right:256 Bottom:192
  Status = NONE
End

CommandButton Command_PorterConstructMordorOrcPit	 ;Forged Blades
	Command				= OBJECT_UPGRADE
	Options				= NEED_UPGRADE OK_FOR_MULTI_SELECT CANCELABLE
	Upgrade				= Upgrade_RohanForgedBladesNew ;Upgrade_GondorForgedBlades
	NeededUpgrade		= Upgrade_TechnologyRohanForgedBladesNew ;Rohirrim now combined with gondor to form Men of the West
	TextLabel			= CONTROLBAR:PurchaseUpgradeRohanForgedBlades
	ButtonImage			= BMOrcPit
	ButtonBorderType	= UPGRADE
	DescriptLabel		= CONTROLBAR:ToolTipPurchaseUpgradeRohanForgedBlades
	InPalantir			= Yes
	Radial				= No
	LacksPrerequisiteLabel		= TOOLTIP:LackRohanForgedBlades
End

MappedImage BMTrollCages ;Heavy Armor
  Texture = BuildingRadialButtons_124.tga
  TextureWidth = 256
  TextureHeight = 256
  Coords = Left:192 Top:64 Right:256 Bottom:128
  Status = NONE
End

CommandButton Command_PorterConstructMordorTrollCage ;Heavy Armor
	Command				= OBJECT_UPGRADE
	Options				= NEED_UPGRADE OK_FOR_MULTI_SELECT CANCELABLE
	Upgrade				= Upgrade_RohanHeavyArmorNew
	NeededUpgrade		= Upgrade_TechnologyRohanHeavyArmorNew
	TextLabel			= CONTROLBAR:PurchaseUpgradeRohanHeavyArmor
	ButtonImage			= BMTrollCages
	ButtonBorderType	= UPGRADE
	DescriptLabel		= CONTROLBAR:ToolTipPurchaseUpgradeRohanHeavyArmor
	InPalantir	   		= Yes
	Radial				= No
	LacksPrerequisiteLabel		= TOOLTIP:LackRohanHeavyArmor
End
MappedImage BMGreatSiegeWorks ;Shields
  Texture = BuildingRadialButtons_124.tga
  TextureWidth = 256
  TextureHeight = 256
  Coords = Left:192 Top:0 Right:256 Bottom:64
  Status = NONE
End

CommandButton Command_PorterConstructMordorSiegeWorks ;Shields
	Command				= OBJECT_UPGRADE
	Options				= NEED_UPGRADE OK_FOR_MULTI_SELECT CANCELABLE
	Upgrade				= Upgrade_RohanHorseShieldNew
	NeededUpgrade		= Upgrade_TechnologyRohanHorseShieldNew
	TextLabel			= UPGRADE:GondorKnightShield ;re used that from above =)
	ButtonImage			= BMGreatSiegeWorks
	ButtonBorderType	= UPGRADE
	DescriptLabel		= CONTROLBAR:ToolTipPurchaseUpgradeRohanHeavyArmor
	InPalantir	   		= Yes
	Radial				= No
	LacksPrerequisiteLabel		= TOOLTIP:LackRohanHeavyArmor
End

MappedImage BMHaradrimPalace ;fire Arrows
  Texture = BuildingRadialButtons_130.tga
  TextureWidth = 256
  TextureHeight = 256
  Coords = Left:192 Top:128 Right:256 Bottom:192
  Status = NONE
End

CommandButton Command_PorterConstructMordorHaradrimPalace ;fire Arrows
	Command				= OBJECT_UPGRADE
	Options				= NEED_UPGRADE OK_FOR_MULTI_SELECT CANCELABLE
	Upgrade				= Upgrade_RohanFireArrowsNew ;Upgrade_GondorFireArrows
	NeededUpgrade		= Upgrade_TechnologyRohanFireArrowsNew
	TextLabel			= CONTROLBAR:FireArrowUpgrade
	ButtonImage			= BMHaradrimPalace
	ButtonBorderType	= UPGRADE
	DescriptLabel		= CONTROLBAR:ToolTipPurchaseUpgradeRohanFireArrows
	InPalantir			= Yes
	Radial				= No
	LacksPrerequisiteLabel		= TOOLTIP:LackRohanFireArrows
End