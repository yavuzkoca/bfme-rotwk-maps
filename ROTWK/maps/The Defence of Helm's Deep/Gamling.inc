CommandButton Command_RohanGimliLeap
  Command			= SPECIAL_POWER 
  SpecialPower			= SpecialAbilityGimliLeap
  Options			= NEED_TARGET_POS CONTEXTMODE_COMMAND
  TextLabel			= CONTROLBAR:NewGimliLeap
  ButtonImage			= HSGimliLeap
  RadiusCursorType		= LeapRadiusCursor
  CursorName			= Bombard
  ButtonBorderType		= ACTION 
  DescriptLabel			= CONTROLBAR:ToolTipNewGimliLeap
  InPalantir			= Yes
End

CommandButton Command_RohanEomerHorseLordLeadership
  Command                 = SPECIAL_POWER
  SpecialPower            = SpecialAbilityCreateAHeroShieldCrush_Level3
  Options				  = NONE
  TextLabel               = CONTROLBAR:HorseMaster
  ButtonImage             = HSEomerLeadership
  RadiusCursorType        = TrainingRadiusCursor
  ButtonBorderType        = ACTION
  DescriptLabel           = CONTROLBAR:ToolTipHorseMaster
  InPalantir		  = Yes
End

CommandButton Command_SpecialAbilitySummonHillmen1
  Command           = SPECIAL_POWER
  SpecialPower      = SpecialAbilityHwaldarSummonHillmen1
  TextLabel         = CONTROLBAR:GamGuard
  ButtonImage       = HISummonHillmenIcon
  Options           = NEED_TARGET_POS CONTEXTMODE_COMMAND
  RadiusCursorType  = SummonWildmen2RadiusCursor ;SummonOathBreakersRadiusCursor
  CursorName        = Bombard
  InvalidCursorName = GenericInvalid  
  ButtonBorderType  = ACTION 
  DescriptLabel     = CONTROLBAR:ToolTipGamGuard
  InPalantir	    = Yes
End
CommandButton Command_GothmogIronHand						; Added for BFME2 Expansion
  Command                 	= SPECIAL_POWER
  SpecialPower            	= SpecialAbilityFakeLeadership
  Options			= NONPRESSABLE
  TextLabel               	= CONTROLBAR:GamLoyal
  ButtonImage            	= HSKingDainStubbornPride
  RadiusCursorType        	= IronHandRadiusCursor ;SpeechCraftRadiusCursor
  ButtonBorderType        	= ACTION
  DescriptLabel           	= CONTROLBAR:ToolTipGamLoyal
  InPalantir		  	= Yes
End
CommandButton Command_RohanEomerOutlawLeadership
  Command                 = SPECIAL_POWER
  SpecialPower            = SpecialAbilityFakeLeadership2
  Options				  = NONPRESSABLE
  TextLabel               = CONTROLBAR:MoneyOutOfEnemies
  ButtonImage             = UCCommon_Pillage
  RadiusCursorType        = TrainingRadiusCursor
  ButtonBorderType        = ACTION
  DescriptLabel           = CONTROLBAR:ToolTipMoneyOutOfEnemies
  InPalantir		  = Yes
End
CommandSet NewGamlingCommandSet;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;DONE FINAL
	1	= Command_RohanGimliLeap;;;RogashLeap
	2	= Command_RohanEomerHorseLordLeadership;;;;CreateAHero_ShieldCrush_Level3
	3 	= Command_RohanEomerOutlawLeadership
	4	= Command_SpecialAbilitySummonHillmen1;;hammer/blademasterSpecialAbilitySummonHillmen1
	5	= Command_GothmogIronHand;;steadfast loyalty
	12 	= Command_CaptureBuilding
	13	= Command_AttackMove
	14	= Command_Stop
End

