;;================== ANIMATIONS =================================================================
				
;;------------------  DYING -------------------------------------------------------------

; --- Flying through the air.
		AnimationState        = STUNNED_FLAILING WEAPONLOCK_SECONDARY
			Animation           = FLYA
				AnimationName     = RULegolas_FLYA
				AnimationMode     = LOOP
				AnimationSpeedFactorRange	= 0.4 0.6
			End
			Flags               = RANDOMSTART
			BeginScript
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End
		AnimationState        = STUNNED_FLAILING
			Animation           = FLYA
				AnimationName     = RULegolas_FLYB
				AnimationMode     = LOOP
				AnimationSpeedFactorRange	= 0.4 0.6
			End
			Flags               = RANDOMSTART
			BeginScript
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End

; --- Dying
		AnimationState        = DYING WEAPONLOCK_SECONDARY
			Animation           = DIEC
				AnimationName     = RULegolas_DIEC
				AnimationMode     = ONCE
			End
			BeginScript
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End
				 
		AnimationState        = DYING
			Animation           = DIEA
				AnimationName     = RULegolas_DIEA
				AnimationMode     = ONCE
			End
			Animation           = DIEB
				AnimationName     = RULegolas_DIEB
				AnimationMode     = ONCE
			End
			BeginScript
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End	
		
; --- Stunned

		AnimationState        = STUNNED_STANDING_UP WEAPONLOCK_SECONDARY
			StateName           = STATE_Sword
			Animation           = GUFaramir_GTPC
				AnimationName     = RULegolas_GTPC
				AnimationMode     = ONCE
				AnimationSpeedFactorRange = 1.5 1.5
			End
			BeginScript
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End
		AnimationState        = STUNNED_STANDING_UP
			StateName           = STATE_Bow
			Animation           = GUFaramir_GTPA
				AnimationName     = RULegolas_GTPA
				AnimationMode     = ONCE
				AnimationSpeedFactorRange = 1.5 1.5
			End
			Animation           = GUFaramir_GTPB
				AnimationName     = RULegolas_GTPB
				AnimationMode     = ONCE
				AnimationSpeedFactorRange = 1.5 1.5
			End
			BeginScript
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End

		AnimationState        = STUNNED WEAPONLOCK_SECONDARY
			StateName           = STATE_Sword
			Animation           = GUFaramir_LNDA
				AnimationName     = RULegolas_LNDA
				AnimationMode     = ONCE
			End
			BeginScript
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End				
		AnimationState        = STUNNED 
			StateName           = STATE_Bow
			Animation           = GUFaramir_LNDB
				AnimationName     = RULegolas_LNDB
				AnimationMode     = ONCE
			End
			BeginScript
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End			
			
		AnimationState						= PARALYZED
			Animation
				AnimationName				= RULegolas_IDLA
				AnimationMode				= LOOP
			End
		End

;--- Arrow Wind Special attack

		AnimationState        = UNPACKING PACKING_TYPE_1
			Animation           = ATKA1
				AnimationName     = RULegolas_ATKA1	;ATKH1
				AnimationMode     = ONCE
			End
			StateName           = STATE_Bow
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "STATE_Sword" then CurDrawableSetTransitionAnimState("TRANS_SwitchToBow") end
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End
	
	
		AnimationState        = PREPARING PACKING_TYPE_1
			Animation           = ATKA2
				AnimationName     = RULegolas_ATKA2 ;ATKH2
				AnimationMode     = LOOP
				AnimationSpeedFactorRange = 1.328 1.328
			End
			StateName           = STATE_Bow
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "STATE_Sword" then CurDrawableSetTransitionAnimState("TRANS_SwitchToBow") end
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End
		
		AnimationState        = PACKING PACKING_TYPE_1
			Animation           = ATKA3
				AnimationName     = RULegolas_ATKA3 ;ATKH3
				AnimationMode     = LOOP
			End
			StateName           = STATE_Bow
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "STATE_Sword" then CurDrawableSetTransitionAnimState("TRANS_SwitchToBow") end
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End

