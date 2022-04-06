; Changes to the tower to make the Horn usable !!!

;special Power (to change duration and sound)
SpecialPower SpecialAbilityMenFortressIvoryTowerVision
	Enum				= SPECIAL_SPELL_BOOK_PALANTIR_VISION
	ReloadTime			= 120000 ; in milliseconds (CHANGE)
	InitiateAtLocationSound       = BoromirHorn
End

;adding the ability to the object
Object HelmsDeepTower
	KindOf              = PRELOAD STRUCTURE SELECTABLE IMMOBILE SCORE NOT_AUTOACQUIRABLE IGNORED_IN_GUI IGNORE_FOR_VICTORY NEVER_CULL_FOR_MP DONT_HIDE_IF_FOGGED CAN_ATTACK
	CommandSet			= HelmsDeepHorn
	AddModule
		Behavior = UnpauseSpecialPowerUpgrade ModuleTag_IvoryTowerVisionEnabler
			SpecialPowerTemplate = SpecialAbilityMenFortressIvoryTowerVision
			TriggeredBy = Upgrade_MenFortressIvoryTower
		End
	End
	AddModule
		Behavior				 = OCLSpecialPower ModuleTag_IvoryTowerVision
			SpecialPowerTemplate = SpecialAbilityMenFortressIvoryTowerVision
			StartsPaused		 = Yes
			OCL                  = SpecialPowerIvoryTowerVision
			CreateLocation       = CREATE_AT_LOCATION
		End
	End
END
;just in case it is necesary
ObjectCreationList SpecialPowerIvoryTowerVision
  CreateObject
    ObjectNames = IvoryTowerVisionPing
    Count = 1
  End
End
;the fake object that applies the bonus/malus
Object IvoryTowerVisionPing
	
	ReplaceModule ModuleTag_LifetimeUpdate
		Behavior = LifetimeUpdate ModuleTag_LifetimeUpdateNew
			MinLifetime		= 30000 ; 30sec
			MaxLifetime		= 30000
		End	
	End
	AddModule 
		Behavior = AttributeModifierAuraUpdate ModuleTag_DebuffOne
			StartsActive	= Yes				//If no, requires upgrade to turn on.
			TargetEnemy		= Yes
			AntiCategory	= LEADERSHIP BUFF
			BonusName		= GenericDebuff
			RefreshDelay	= 2000
			Range			= 99999.0
			ObjectFilter	= ANY +INFANTRY +CAVALRY -STRUCTURE -BASE_FOUNDATION  -HERO -HORDE
		End	
	End
	AddModule 
		Behavior = AttributeModifierAuraUpdate ModuleTag_Leadership
			StartsActive		= Yes ;If no, requires upgrade to turn on.
			BonusName		= GenericHeroLeadership
			RefreshDelay		= 2000
			Range			= 99999.0
			AntiCategory	= BUFF
			ObjectFilter		= GENERIC_BUFF_RECIPIENT_OBJECT_FILTER
		End
	End
	
End
;Change image of button
MappedImage BGFortress_UseIvoryTower ;Good_RallyingCall
  Texture = SpellBook_001.tga
  TextureWidth = 512
  TextureHeight = 256
  Coords = Left:256 Top:64 Right:320 Bottom:128
  Status = NONE
End
;The Button
CommandButton Command_SpecialAbilityIvoryTowerVision
	Command			= SPECIAL_POWER
	SpecialPower		= SpecialAbilityMenFortressIvoryTowerVision
	Options			= HIDE_WHILE_DISABLED ;NEED_TARGET_POS
    ButtonImage		= BGFortress_UseIvoryTower	
	TextLabel		= CONTROLBAR:HelmsHorn
	ButtonBorderType	= ACTION
	DescriptLabel		= CONTROLBAR:TooltipHelmsHorn
	RadiusCursorType    	= PalantirVisionRadiusCursor
	Radial			= Yes
	InPalantir		= Yes
End
;The CommandSet
CommandSet HelmsDeepHorn
	1	= Command_SpecialAbilityIvoryTowerVision
End