Weapon NewGamlingSword
  LeechRangeWeapon      = Yes
  AttackRange           = STANDARD_MELEE_ATTACK_RANGE
	RadiusDamageAffects = ENEMIES NOT_SIMILAR
  MeleeWeapon           = Yes
  DelayBetweenShots     = GAMLING_DELAYBETWEENSHOTS 			
             ; time between shots, msec
  PreAttackDelay        = GAMLING_PREATTACKDELAY 				; 400 is sword swing delay time before contact with target.
  PreAttackType         = PER_SHOT ; Do the delay each time we attack a new target
  FireFX                = FX_GondorSwordHit
  FiringDuration        = GAMLING_FIRINGDURATION 				; Duration of the sword swing

	DamageNugget                        ; A basic Nugget that just does damage
		Damage        = 130					
		Radius        = 30.0 ;
		DelayTime     = 200
		DamageType    = HERO
		DamageFXType  = SWORD_SLASH
		DeathType     = NORMAL
		DamageSpeed		= 700.0 ; must match the ShockWaveSpeed below
	End
	DOTNugget                        ; 30s time.
		Damage        = 20 ; default is 300
		AcceptDamageAdd = No
		Radius        = 20.0
		DelayTime     = 0
		DamageType    = MAGIC
		DamageFXType  = MAGIC
		DeathType     = NORMAL
		DamageInterval = 1000
		DamageDuration = 30000
		SpecialObjectFilter = AFFECTED_BY_POISON_OBJECTFILTER
	End
	MetaImpactNugget                    ; A Nugget that throws things back with force
		HeroResist			= .75
		ShockWaveAmount   = 30.0
		ShockWaveRadius   = 10.0
		ShockWaveTaperOff = 1  ;0.75
		ShockWaveZMult    = 0.75
		ShockWaveSpeed		= 700
	End  
End

SpecialPower SpecialAbilityHwaldarSummonHillmen1
	Enum							= SPECIAL_SPELL_BOOK_MEN_OF_DALE_ALLIES
	ReloadTime						= 210000	  ;	in milliseconds
	RadiusCursorRadius				= 90.0
	InitiateAtLocationSound			= SpellRohirrimSummonMS
	Flags							= NO_FORBIDDEN_OBJECTS LIMIT_DISTANCE
	ForbiddenObjectFilter			= NO_SUMMON_NEAR_OBJECT_FILTER
	ForbiddenObjectRange			= 100
	MaxCastRange					= 150
End