;--- Train Archer - a cheer 

		AnimationState        = PACKING_TYPE_2
			Animation           = CHRB
				AnimationName     = RULegolas_CHRB
				AnimationMode     = ONCE
				AnimationSpeedFactorRange = 1.5 1.5
			End
			StateName           = STATE_TrainingStart
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "STATE_Sword" then CurDrawableSetTransitionAnimState("TRANS_SwitchToBow") end
			EndScript
		End

;--- Hawk Strike Special Attack
		AnimationState        =  SPECIAL_WEAPON_ONE
			Animation           = ATKB
				AnimationName     = RULegolas_ATKB
				AnimationMode     = ONCE
				;Speed up the animation so it plays in 3 seconds (90 frames) instead of 4.53 (136 frames)
				;Changing this value will require consideration of the special weapon timings in WeaponFireSpecialAbilityUpdate below
				;AnimationSpeedFactorRange	= 1.51 1.51		
			End
			FrameForPristineBonePositions = 45
			StateName           = STATE_Bow
			
			;This script handles proper transitions back to KnifeFighter mode. The WeaponFireSpecialAbilityUpdate will force
			;a short duration paralysis on the unit allowing for the transition to complete. Otherwise the unit would move
			;and blend immediately out of this to moving. 
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "STATE_Sword" then CurDrawableSetTransitionAnimState("TRANS_SwitchToBow") end
				CurDrawableShowSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End

	;--------------------------------------------------------------------------------------		
	;  These are necessary because the arrow wind just busts him out of his knife fighter  spell
	;	but without removing the weaponlock flag.
	;
			AnimationState        =  SPECIAL_WEAPON_ONE WEAPONLOCK_SECONDARY
			Animation           = ATKB
				AnimationName     = RULegolas_ATKB
				AnimationMode     = ONCE
				UseWeaponTiming		= Yes
			End
			FrameForPristineBonePositions = 32
			StateName           = STATE_Bow
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "STATE_Sword" then CurDrawableSetTransitionAnimState("TRANS_SwitchToBow") end
			EndScript
		End
		
		AnimationState        = MOVING FIRING_OR_PREATTACK_A WEAPONLOCK_SECONDARY
			ShareAnimation		= Yes
			Animation           = RunAndFire
				AnimationName       = RULegolas_ATRA
				AnimationMode       = LOOP
			End
			Flags               = RANDOMSTART 
		End
		
		
		AnimationState        = UNPACKING WEAPONLOCK_SECONDARY
			Animation           = ATKA
				AnimationName     = RULegolas_ATKA
				AnimationMode     = ONCE
			End
			StateName           = STATE_Bow
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "STATE_Sword" then CurDrawableSetTransitionAnimState("TRANS_SwitchToBow") end
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End
	
		AnimationState        = PREPARING WEAPONLOCK_SECONDARY
			Animation          
				AnimationName     = RULegolas_ATKA2
				AnimationMode     = LOOP
			End
			StateName           = STATE_Bow
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "STATE_Sword" then CurDrawableSetTransitionAnimState("TRANS_SwitchToBow") end
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End
; ---
	
		AnimationState        =  FIRING_OR_PREATTACK_B WEAPONLOCK_SECONDARY
			Animation           = ATKD
				AnimationName     = RULegolas_ATKD
				AnimationMode     = ONCE
				UseWeaponTiming		= Yes
			End
			Animation           = ATKE
				AnimationName     = RULegolas_ATKE
				AnimationMode     = ONCE
				UseWeaponTiming		= Yes
			End
			Animation           = ATKJ
				AnimationName     = RULegolas_ATKJ
				AnimationMode     = ONCE
				UseWeaponTiming		= Yes
			End
			Animation           = ATKK
				AnimationName     = RULegolas_ATKK
				AnimationMode     = ONCE
				UseWeaponTiming		= Yes
			End
;FXEvent	= Frame:20 Name: FX_KnifeFighterHitOrientRight
;FXEvent	= Frame:22 Name: FX_KnifeFighterHitOrientLeft
            FXEvent	= Frame:17 Name: FX_BladeMasterHitOrient
    		StateName           = STATE_Sword
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "STATE_Bow" then CurDrawableSetTransitionAnimState("TRANS_SwitchToSwords") end
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End
		
