 ;;;;; This is the exact code taken from the game code for Galadriel - no changes. I had to put this here cause i made some changes to Galadriel in the map.ini
 ;;;;; CODE TAKEN FROM : data\ini\object\goodfaction\units\elven\galadriel.ini



 		IdleAnimationState
			Animation				= IDLB
				AnimationName		= EUGaldrl_SKL.EUGaldrl_IDLB
				AnimationMode		= ONCE
				AnimationPriority   = 20
			End
			Animation				= IDLC
				AnimationName		= EUGaldrl_SKL.EUGaldrl_IDLC
				AnimationMode		= ONCE
				AnimationPriority   = 1
			End
			Animation				= IDLD
				AnimationName		= EUGaldrl_SKL.EUGaldrl_IDLD
				AnimationMode		= ONCE
				AnimationPriority   = 1
			End
			StateName				= Idle
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "Selected" then CurDrawableSetTransitionAnimState("TRANS_Selected_To_Idle") end
			EndScript

		End

		AnimationState        = STUNNED_FLAILING 
			Flags               = RANDOMSTART
			Animation           = EUGaldrl_FLYA
				AnimationName     = EUGaldrl_SKL.EUGaldrl_FLYA
				AnimationMode     = LOOP
			End
		End
	
	; --- Dying anims
		AnimationState        = DYING SPLATTED
			Animation           = EUGaldrl_LNDA
				AnimationName     = RUEwnHrHrs_SKL.RUEwnHrHrs_LNDA
				AnimationMode     = ONCE
			End
		End
		AnimationState        = DYING AFLAME
			Animation = DieAflame
				AnimationName       = EUGaldrl_SKL.EUGaldrl_FLYA
				AnimationMode       = LOOP
			End
		End
		AnimationState        = DYING
			Animation           = EUGaldrl_DTHA
				AnimationName     = EUGaldrl_SKL.EUGaldrl_DTHA
				AnimationMode     = ONCE
			End
			;ParticleSysBone = NONE GaladrielDying
			ParticleSysBone = NONE UltraInitial01
			ParticleSysBone = NONE UltraInitial02
			ParticleSysBone = NONE UltraInitial03
		End
	
	
	; --- Stunned anims
		AnimationState        = STUNNED_STANDING_UP
			Animation           = EUGaldrl_GTPA
				AnimationName     = EUGaldrl_SKL.EUGaldrl_GTPA
				AnimationMode     = ONCE
				AnimationSpeedFactorRange = 1.3 1.3
			End
		End
		AnimationState        = STUNNED 
			Animation           = EUGaldrl_LNDA
				AnimationName     = EUGaldrl_SKL.EUGaldrl_LNDA
				AnimationMode     = ONCE
			End
		End

	; --- Moving anims
		; --- Moving Anims
		AnimationState        = MOVING WANDER WEAPONSTATE_CLOSE_RANGE
			StateName           = WithSword
			Animation           = EUGaldrl_WLKA
				AnimationName     = EUGaldrl_SKL.EUGaldrl_RUNB
				AnimationMode     = LOOP
			End
		End
		AnimationState        = MOVING WANDER
			Animation           = EUGaldrl_WLKA
				AnimationName     = EUGaldrl_SKL.EUGaldrl_RUNB
				AnimationMode     = LOOP
			End
		End
			
		AnimationState        = MOVING FIRING_OR_PREATTACK_A
			ShareAnimation		= Yes
			Animation           = RunAndFire
				AnimationName       = EUGaldrl_SKL.EUGaldrl_ATKA
				AnimationMode       = LOOP
			End
			Flags               = RANDOMSTART  
		End
		
		AnimationState			= USER_2					; TerribleFury
			Animation
				AnimationName	= EUGaldrl_SKL.EUGaldrl_SPCB
				AnimationMode	= ONCE
			End
			FXEvent				= Frame:5 Name:FX_GaladrielTerribleFuryFearBlast
		End
		
		AnimationState        = MOVING
			Flags               = RANDOMSTART
			Animation           = EUGaldrl_RUNB
				AnimationName     = EUGaldrl_SKL.EUGaldrl_RUNA
				AnimationMode     = LOOP
			End
		End
		
	; --- Attacking Anims
		AnimationState        = FIRING_OR_PREATTACK_A WEAPONSTATE_CLOSE_RANGE
			StateName				= WithSword
			Animation				= ATKA
				AnimationName		= EUGaldrl_SKL.EUGaldrl_ATKA
				AnimationMode		= ONCE
				UseWeaponTiming		= Yes
			End
			Animation				= ATKB
				AnimationName		= EUGaldrl_SKL.EUGaldrl_ATKB
				AnimationMode		= ONCE
				UseWeaponTiming		= Yes
			End
			Animation				= ATKB
				AnimationName		= EUGaldrl_SKL.EUGaldrl_ATKC
				AnimationMode		= ONCE
				UseWeaponTiming		= Yes
			End
		End

		AnimationState        = FIRING_OR_PREATTACK_A
			Animation				= ATKA
				AnimationName		= EUGaldrl_SKL.EUGaldrl_ATKA
				AnimationMode		= ONCE
				UseWeaponTiming		= Yes
			End
			Animation				= ATKB
				AnimationName		= EUGaldrl_SKL.EUGaldrl_ATKB
				AnimationMode		= ONCE
				UseWeaponTiming		= Yes
			End
			Animation				= ATKB
				AnimationName		= EUGaldrl_SKL.EUGaldrl_ATKC
				AnimationMode		= ONCE
				UseWeaponTiming		= Yes
			End
		End

		AnimationState        = ATTACKING
			Animation           = ALERT_1
				AnimationName     = EUGaldrl_SKL.EUGaldrl_IDLA
				AnimationMode     = LOOP; ONCE
			End
		End

		AnimationState        = RAISING_FLAG
			Animation
				AnimationName     = EUGaldrl_SKL.EUGaldrl_CHRA
				AnimationMode     = LOOP
			End
		End
		
		AnimationState				=	SELECTED
			StateName				=	Selected
			SimilarRestart			=   Yes			
			Animation				=	ATNB
				AnimationName		=	EUGaldrl_SKL.EUGaldrl_ATNB
				AnimationMode		=	LOOP
			End
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "Idle" then CurDrawableSetTransitionAnimState("TRANS_Idle_to_Selected") end
			EndScript
		End

		AnimationState = LEVELED
			Animation = Hit_Level_1_a
				AnimationName = EUGaldrl_SKL.EUGaldrl_LVLA
				AnimationMode = ONCE
			End
		End		

	; --- Click and Hit Reactions
		AnimationState = HIT_REACTION HIT_LEVEL_1
			Animation = Hit_Level_1_a
				AnimationName = EUGaldrl_SKL.EUGaldrl_HITA
				AnimationMode = ONCE
			End
		End		


		