Object RohanGamling
	ShockwaveResistance = SHOCKWAVE_RESISTANCE_IMMUNE
	CommandPoints = 0
	
	SelectPortrait = UPGondor_Rohirrim
	ButtonImage = hicahdamrod
	
	RadarPriority = UNIT
	KindOf = HERO PRELOAD SELECTABLE CAN_CAST_REFLECTIONS INFANTRY PATH_THROUGH_EACH_OTHER SCORE CAN_ATTACK ATTACK_NEEDS_LINE_OF_SIGHT ARMY_SUMMARY HEAVY_MELEE_HITTER
	RecruitText = CONTROLBAR:RohanGamlingRecruitNew
	ReviveText	= CONTROLBAR:RohanGamlingReviveNew
	Hotkey		= CONTROLBAR:RohanGamlingHotkeyNew
	
	CommandSet = NewGamlingCommandSet
	
	ReplaceModule ModuleTag_DRAW
		Draw = W3DScriptedModelDraw ModuleTag_DRAW_NEW
	
	StaticModelLODMode = yes ; Will append M or L to the skin name depending on GameLOD
	
		OkToChangeModelColor = Yes
	
			DefaultModelConditionState
				Model               = RUGamling_SKN
				ParticleSysBone = B_SWORDBONE GamlingSwordglow FollowBone:Yes
			End	
			ModelConditionState = WEAPONSET_HERO_MODE;
				ParticleSysBone = BAT_RIBS GamBladeMaster FollowBone:Yes
				ParticleSysBone = BAT_RIBS FloodWaterHit FollowBone:Yes
				ParticleSysBone = BAT_HHEAD GCglowHorseWhite FollowBone:Yes
				ParticleSysBone = B_HHIPL GCglowHorseRearWhite FollowBone:Yes
				ParticleSysBone = BAT_SPINE2 GCglowWhite FollowBone:Yes
			End
	
			; --- Idle Anims
			IdleAnimationState
				StateName = Idle			
	;			Animation           = IDLA
	;				AnimationName     = GUBoromir_SKL.GUBoromir_IDLA 0 15
	;				AnimationMode     = ONCE
	;			End			
				Animation           = IDLB
					AnimationName     = GUBoromir_SKL.GUBoromir_IDLB
					AnimationMode     = ONCE
					AnimationPriority   = 20
				End			
				Animation           = IDLD
					AnimationName     = GUBoromir_SKL.GUBoromir_IDLD
					AnimationMode     = ONCE
					AnimationPriority   = 1
				End			
					BeginScript
					Prev = CurDrawablePrevAnimationState()
					if Prev == "Selected" then CurDrawableSetTransitionAnimState("TRANS_Selected_To_Idle") end
				EndScript			
			End
			
			TransitionState       = Trans_None_To_Sword
				Animation           = GUBoromir_STHA
					AnimationName     = GUBoromir_SKL.GUBoromir_STHA ;
					AnimationMode     = ONCE
				End
			End
			TransitionState       = Trans_Sword_To_None
				Animation           = GUBoromir_STHB
					AnimationName     = GUBoromir_SKL.GUBoromir_STHB ;
					AnimationMode     = ONCE
				End
			End
			
			AnimationState        = STUNNED_FLAILING 
				Flags               = RANDOMSTART
				Animation           = GUBoromir_FLYA
					AnimationName     = GUBoromir_SKL.GUBoromir_FLYA
					AnimationMode     = LOOP
				End
			End
			
			
			; --- Dying anims
			
			AnimationState        = DYING SPLATTED
				Animation           = GUBoromir_LNDA
					AnimationName     = GUBoromir_SKL.GUBoromir_LNDA
					AnimationMode     = ONCE
				End
			End
			AnimationState        = DYING AFLAME
				Animation = DieAflame
					AnimationName       = GUBoromir_SKL.GUBoromir_MFDA
					AnimationMode       = LOOP
				End
			End
			AnimationState        = DYING
				Animation           = GUBoromir_DTHA
					AnimationName     = GUBoromir_SKL.GUBoromir_DTHA
					AnimationMode     = ONCE
				End
			End
			
			; --- Stunned anims
			AnimationState        = STUNNED_STANDING_UP
				Animation           = GUBoromir_GTPA
					AnimationName     = GUBoromir_SKL.GUBoromir_GTPA
					AnimationMode     = ONCE
					AnimationSpeedFactorRange = 1.3 1.3
				End
			End
			AnimationState        = STUNNED 
				Animation           = GUBoromir_LNDA
					AnimationName     = GUBoromir_SKL.GUBoromir_LNDA
					AnimationMode     = ONCE
				End
			End
			
			AnimationState        = PACKING_TYPE_2 
				StateName		  =	CaptainPower
				Animation           = GUBoromir_CHRA
					AnimationName     = GUBoromir_SKL.GUBoromir_CHRA
					AnimationMode     = ONCE
					AnimationSpeedFactorRange = 1.2 1.2
				End
			End
			
			; -- Horn anims
			AnimationState        = UNPACKING SPECIAL_POWER_1
				Animation           
					AnimationName     = GUBoromir_SKL.GUBoromir_HRNA
					AnimationMode     = ONCE
				End
			End
			AnimationState        = PREPARING SPECIAL_POWER_1
				Animation           
					AnimationName     = GUBoromir_SKL.GUBoromir_HRNB
					AnimationMode     = ONCE
				End
			EnteringStateFX = FX_BoromirHorn
			End
			AnimationState        = PACKING SPECIAL_POWER_1
				Animation           
					AnimationName     = GUBoromir_SKL.GUBoromir_HRNC
					AnimationMode     = ONCE
				End
			End
			AnimationState        = SPECIAL_POWER_1
				Animation           
					AnimationName     = GUBoromir_SKL.GUBoromir_HRNB
					AnimationMode     = LOOP
				End
			End
			
			; -- Last Stand Animations
			AnimationState        = UNPACKING SPECIAL_WEAPON_ONE
				Animation           
					AnimationName     = GUBoromir_SKL.GUBoromir_SPCA
					AnimationMode     = ONCE
				End
			End
			AnimationState        = PREPARING SPECIAL_WEAPON_ONE
				Animation           
					AnimationName     = GUBoromir_SKL.GUBoromir_SPCB
					AnimationMode     = ONCE
				End
				Animation           
					AnimationName     = GUBoromir_SKL.GUBoromir_SPCC
					AnimationMode     = ONCE
				End
			EnteringStateFX = FX_BoromirHorn
			End
			AnimationState        = PACKING SPECIAL_WEAPON_ONE
				Animation           
					AnimationName     = GUBoromir_SKL.GUBoromir_SPCE
					AnimationMode     = ONCE
				End
			End
			AnimationState        = SPECIAL_WEAPON_ONE
				Animation           
					AnimationName     = GUBoromir_SKL.GUBoromir_SPCB
					AnimationMode     = ONCE
				End
				Animation           
					AnimationName     = GUBoromir_SKL.GUBoromir_SPCC
					AnimationMode     = ONCE
				End
			End
			
			; --- Moving Anims
			AnimationState        = MOVING WANDER WEAPONSTATE_CLOSE_RANGE
				StateName           = WithSword
				;ParticleSysBone     = None InfantryDustTrails
				Animation           = GUBoromir_WLKA
					AnimationName     = GUBoromir_SKL.GUBoromir_WLKA
					AnimationMode     = LOOP
				End
			End
			; non mo cap
	;		AnimationSt	ate        = MOVING WEAPONSTATE_CLOSE_RANGE
