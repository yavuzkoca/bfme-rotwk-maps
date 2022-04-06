;Making so that the tower will work as a BFME2 Tower
ChildObject RohanSentryTower GondorKeep
	SelectPortrait = BPRSentryTwr
	ButtonImage = BRSentryTwr
	RemoveModule ModuleTag_DrawFloor
	
	ReplaceModule ModuleTag_Draw
	Draw = W3DScriptedModelDraw ModuleTag_DrawNew
  
	ExtraPublicBone	= ARROWBONE01
	ExtraPublicBone	= ARROWBONE02
	ExtraPublicBone	= ARROWBONE03
	ExtraPublicBone	= ARROWBONE04
	ExtraPublicBone	= ARROWBONE05
	ExtraPublicBone	= ARROWBONE06
	ExtraPublicBone	= ARROWBONE07
	ExtraPublicBone	= ARROWBONE08
	ExtraPublicBone	= ARROWBONE09
	ExtraPublicBone	= ARROWBONE10
	ExtraPublicBone	= ARROWBONE11
	ExtraPublicBone	= ARROWBONE12
	ExtraPublicBone	= ARROWBONE13
	ExtraPublicBone	= ARROWBONE14
	ExtraPublicBone	= ARROWBONE15
	ExtraPublicBone	= ARROWBONE16

  
    OkToChangeModelColor  = Yes
    UseStandardModelNames = Yes
    DefaultModelConditionState
      Model = RBWatchTowM
      
	  WeaponLaunchBone =   PRIMARY ARROWBONE
      
    End
    
     ;------------ build up states---------------
    ModelConditionState   = AWAITING_CONSTRUCTION 
      Model               = RBWatchTowM_A
;		ParticleSysBone	  = NONE BuildingDoughnutCloud
    End;
    AnimationState        = AWAITING_CONSTRUCTION
      Animation           =  RBWatchTowM_A
        AnimationName     =  RBWatchTowM_A.RBWatchTowM_A
        AnimationMode     = MANUAL
        AnimationBlendTime = 0
      End
	  Flags				  = START_FRAME_FIRST
    End

    ModelConditionState   = ACTIVELY_BEING_CONSTRUCTED PARTIALLY_CONSTRUCTED
      Model               = RBWatchTowM_A
		ParticleSysBone   = CONSTDUSTBONE01 BuildingContructDust FollowBone:Yes
    End;
    
    AnimationState        = ACTIVELY_BEING_CONSTRUCTED PARTIALLY_CONSTRUCTED
		Animation           = RBWatchTowM_A
			AnimationName     = RBWatchTowM_A.RBWatchTowM_A
			AnimationMode     = MANUAL
			AnimationBlendTime = 0
		End
		Flags				  = START_FRAME_FIRST
		StateName			  = BeingConstructed
		BeginScript
			CurDrawablePlaySound("GondorBarracksBeginConstruction")
		EndScript
    End
    
       ;--damaged building

    
    ModelConditionState  = DAMAGED
      Model         =  RBWatchTowM_D1  
		ParticleSysBone FireSmall01 FireBuildingSmall
		ParticleSysBone FireSmall02 FireBuildingSmall
		ParticleSysBone FireSmall03 FireBuildingSmall
		ParticleSysBone FireSmall04 FireBuildingSmall
		ParticleSysBone FireMedium01 FireBuildingMedium
		ParticleSysBone FireMedium02 FireBuildingMedium
		ParticleSysBone FireLarge01 FireBuildingLarge
		ParticleSysBone SmokeLarge01 SmokeBuildingLarge
    End
    AnimationState = DAMAGED
	EnteringStateFX	= FX_BuildingDamaged
    End

    ModelConditionState  = REALLYDAMAGED
      Model         =  RBWatchTowM_D2  
		ParticleSysBone FireSmall01 FireBuildingSmall
		ParticleSysBone FireSmall02 FireBuildingSmall
		ParticleSysBone FireSmall03 FireBuildingSmall
		ParticleSysBone FireSmall04 FireBuildingSmall
		ParticleSysBone FireMedium01 FireBuildingMedium
		ParticleSysBone FireMedium02 FireBuildingMedium
		ParticleSysBone FireLarge01 FireBuildingLarge
		ParticleSysBone SmokeLarge01 SmokeBuildingLarge
    End
    AnimationState = REALLYDAMAGED
		EnteringStateFX	= FX_BuildingReallyDamaged
    End

    ModelConditionState  = RUBBLE
      Model         =  RBWatchTowM_D2 
      ParticleSysBone SmokeLarge01 SmokeBuildingLarge
    End
    
    AnimationState = RUBBLE
    End

    ModelConditionState  = POST_RUBBLE
		Model         = None
		ParticleSysBone NONE SmokeBuildingMediumRubble
    End

    ModelConditionState  = POST_COLLAPSE
		 Model         = None
		ParticleSysBone NONE SmokeBuildingMediumRubble
    End
  
  End
  End
	RemoveModule ModuleTag_Draw_HCBanner
	
	DisplayName         = OBJECT:RohanSentryTower
	Side                = MEN
	EditorSorting       = STRUCTURE
	ThreatLevel 		= 11.0
	IsTrainable			= No
		
	VoiceSelect		= RohanBattleTowerSelect

	SoundOnDamaged		= BuildingLightDamageWood
	SoundOnReallyDamaged	= BuildingHeavyDamageWood

	VoiceSelectUnderConstruction	= BuildingGoodVoiceSelectUnderConstruction
	
	GeometryContactPoint = X:23.624		Y:23.464	Z:0			Repair
	GeometryContactPoint = X:22.954		Y:-16.306	Z:0			Repair
	GeometryContactPoint = X:22.954		Y:15.951	Z:0
	GeometryContactPoint = X:5.435		Y:-23.279	Z:0
	GeometryContactPoint = X:-0.459		Y:-0.275	Z:116.828	Swoop

	Geometry              = BOX
	GeometryMajorRadius   = 11
	GeometryMinorRadius   = 11
	GeometryHeight        = 80
	GeometryIsSmall       = No
	Shadow                = SHADOW_VOLUME
	BuildCompletion     = PLACED_BY_PLAYER
	
END