;;====== CELEBRATING		

		AnimationState					= EMOTION_CELEBRATING
			StateName					= STATE_Emotion_Sword
			Animation					= Sword
				AnimationName			= EUGaldrl_SKL.EUGaldrl_CHRA
				AnimationMode			= ONCE
			End
			Flags						= MAINTAIN_FRAME_ACROSS_STATES RESTART_ANIM_WHEN_COMPLETE
		End


;;====== TAUNTING

		AnimationState					= EMOTION_TAUNTING
			StateName					= STATE_Emotion_Sword
			Animation					= Sword
				AnimationName			= EUGaldrl_SKL.EUGaldrl_CHRA
				AnimationMode			= ONCE
			End
			Flags						= RESTART_ANIM_WHEN_COMPLETE ;MAINTAIN_FRAME_ACROSS_STATES
		End

						
	; --- Selected Anims and Transitions
		TransitionState					=	TRANS_Idle_to_Selected
			Animation					=	ATND
				AnimationName			=	EUGaldrl_SKL.EUGaldrl_ATNA
				AnimationMode			=	ONCE
			End
		End
		
		TransitionState					=	TRANS_Selected_To_Idle
			Animation					=	ATNE
				AnimationName			=	EUGaldrl_SKL.EUGaldrl_ATNC
				AnimationMode			=	ONCE
			End
		End