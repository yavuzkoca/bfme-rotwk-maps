; Changing the superpower
SpecialPower SuperweaponSpawnOathbreakers
	Enum						   = SPECIAL_SPAWN_OATHBREAKERS
	ReloadTime					   = 180000	  ;	in milliseconds
	RadiusCursorRadius			   = 100.0
	Flags						   = LIMIT_DISTANCE NO_FORBIDDEN_OBJECTS
	MaxCastRange				   = 200
	ForbiddenObjectFilter		   = NO_SUMMON_NEAR_OBJECT_FILTER
	ForbiddenObjectRange		   = 100.0
	InitiateAtLocationSound			= SpellSummonDunedainAllies
End
;Button
MappedImage UCOathbreaker_OathTimer ;Dunedain Image
  Texture = SpellBook_001.tga
  TextureWidth = 512
  TextureHeight = 256
  Coords = Left:448 Top:64 Right:512 Bottom:128
  Status = NONE
End

CommandButton Command_SpawnOathbreakers
  Command           		= SPECIAL_POWER
  SpecialPower      		= SuperweaponSpawnOathbreakers
  TextLabel         		= CONTROLBAR:SummonDunedainAllies
  ButtonImage       		= UCOathbreaker_OathTimer
  Options           		= NEED_TARGET_POS CONTEXTMODE_COMMAND
  RadiusCursorType  		= DunedainAlliesRadiusCursor
  CursorName        		= AttackObj
  InvalidCursorName 		= GenericInvalid  
  ButtonBorderType  		= ACTION 
  DescriptLabel     		= CONTROLBAR:TooltipSummonDunedainAllies
  InPalantir	    		= Yes
End

CommandSet GondorAragornCommandSetNew
	1	= Command_ToggleStance
	2	= Command_SpecialAbility202Athelas ;;.;; Command_SpecialAbilityAthelas
	3	= Command_SpecialAbilityBladeMaster
	4 	= Command_AragornFakeLeadershipButton
	5 	= Command_SpecialAbilityElendil
	6 	= Command_SpawnOathbreakers
	12 	= Command_CaptureBuilding
	13 	= Command_AttackMove
	14 	= Command_Stop
	16  = Command_SetStanceBattle
	17  = Command_SetStanceAggressive
	18  = Command_SetStanceHoldGround
End


;Changing the object
Object GondorAragorn
	CommandSet = GondorAragornCommandSetNew
	ReplaceModule ModuleTag_OCLSpecialPower
		Behavior = OCLSpecialPower ModuleTag_OCLSpecialPowerNew
			SpecialPowerTemplate	= SuperweaponSpawnOathbreakers
			OCL						= OCL_SpawnDunedainRangersEgg
			TriggerFX			 	= FX_DunedainSummon
			CreateLocation			= CREATE_AT_LOCATION
			StartsPaused			= Yes
			SetModelCondition		= ModelConditionState:USER_1
			SetModelConditionTime	= 8.1
		End
	End
END