;			StateName	           = WithSword
;			Flags  	             = RANDOMSTART
;			;Part	icleSysBone     = None InfantryDustTrails
;			Ani	mation           = GUBoromir_RUNB
;					AnimationName     = GUBoromir_SKL.GUBoromir_RUNB
;					AnimationMode     = LOOP
	;			End	
;		End	
;		A	nimationState        = MOVING DAMAGED
;				Flags               = RANDOMSTART
	;			;ParticleSysBone     = None Infa	ntryDustTrails
;			Animation           = GUBoromir_IW	KA
;				AnimationName     = GUBoromi	r_SKL.GUBoromir_IWKA
;				AnimationMode     = LOOP	
;			End	
;		End	
			AnimationState        = MOVING WANDER
				;ParticleSysBone     = None InfantryDustTrails
				Animation           = GUBoromir_WLKA
					AnimationName     = GUBoromir_SKL.GUBoromir_WLKA
					AnimationMode     = LOOP
				End
			End
			
			
			AnimationState        = MOVING FIRING_OR_PREATTACK_A
				ShareAnimation		= Yes
				Animation           = RunAndFire
					AnimationName       = GUBoromir_SKL.GUBoromir_ATRA
					AnimationMode       = LOOP
				End
				Flags               = RANDOMSTART  
			End
			
			
			AnimationState        = MOVING
				;ParticleSysBone     = None InfantryDustTrails
				Flags               = RANDOMSTART
				Animation           = GUBoromir_RUNB
					AnimationName     = GUBoromir_SKL.GUBoromir_RUNA
					AnimationMode     = LOOP
				End
			End
			
			
			
			; Attacking Anims [Weapon_A]
			AnimationState        = FIRING_OR_PREATTACK_A WEAPONSTATE_CLOSE_RANGE
				StateName           = WithSword
				Animation           = ATKA
					AnimationName     = GUBoromir_SKL.GUBoromir_ATKA
					AnimationMode     = ONCE
					UseWeaponTiming		= Yes
				End
				Animation           = ATKB
					AnimationName    = GUBoromir_SKL.GUBoromir_ATKB
					AnimationMode     = ONCE
					UseWeaponTiming		= Yes
				End
			End
			
			AnimationState        = FIRING_OR_PREATTACK_A
				Animation           = GUBoromir_ATD1
					AnimationName     = GUBoromir_SKL.GUBoromir_ATKB 
					AnimationMode     = ONCE
					UseWeaponTiming		= Yes
				End
			End
			
			
			
			
			; --------- Idle Anims -non mocap-
	;		AnimationState        = WEAPONSTA	TE_CLOSE_RANGE