;---------------------------------------------------
		;New style firing
		AnimationState						= PREATTACK_A 
			StateName						= STATE_Firing
			Animation						= ReadyToDrawn
				AnimationName				= RULegolas_ATKA1
				AnimationMode				= ONCE
;				UseWeaponTiming				= Yes			; UseWeaponTiming plus random weapon field equals desync.  Leaving as warning
				AnimationBlendTime			= 10				; Must be 0 blend time otherwise the arrow will linger for the duration of the blend!
				AnimationSpeedFactorRange	= 1.5 1.5		; Therefore, this is all you get.  A slight speed up so that the animation can always finish before any possible random value Design sets the range for
			End
			BeginScript
				CurDrawableShowSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End

		AnimationState						= FIRING_OR_RELOADING_A
			StateName						= STATE_Firing
			Animation						= OneFrameOfShooting
				AnimationName				= RULegolas_ATKA2
				AnimationMode				= ONCE
;				UseWeaponTiming				= Yes			; UseWeaponTiming plus random weapon field equals desync.  Leaving as warning
				AnimationSpeedFactorRange	= 1.0 1.0		; Therefore, this is all you get.  A slight speed up so that the animation can always finish before any possible random value Design sets the range for
				AnimationBlendTime			= 0
			End
			BeginScript
				CurDrawableShowSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End

	
		;End New style firing
;---------------------------------------------------


;--- Moving		
		; ------ With blades
		AnimationState        = MOVING WEAPONLOCK_SECONDARY
			Animation           = RUNB
				AnimationName   = RULegolas_RUNB
				AnimationMode   = LOOP
				Distance		= 50
				AnimationBlendTime = 10
			End
			Flags               = RANDOMSTART
			;ParticleSysBone     = None InfantryDustTrails
			StateName           = STATE_Sword
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "STATE_Bow" then CurDrawableSetTransitionAnimState("TRANS_SwitchToSwordsWhileMoving") end
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End
		; ------ With bow
		AnimationState        = MOVING
			Animation           = RUNA
				AnimationName   = RULegolas_RUNA
				AnimationMode   = LOOP
				Distance		= 50
				AnimationBlendTime			= 10
			End
			Flags               = RANDOMSTART
			;ParticleSysBone     = None InfantryDustTrails
			StateName           = STATE_Bow
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "STATE_Sword" then CurDrawableSetTransitionAnimState("TRANS_SwitchToBowWhileMoving") end
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End
		

;--- Holding drawn bow while attacking		
		AnimationState						= CONTINUOUS_FIRE_MEAN
			StateName						= STATE_Firing
			Animation						= HangFrameWhileCoasting
				AnimationName				= RULegolas_ATKA2
				AnimationMode				= MANUAL
			End
			BeginScript
				CurDrawableShowSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End
		
		AnimationState						= CONTINUOUS_FIRE_SLOW
			StateName						= STATE_Idle_Bow
			Animation						= PutAwayArrow
				AnimationName				= RULegolas_ATKA3
				AnimationMode				= ONCE
			End
			BeginScript
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End
	
;--- Hit Reactions
		AnimationState = HIT_REACTION
			Animation = Hit_Level
				AnimationName = RULegolas_HITC
				AnimationMode = ONCE
			End
		End
	
;--- Emotions
		
		AnimationState				=	EMOTION_CELEBRATING
			Animation           =	CHRA
				AnimationName   =	RULegolas_CHRA
				AnimationMode   =	ONCE
				AnimationPriority	=	10
			End
			Animation           =	CHRB
				AnimationName   =	RULegolas_CHRB
				AnimationMode   =	ONCE
				AnimationPriority	=	5
			End
			Flags				=	RESTART_ANIM_WHEN_COMPLETE
			BeginScript
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End
		
		AnimationState				=	EMOTION_TAUNTING
			Animation           =	CHRB
				AnimationName   =	RULegolas_CHRB
				AnimationMode   =	ONCE
			End
			Flags				=	RESTART_ANIM_WHEN_COMPLETE
			BeginScript
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End
		
