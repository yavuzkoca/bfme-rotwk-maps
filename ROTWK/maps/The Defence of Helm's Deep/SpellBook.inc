Science SCIENCE_MenOfDaleAllies
  PrerequisiteSciences = SCIENCE_GOOD OR SCIENCE_MEN SCIENCE_CloudBreak OR SCIENCE_MEN SCIENCE_DunedainAllies
  SciencePurchasePointCost = 1
  SciencePurchasePointCostMP = 25
  IsGrantable = Yes
End

SpecialPower SpellBookMenOfDaleAllies ;Just to change the Sound
	Enum						= SPECIAL_SPELL_BOOK_MEN_OF_DALE_ALLIES
	RequiredSciences				= SCIENCE_MenOfDaleAllies
	ReloadTime					= SPELL_RECHARGE_TIME_TIER_4 ; in milliseconds
	InitiateAtLocationSound			= SpellElvenSummon
	RadiusCursorRadius			= 100.0
	Flags					= NO_FORBIDDEN_OBJECTS RESPECT_RECHARGE_TIME_DISCOUNT
	ForbiddenObjectFilter	= NO_SUMMON_NEAR_OBJECT_FILTER
	ForbiddenObjectRange	= 100.0
End

Object GoodSpellBook
	ReplaceModule ModuleTag_MenOfDaleAllies
		Behavior = OCLSpecialPower ModuleTag_MenOfDaleAlliesNew ;Elves Summon
			SpecialPowerTemplate = SpellBookMenOfDaleAllies
			OCL                  = OCL_SpawnMenOfDaleEgg
			TriggerFX			 = FX_DunedainSummon
			CreateLocation       = CREATE_AT_LOCATION
			UpgradeName			 = Upgrade_MenOfDaleAllies
			AvailableAtStart	 = No
			RequirementsFilterMPSkirmish = SPELL_BOOK_REQUIREMENTS_FILTER
			RequirementsFilterStrategic = SPELL_BOOK_REQUIREMENTS_FILTER_STRATEGIC
		End
	End
END
ChildObject MenSpellBook GoodSpellBook
	CommandSet          = MenSpellBookCommandSetNew
End
MappedImage BDArcheryRange_MenofDale ; Changing the image of Men of Dale to Elven warriors
  Texture = BuildingRadialButtons_149.tga
  TextureWidth = 256
  TextureHeight = 256
  Coords = Left:192 Top:128 Right:256 Bottom:192
  Status = NONE
End

CommandButton Command_SpellBookMenOfDaleAllies
	Command				= SPELL_BOOK
    SpecialPower		= SpellBookMenOfDaleAllies
    ButtonImage			= BDArcheryRange_MenofDale
	Options				= NEED_TARGET_POS ; Huh, you can't have this flag and a radius cursor: CONTEXTMODE_COMMAND
	TextLabel			= CONTROLBAR:SummonElvenAlliesNew
	ButtonBorderType	= ACTION 
	DescriptLabel		= CONTROLBAR:TooltipSummonElvenAlliesNew
	RadiusCursorType	= ElvenAlliesRadiusCursor
	CursorName          = AttackObj
	InvalidCursorName   = GenericInvalid
End

CommandButton Command_PurchaseSpellMenOfDaleAllies
	Command				= PURCHASE_SCIENCE
	ButtonBorderType	= UPGRADE 
    ButtonImage			= BDArcheryRange_MenofDale
    Science				= SCIENCE_MenOfDaleAllies
    TextLabel			= CONTROLBAR:SummonElvenAlliesNew
	DescriptLabel		= CONTROLBAR:TooltipSummonElvenAlliesNew
End

CommandSet MenSpellBookCommandSetNew
	1 = Command_SpellBookHeal
	2 = Command_SpellBookRallyingCall
	3 = Command_SpellBookRebuild
	
	4 = Command_SpellBookTomBombadil
	5 = Command_SpellBookHobbitAllies
	6 = Command_SpellBookLoneTower
	7 = Command_SpellBookArrowVolleyGood

	8 = Command_SpellBookCloudBreak
	9 = Command_SpellBookRohanAllies
	10 = Command_SpellBookDunedainAllies

	11 = Command_SpellBookMenOfDaleAllies
	12 = Command_SpellBookEarthquake
End
CommandSet MenSpellStoreCommandSetNew
	1 = Command_PurchaseSpellHeal
	2 = Command_PurchaseSpellRallyingCallMP
	3 = Command_PurchaseSpellRebuild
	
	4 = Command_PurchaseSpellHobbitAllies
	5 = Command_PurchaseSpellArrowVolleyGood
	6 = Command_PurchaseSpellTomBombadil
	7 = Command_PurchaseSpellLoneTowerMen

	8 = Command_PurchaseSpellDunedainAllies
	9 = Command_PurchaseSpellCloudBreak
	10 = Command_PurchaseSpellRohanAllies

	11 = Command_PurchaseSpellMenOfDaleAllies
	12 = Command_PurchaseSpellEarthquake
End

ObjectCreationList OCL_SpawnMenOfDaleEgg
	CreateObject
		ObjectNames = DwarvenMenOfDaleAlliesSummonEgg
		IgnoreCommandPointLimit = Yes
		Disposition = LIKE_EXISTING
	End
End
ObjectCreationList OCL_SpawnMenOfDale
	CreateObject
		ObjectNames = RohanElvenWarriorHorde_Summoned
		Count = 6
		FadeIn = Yes
		FadeTime = 8000
		IgnoreCommandPointLimit = Yes
		Disposition = SPAWN_AROUND
		DispositionAngle = 60	;SpawnAround uses this as the arc between guys
		DispositionIntensity = 500; and this for distance from center
	End
End
Object DwarvenMenOfDaleAlliesSummonEgg
	ReplaceModule ModuleTag_HatchProcess
		Behavior = SlowDeathBehavior ModuleTag_HatchProcessNew
			DestructionDelay = 2000
			OCL = FINAL OCL_SpawnMenOfDale
		End
	End
End