;			StateName           = WithSword	
;			Animation           = GUBorom	ir_IDLC
;				AnimationName     = GUBoromir_SKL.GUBoromir_IDLC
;				AnimationMode     = ONCE
;			End
;		End

		; ATTACKING
			AnimationState        = ATTACKING
				Animation           = ALERT_1
					AnimationName     = GUBoromir_SKL.GUBoromir_IDLA
					AnimationMode     = LOOP; ONCE
				End
;				Flags               = RESTART_ANIM_WHEN_COMPLETE ; acts like an idle animation & keeps running the animations.
			End
			
			; --------- Selected Anims and Transitions
			TransitionState					=	TRANS_Idle_to_Selected
				Animation					=	ATND
					AnimationName			=	GUBoromir_SKL.GUBoromir_ATND
					AnimationMode			=	ONCE
				End
			End
			
			TransitionState					=	TRANS_Selected_To_Idle
				Animation					=	ATNE
					AnimationName			=	GUBoromir_SKL.GUBoromir_ATNE
					AnimationMode			=	ONCE
				End
			End
			
			AnimationState				= LEVELED 						; This state clears itself in 3 seconds
				Animation				= LevelUp
					AnimationName		= GUBoromir_SKL.GUBoromir_CHRA
					AnimationMode		= ONCE
				End
			End
			
			AnimationState				=	SELECTED
				StateName				=	Selected
				SimilarRestart			=   Yes			
				Animation				=	ATNB
					AnimationName		=	GUBoromir_SKL.GUBoromir_ATNB
					AnimationMode		=	LOOP
				End
				BeginScript
					Prev = CurDrawablePrevAnimationState()
					if Prev == "Idle" then CurDrawableSetTransitionAnimState("TRANS_Idle_to_Selected") end
				EndScript
			End
			
			;------------emotions---------------
			AnimationState			= EMOTION_CELEBRATING
				Animation           = CHRA
					AnimationName   = GUBoromir_SKL.GUBoromir_CHRA
					AnimationMode   = Once
				End
				Animation           = CHRB
					AnimationName   = GUBoromir_SKL.GUBoromir_CHRB
					AnimationMode   = Once
				End
				Flags				=	RESTART_ANIM_WHEN_COMPLETE
			End
			
			AnimationState					= EMOTION_ALERT EMOTION_MORALE_HIGH
				Animation					= Taunting
					AnimationName			=  GUBoromir_SKL.GUBoromir_TNTB
					AnimationMode			= ONCE
				End
				Flags						= RANDOMSTART RESTART_ANIM_WHEN_COMPLETE
			End
			
			; READY IDLE
			AnimationState        = EMOTION_ALERT
				Animation           = ALERT_1
					AnimationName     = GUBoromir_SKL.GUBoromir_IDLA
					AnimationMode     = LOOP ;ONCE
				End
