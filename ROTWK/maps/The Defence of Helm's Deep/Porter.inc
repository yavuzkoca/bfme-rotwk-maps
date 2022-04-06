; Editing the Men Porter !!!





;---------------------------------------
;The porter itself !
Object MenPorter
	CommandSet = MenPorterCommandSetNew
END
;-----------------------------------------------
;Images for the buttons of the porter
MappedImage BRArmory
  Texture = BuildingRadialButtons_124.tga
  TextureWidth = 256
  TextureHeight = 256
  Coords = Left:64 Top:192 Right:128 Bottom:256
  Status = NONE
End

MappedImage BRArcheryRange
  Texture = BuildingRadialButtons_130.tga
  TextureWidth = 256
  TextureHeight = 256
  Coords = Left:0 Top:192 Right:64 Bottom:256
  Status = NONE
End

MappedImage BRStables
  Texture = BuildingRadialButtons_212.tga
  TextureWidth = 64
  TextureHeight = 64
  Coords = Left:0 Top:0 Right:64 Bottom:64
  Status = NONE
End

MappedImage BCFarm
  Texture = BuildingRadialButtons_076.tga
  TextureWidth = 256
  TextureHeight = 256
  Coords = Left:192 Top:0 Right:256 Bottom:64
  Status = NONE
End
;-----------------------------------------
;Buttons for the proter (TIP: in the buttons you can't actually change their images, the game will use the original ones, 
;							thus you have to use an existing button and change the image itself pointing it toward the image you want)

CommandButton Command_ConstructRohanArmory
  Command          = DOZER_CONSTRUCT
  Object           = RohanArmory
  TextLabel        = CONTROLBAR:ConstructRohanArmory
  ButtonImage      = BRArmory                                
  ButtonBorderType = BUILD 
  DescriptLabel    = CONTROLBAR:ToolTipRohanArmory
  Radial           = Yes  
End

CommandButton Command_ConstructRohanArcherRange
  Command          = DOZER_CONSTRUCT
  Object           = RohanArcherRange
  TextLabel        = CONTROLBAR:ConstructRohanArcherRange
  ButtonImage      = BRArcheryRange
  ButtonBorderType = BUILD 
  DescriptLabel    = CONTROLBAR:ToolTipRohanArcherRange
  Radial           = Yes  
End

CommandButton Command_ConstructRohanStable
  Command          = DOZER_CONSTRUCT
  Object           = RohanStable
  TextLabel        = CONTROLBAR:ConstructRohanStable
  ButtonImage      = BRStables
  ButtonBorderType = BUILD 
  DescriptLabel    = CONTROLBAR:ToolTipRohanStable
  Radial           = Yes  
End

CommandButton Command_ConstructRohanFarm
  Command          = DOZER_CONSTRUCT
  Object           = RohanFarm
  TextLabel        = CONTROLBAR:ConstructRohanFarm
  ButtonImage      = BCFarm
  ButtonBorderType = BUILD 
  DescriptLabel    = CONTROLBAR:ToolTipRohanFarm
  Radial           = Yes  
End
CommandButton Command_ConstructRohanSentryTower
  Command          = DOZER_CONSTRUCT
  Object           = RohanSentryTower
  TextLabel        = CONTROLBAR:ConstructRohanSentryTower
  ButtonImage      = BRSentryTwr
  ButtonBorderType = BUILD 
  DescriptLabel    = CONTROLBAR:ToolTipRohanBuildSentryTower
  Radial           = Yes  
End
CommandButton Command_PorterConstructMenWell
	Command				= DOZER_CONSTRUCT
	Object				= RohanWell
	TextLabel			= CONTROLBAR:ConstructMenWell
	ButtonImage			= BGWell
	ButtonBorderType	= BUILD 
	DescriptLabel		= OBJECT:HearthWellDescription
	Radial				= Yes
	;InPalantir	   		= Yes
End
CommandButton Command_PorterConstructMenStatue
	Command				= DOZER_CONSTRUCT
	Object				= RohanHeroStatue
	TextLabel			= CONTROLBAR:ConstructMenStatue
	ButtonImage			= BGHeroicStatue
	ButtonBorderType	= BUILD 
	DescriptLabel		= OBJECT:HeroicStatueDescription
	Radial				= Yes  
	;InPalantir			= Yes
End

;----------------------------------------
;Set of actions available for the porter
CommandSet MenPorterCommandSetNew
   1  = Command_Stop
   2  = Command_PorterExtinguishFire
   3  = Command_ConstructRohanFarm
   4  = Command_ConstructRohanStable
   5  = Command_ConstructRohanArcherRange
   6  = Command_ConstructRohanArmory
   7  = Command_ConstructRohanSentryTower
   8  = Command_PorterConstructMenWell
   9 = Command_PorterConstructMenStatue

End