;--- Selected
		AnimationState				=	WEAPONLOCK_SECONDARY SELECTED
			StateName				=	KnifeFighterSelected
			Animation				=	ATNF
				AnimationName		=	RULegolas_IDLJ
				AnimationMode		=	LOOP
			End
			StateName				= SwordsAttn
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "STATE_Bow" or Prev == "Selected" then CurDrawableSetTransitionAnimState("TRANS_SwitchToAttentionSword") end
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End
		
		AnimationState				=	RAISING_FLAG
			Animation           =	CHRA
				AnimationName   =	RULegolas_CHRA
				AnimationMode   =	ONCE
			End
			Animation           =	CHRB
				AnimationName   =	RULegolas_CHRB
				AnimationMode   =	ONCE
			End
			Flags				=	RESTART_ANIM_WHEN_COMPLETE
		End

		AnimationState				=	SELECTED
			StateName				=	Selected
			Animation				=	ATNB
				AnimationName		=	RULegolas_ATNB
				AnimationMode		=	LOOP
			End
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "STATE_Bow" then CurDrawableSetTransitionAnimState("TRANS_SwitchToAttention") end
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End

	
;--- Idle states
		AnimationState        = WEAPONLOCK_SECONDARY
			Animation           = IDLG
				AnimationName     = RULegolas_IDLJ
				AnimationMode     = LOOP
			End
			StateName           = STATE_Sword
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "STATE_Bow" then CurDrawableSetTransitionAnimState("TRANS_SwitchToSwords") end
; no attn w/ sword anim				if Prev == "SwordsAttn" then CurDrawableSetTransitionAnimState("TRANS_SwitchFromAttentionSword") end
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End
		IdleAnimationState
			Animation           = IDLB
				AnimationName     = RULegolas_IDLB
				AnimationMode     = ONCE
				AnimationPriority	= 8
			End
			Animation           = IDLB ;Double up because animations never choose the same one twice in a row.
				AnimationName     = RULegolas_IDLB
				AnimationMode     = ONCE
				AnimationPriority	= 8
			End
			Animation           = IDLD
				AnimationName     = RULegolas_IDLD
				AnimationMode     = ONCE
				AnimationPriority	= 1
			End
			Animation           = IDLE
				AnimationName     = RULegolas_IDLE
				AnimationMode     = ONCE
				AnimationPriority	= 1
			End
			StateName           = STATE_Bow
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "STATE_Sword" then CurDrawableSetTransitionAnimState("TRANS_SwitchToBow") end
				if Prev == "Selected" then CurDrawableSetTransitionAnimState("TRANS_SwitchFromAttention") end
				CurDrawableHideSubObject("arrow") ;Circumvents blend issues when the arrow is being shown...
			EndScript
		End
		

;--- Transitions
		TransitionState       = TRANS_SwitchToBow
			Animation           = STHB
				AnimationName     = RULegolas_STHB
				AnimationMode     = ONCE
			End
		End

		TransitionState       = TRANS_SwitchToSwords
			Animation           = STHA
				AnimationName     = RULegolas_STHA
				AnimationMode     = ONCE
			End
		End
		
		TransitionState       = TRANS_SwitchToBowWhileMoving
			Animation           = STHB
				AnimationName     = RULegolas_RUND
				AnimationMode     = ONCE
				Distance		= 50
			End
		End

		TransitionState       = TRANS_SwitchToSwordsWhileMoving
			Animation           = STHA
				AnimationName     = RULegolas_RUNE
				AnimationMode     = ONCE
				Distance		= 50
			End
		End

		TransitionState       = TRANS_SwitchToAttentionSword
			Animation           = ATNE
				AnimationName     = RULegolas_STHA
				AnimationMode     = ONCE
			End
		End
		
		
;		TransitionState       = TRANS_SwitchFromAttentionSword
;			Animation           = ATNH
;				AnimationName     = RULegolas_STHB
;				AnimationMode     = ONCE
;			End
;		End
		
		TransitionState       = TRANS_SwitchToAttention
			Animation           = ATNA
				AnimationName     = RULegolas_ATNA
				AnimationMode     = ONCE
			End
		End
		
		TransitionState       = TRANS_SwitchFromAttention
			Animation           = ATND
				AnimationName     = RULegolas_ATND
				AnimationMode     = ONCE
			End
		End
End
		