;				Flags               = RESTART_ANIM_WHEN_COMPLETE ; acts like an idle animation & keeps running the animations.
			End
			
			
			; --------- Click and Hit Reactions ------------
			AnimationState = HIT_REACTION HIT_LEVEL_1
				Animation = Hit_Level_1_a
					AnimationName = GUBoromir_SKL.GUBoromir_HITA
					AnimationMode = ONCE
				End
			End		
			
		End	
	End	
	WeaponSet
		Conditions 			= None 
		Weapon     			= PRIMARY  NewGamlingSword  		
		AutoChooseSources	= PRIMARY FROM_PLAYER FROM_SCRIPT FROM_AI		
	End

	AddModule
		Behavior = UnpauseSpecialPowerUpgrade ModuleTag_GothmogIronHandEnabler
			SpecialPowerTemplate		= SpecialAbilityFakeLeadership
			TriggeredBy			= Upgrade_GothmogIronHand
		End	
	End
	AddModule
		Behavior = SpecialPowerModule ModuleTag_GothmogIronHandSpecialPowerModule
			SpecialPowerTemplate		= SpecialAbilityFakeLeadership 
			StartsPaused			= Yes
			UpdateModuleStartsAttack	= Yes
		End
	End
	AddModule
		Behavior = AttributeModifierAuraUpdate ModuleTag_IronHandLeadership
			StartsActive		= No ;If no, requires upgrade to turn on.
			BonusName		= NewGothmogIronHand
			TriggeredBy		= Upgrade_GothmogIronHand							; Upgrade_LurtzLeadership
			RefreshDelay		= 2000
			Range			= 90
			ObjectFilter		= ALL	; GENERIC_BUFF_RECIPIENT_OBJECT_FILTER
		End
	End	
	AddModule
		Behavior = BezierProjectileBehavior ModuleTag_08 ; Module starts asleep, and wakes up when thrown.
			; To tweak a Bezier path
			FirstHeight = 50  ; Height of Bezier control points above highest intervening terrain
			SecondHeight = 20
			FirstPercentIndent = 20% ; Percentage of shot distance control points are placed
			SecondPercentIndent = 70%
			TumbleRandomly = Yes
			CrushStyle = Yes ; I don't detonate, I 
			BounceCount = 0   ; When I hit the ground, I'll ar
			FinalStuckTime = 1200 ; Can't move for thi
			GroundHitFX       = FX_GimliLeapLand
			GroundHitWeapon   = RohanGimliLeapWarhead
			PreLandingStateTime = 75; Look ahead to the end of the arc, and get the ABOUT_TO_HIT flag this far in advance
		End
	End
	AddModule
		Behavior = UnpauseSpecialPowerUpgrade ModuleTag_LeapEnabler
			SpecialPowerTemplate = SpecialAbilityGimliLeap
			TriggeredBy = Upgrade_GimliLeapTrigger
		End
	End
	AddModule
		Behavior = SpecialPowerModule ModuleTag_LeapStarter                      
			SpecialPowerTemplate		= SpecialAbilityGimliLeap
			UpdateModuleStartsAttack	= Yes
			StartsPaused			= Yes
			InitiateSound			= BoromirVoiceAttackCharge
		End
	End
	AddModule
		Behavior = WeaponFireSpecialAbilityUpdate ModuleTag_LeapUpdate   
			SpecialPowerTemplate    = SpecialAbilityGimliLeap
	
			UnpackTime              = 600
			PackTime                = 300 ; Putting horn away
	
			AwardXPForTriggering    = 0
			MustFinishAbility	= Yes
			StartAbilityRange = 100.0
			
			SpecialWeapon = RohanGimliLeap
			BusyForDuration = 2000 ; don't accept any AI for this long... ai commands will be queued
	
	;		ApproachRequiresLOS = No
			WhichSpecialWeapon = 2
			TriggerSound = BoromirVoiceAttackCharge
		End
	End
	AddModule
		Behavior = UnpauseSpecialPowerUpgrade ModuleTag_HwaldarSummon1Enabler
			SpecialPowerTemplate = SpecialAbilityHwaldarSummonHillmen1
			TriggeredBy = Upgrade_HwaldarSummons1
		End
	End
	AddModule
		Behavior = OCLSpecialPower ModuleTag_OCLSpecialPowerSummon1
			SpecialPowerTemplate		= SpecialAbilityHwaldarSummonHillmen1
			OCL				= OCL_SpawnRohanRohirrim
			CreateLocation			= CREATE_AT_LOCATION
			StartsPaused			= Yes
			;SetModelCondition		= ModelConditionState:USER_1
			;SetModelConditionTime		= 8.1
		End
	End
	ReplaceModule ModuleTag_GamlingHealing
		Behavior = AutoHealBehavior ModuleTag_GamlingHealing1
			StartsActive = Yes
			HealingAmount = 50
			HealingDelay = 7000
			StartHealingDelay = 5000
			HealOnlyIfNotInCombat = Yes
		End
	End
	AddModule
		Behavior = UnpauseSpecialPowerUpgrade ModuleTag_CreateAHeroShieldCrushEnabler_Level3
			SpecialPowerTemplate	= SpecialAbilityCreateAHeroShieldCrush_Level3
			TriggeredBy				= Upgrade_CreateAHeroShieldCrush_Level3
		End
	End
	AddModule
		Behavior = SpecialPowerModule ModuleTag_CreateAHeroShieldCrushStarter_Level3			; SpecialAbility is	a SpecialPower,	SpecialPower is	anyting	special
			SpecialPowerTemplate			= SpecialAbilityCreateAHeroShieldCrush_Level3
			StartsPaused					= Yes
			AttributeModifier				= NewCreateAHeroShieldCrush_Level3
			AttributeModifierAffectsSelf	= Yes
			;TriggerRX						= FX_CreateAHeroShieldCharge_Level3
		End
	End
	AddModule ModuleTag_AragornBladeMasterEnabler
		Behavior = UnpauseSpecialPowerUpgrade ModuleTag_AragornBladeMasterEnabler
			SpecialPowerTemplate = SpecialAbilityAragornBladeMaster
			TriggeredBy = Upgrade_AragornBladeMaster
		End
	End
	AddModule ModuleTag_AragornBladeMasterStarter
		Behavior = SpecialPowerModule ModuleTag_AragornBladeMasterStarter                ; SpecialAbility is a SpecialPower, SpecialPower is anyting special
			SpecialPowerTemplate    = SpecialAbilityAragornBladeMaster
			StartsPaused			= Yes
		End
	End
	AddModule ModuleTag_AragornBladeMasterUpdate
		Behavior = HeroModeSpecialAbilityUpdate ModuleTag_AragornBladeMasterUpdate   
			SpecialPowerTemplate    = SpecialAbilityAragornBladeMaster
			HeroAttributeModifier	= NewAragornBladeMaster
			HeroEffectDuration		= 30000 
			UnpackTime              = 1 ; insant unpack
			TriggerSound			= AragornBladeMaster
		End
	End
	AddModule
		Behavior = UnpauseSpecialPowerUpgrade ModuleTag_TheodenLeadership2New
			SpecialPowerTemplate = SpecialAbilityFakeLeadership2
			TriggeredBy = Upgrade_EomerOutlawLeader
		End
	End
	AddModule
		Behavior = SpecialPowerModule ModuleTag_TheodenLeadershipUpdate2New
			SpecialPowerTemplate      = SpecialAbilityFakeLeadership2
			UpdateModuleStartsAttack  = No
			StartsPaused = Yes
		End	
	End
	AddModule
		Behavior = AttributeModifierAuraUpdate ModuleTag_Leadership2New
			StartsActive	= No ;If no, requires upgrade to turn on.
			BonusName		= EomerPassiveOutlawLeadership
			TriggeredBy		= Upgrade_EomerOutlawLeader
			RefreshDelay	= 2000
			Range			= 200
			AllowSelf		= Yes		
			ObjectFilter	= ANY +CAVALRY +INFANTRY -STRUCTURE -BASE_FOUNDATION -DOZER
		End	
	End
END


ExperienceLevel	GamlingLevel1
	TargetNames						=	RohanGamling	
	RequiredExperience					=	1	
	ExperienceAward						=	GAMLING_LVL1_EXP_AWARD
	Rank							=	1
	Upgrades						=	Upgrade_BoromirHornOfGondor
	SelectionDecal
		Texture						=	decal_hero_good	
		Style						=	SHADOW_ALPHA_DECAL
		OpacityMin					=	50%	
		OpacityMax					=	100%
		MinRadius					=	40
		MaxRadius					=	200
		MaxSelectedUnits				=	1
	End
End

ExperienceLevel	GamlingLevel2
	TargetNames						=	RohanGamling	
	RequiredExperience					=	GAMLING_LVL2_EXP_NEEDED
	ExperienceAward						=	GAMLING_LVL2_EXP_AWARD
	AttributeModifiers					=	HeroLevelUpDamage1
	Rank							=	2
	LevelUpFx						=	FX:GandalfLevelUp1FX
	;LevelUpOCL						=	OCL_GandalfLevelUp1OCL
	Upgrades						=	Upgrade_GimliLeapTrigger
	SelectionDecal
		Texture						=	decal_hero_good	
		Style						=	SHADOW_ALPHA_DECAL
		OpacityMin					=	50%	
		OpacityMax					=	100%
		MinRadius					=	40
		MaxRadius					=	200
		MaxSelectedUnits				=	1	
	End		
End	

ExperienceLevel	GamlingLevel4
	TargetNames						=	RohanGamling	
	RequiredExperience					=	GAMLING_LVL4_EXP_NEEDED
	ExperienceAward						=	GAMLING_LVL4_EXP_AWARD	
	AttributeModifiers					=	HeroLevelUpDamage3
	Rank							=	4
	LevelUpFx						=	FX:GandalfLevelUp1FX
	;LevelUpOCL						=	OCL_GandalfLevelUp1OCL
	Upgrades						=	Upgrade_CreateAHeroShieldCrush_Level3
	SelectionDecal
		Texture						=	decal_hero_good
		Style						=	SHADOW_ALPHA_DECAL
		OpacityMin					=	50%
		OpacityMax					=	100%
		MinRadius					=	40
		MaxRadius					=	200
		MaxSelectedUnits				=	1
	End		
End	

ExperienceLevel	GamlingLevel6
	TargetNames						=	RohanGamling	
	RequiredExperience					=	GAMLING_LVL6_EXP_NEEDED
	ExperienceAward						=	GAMLING_LVL6_EXP_AWARD	
	AttributeModifiers					=	HeroLevelUpDamage5
	Rank							=	6
	LevelUpFx						=	FX:GandalfLevelUp1FX
	;LevelUpOCL						=	OCL_GandalfLevelUp1OCL
	Upgrades						=	Upgrade_EomerOutlawLeader
	SelectionDecal
		Texture						=	decal_hero_good
		Style						=	SHADOW_ALPHA_DECAL
		OpacityMin					=	50%	
		OpacityMax					=	100%
		MinRadius					=	40
		MaxRadius					=	200
		MaxSelectedUnits				=	1	
	End	
End	

ExperienceLevel	GamlingLevel9
	TargetNames						=	RohanGamling	
	RequiredExperience					=	GAMLING_LVL9_EXP_NEEDED
	ExperienceAward						=	GAMLING_LVL9_EXP_AWARD	
	AttributeModifiers					=	HeroLevelUpDamage8
	Rank							=	9
	LevelUpFx						=	FX:GandalfLevelUp1FX
	;LevelUpOCL						=	OCL_GandalfLevelUp1OCL
	Upgrades						=	Upgrade_HwaldarSummons1
	SelectionDecal
		Texture						=	decal_hero_good
		Style						=	SHADOW_ALPHA_DECAL
		OpacityMin					=	50%	
		OpacityMax					=	100%
		MinRadius					=	40
		MaxRadius					=	200
		MaxSelectedUnits				=	1	
	End	
End

ExperienceLevel	GamlingLevel10
	TargetNames						=	RohanGamling	
	RequiredExperience					=	GAMLING_LVL10_EXP_NEEDED
	ExperienceAward						=	GAMLING_LVL10_EXP_AWARD	
	AttributeModifiers					=	HeroLevelUpDamage9
	Rank							=	10
	LevelUpFx						=	FX:GandalfLevelUp1FX
	;LevelUpOCL						=	OCL_GandalfLevelUp1OCL
	Upgrades						=	Upgrade_GothmogIronHand
	SelectionDecal
		Texture						=	decal_hero_good
		Style						=	SHADOW_ALPHA_DECAL
		OpacityMin					=	50%	
		OpacityMax					=	100%
		MinRadius					=	40
		MaxRadius					=	200
		MaxSelectedUnits				=	1	
	End	
End	