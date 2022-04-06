		IdleAnimationState
			StateName = State_Idle
			Animation = Breathe 
				AnimationName = MUBalrog_SKL.MUBalrog_IDLA
				AnimationMode = ONCE
				AnimationBlendTime = 10
				AnimationPriority = 20
			End
			Animation = LookAround 
				AnimationName = MUBalrog_SKL.MUBalrog_IDLB
				AnimationMode = ONCE
				AnimationBlendTime = 10
				AnimationPriority = 2
			End
			Animation = SnortLikeABull 
				AnimationName = MUBalrog_SKL.MUBalrog_IDLC
				AnimationMode = ONCE
				AnimationBlendTime = 10
				AnimationPriority = 1
			End

			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "State_JustBuilt" 
					then CurDrawableSetTransitionAnimState("TRANS_JustBuilt_To_Idle") 
				end
				if Prev == "State_AboutToHitGround" 
					then CurDrawableSetTransitionAnimState("TRANS_AboutToHitGround_To_Idle") 
				end
			EndScript
		End 
		
		AnimationState					=	DYING DEATH_1
			Animation					=	Dying 
				AnimationName			=	MUBalrog_SKL.MUBalrog_DIEA 
				AnimationMode			=	ONCE
			End
			ParticleSysBone = None BalrogFallDust FollowBone:No
		End

		AnimationState					=	DYING DEATH_2
			Animation					=	FadingOut 
				AnimationName			=	MUBalrog_SKL.MUBalrog_RORC 
				AnimationMode			=	ONCE
			End
;			ParticleSysBone = None BalrogFallDust FollowBone:No
		End


; This is triggered by the single player only HitReaction module for the lightningsword	
; It is highest instead of lowest priority, because the hit reaction Paralyzes us, where for others it is just a fancy idle.	
		AnimationState					=	HIT_LEVEL_2
			Animation					=	Owowowowowowowow
				AnimationName			=	MUBalrog_SKL.MUBalrog_HITB 
				AnimationMode			=	ONCE
			End
		End
		
		AnimationState					=	EATING
			Animation					=	DoingHorribleThingToGrabbedGuy 
				AnimationName			=	MUBalrog_SKL.MUBalrog_BRNA 
				AnimationMode			=	ONCE
				AnimationBlendTime		=	0
			End

				ParticleSysBone = ZZZPassengerBon balrogHandSqueezeFlames FollowBone:Yes
                ParticleSysBone = ZZZPassengerBon balrogHandSqueezeFlames2 FollowBone:Yes
				ParticleSysBone = ZZZPassengerBon balrogHandSqueezeFlamesFinal FollowBone:Yes
                ParticleSysBone = ZZZPassengerBon BalrogHandSqueezeFlash FollowBone:Yes
                ParticleSysBone = ZZZPassengerBon BalrogHandSmoke FollowBone:Yes
                ParticleSysBone = RING_2_L balrogHandAsh FollowBone:Yes
                ParticleSysBone = RING_2_L balrogHandAshSmall FollowBone:Yes
;    			ParticleSysBone = LFHANDBONE BalrogHandEmbers FollowBone:Yes
;               ParticleSysBone = BAT_Elbow_L BalrogArmFireL FollowBone:Yes
;               ParticleSysBone = BAT_Shoulder_L BalrogShoulderFireL FollowBone:Yes
		End

		AnimationState					=	UNPACKING PACKING_TYPE_3
			Animation					=	GrabbingToTouching
				AnimationName			=	MUBalrog_SKL.MUBalrog_GRBA 
				AnimationMode			=	ONCE
				AnimationBlendTime		=	0
			End
		End

		AnimationState					=	PACKING PACKING_TYPE_3
			Animation					=	GrabbingFollowThrough 
				AnimationName			=	MUBalrog_SKL.MUBalrog_GRBC 
				AnimationMode			=	ONCE
				AnimationBlendTime		=	0
			End	
		End

		AnimationState			= JUST_BUILT
			StateName = State_JustBuilt
			Animation
				AnimationName = MUBalrog_SKL.MUBalrog_RORA
				AnimationMode = MANUAL
				AnimationBlendTime = 0
			End
		End
		
	    TransitionState = TRANS_JustBuilt_To_Idle
			Animation = BeingSummoned
				AnimationName = MUBalrog_SKL.MUBalrog_RORA 
				AnimationMode = ONCE
			End
		End
		
		AnimationState = FIRING_OR_PREATTACK_B
			Animation = CrackThatWhip 
				AnimationName = MUBalrog_SKL.MUBalrog_WIPA
				AnimationMode = ONCE
			End
				ParticleSysBone = RTHANDBONE BalrogWhip2swordEfx FollowBone:Yes
		End

		AnimationState			= SPECIAL_POWER_1
			Animation			= RoaringFear 
				AnimationName	= MUBalrog_SKL.MUBalrog_RORB
				AnimationMode   = ONCE
			End
				ParticleSysBone = BAT_JAW BalrogScreamEffect FollowBone:Yes
				FXEvent			= Frame:20 Name:FX_BalrogScreamEfx
				ParticleSysBone = BAT_JAW balrogPixelDisplScrm FollowBone:Yes
				ParticleSysBone = BAT_JAW balrogScrmEmbers FollowBone:Yes
		End
			   
		AnimationState			= SPECIAL_WEAPON_ONE
			Animation			= BreathingFireAnimation
				AnimationName	= MUBalrog_SKL.MUBalrog_FIRA
				AnimationMode   = ONCE
			End
				;This is Balrog's fire breath efx
				ParticleSysBone = BAT_JAW balrogFireBreath FollowBone:Yes
				ParticleSysBone = BAT_JAW balrogBreathEmbers FollowBone:Yes
				ParticleSysBone = BAT_JAW balrogBreathSmoke FollowBone:Yes
				ParticleSysBone = BAT_JAW balrogBreathProxy FollowBone:Yes
			End
			   
		AnimationState			= SPECIAL_WEAPON_TWO UNPACKING
			StateName			= State_LeapStart
			Animation			= GettingReadyToLeap
				AnimationName	= MUBalrog_SKL.MUBalrog_JMP1
				AnimationMode   = ONCE
			End
		End
			   
	    AnimationState			= SPECIAL_WEAPON_TWO PACKING
			Animation			= FirstWingBeatGoingUp 
				AnimationName	= MUBalrog_SKL.MUBalrog_JMP2
				AnimationMode   = ONCE
			End
		End
			   
	    AnimationState			= ABOUT_TO_HIT						; Before ThrownProjectile, since by definition this set for nn frames while T_P is still on
			StateName			= State_AboutToHitGround
			Animation			= StartingToLandToTouchingGround 
				AnimationName	= MUBalrog_SKL.MUBalrog_LND1
				AnimationMode   = ONCE
			End
		End
			   
		AnimationState			= THROWN_PROJECTILE
			Animation			= HurtlingThroughAir 
				AnimationName	= MUBalrog_SKL.MUBalrog_FLYA
				AnimationMode   = LOOP
				AnimationBlendTime = 10
			End
		End
			   
	    TransitionState = TRANS_AboutToHitGround_To_Idle
			Animation = SplashAtEndOfJump
				AnimationName = MUBalrog_SKL.MUBalrog_LND2 
				AnimationMode = ONCE
				AnimationBlendTime = 0
			End
		End
		
		AnimationState			= TURN_RIGHT
			Animation			= TurningRight 
				AnimationName	= MUBalrog_SKL.MUBalrog_TRNA
				AnimationMode   = LOOP
				AnimationBlendTime = 10
			End
		End

		AnimationState			= TURN_LEFT
			Animation			= TurningLeft 
				AnimationName	= MUBalrog_SKL.MUBalrog_TRNB
				AnimationMode   = LOOP
				AnimationBlendTime = 10
			End
		End

		AnimationState			= MOVING
			Animation			= Running 
				AnimationName	= MUBalrog_SKL.MUBalrog_WLKA
				AnimationMode   = LOOP
				AnimationBlendTime = 10
			End
			Flags               = RANDOMSTART
			
			FXEvent	= Frame:20 Name:FX_BalrogRightFootStep
			FXEvent	= Frame:44 Name:FX_BalrogLeftFootStep
		End
      
		AnimationState			= WEAPONSET_HERO_MODE UNPACKING PACKING_TYPE_1
			Animation = StartIgniteRoar 
				AnimationName = MUBalrog_SKL.MUBalrog_IGNTA
				AnimationMode = ONCE
			End
		End
				
		AnimationState			= HERO PACKING PACKING_TYPE_1
			Animation = FinishIgniteRoar 
				AnimationName = MUBalrog_SKL.MUBalrog_IGNTB
				AnimationMode = ONCE
			End
           
            EnteringStateFX = FX_BalrogIgniteStart
		End
				
		AnimationState			= FIRING_OR_PREATTACK_A
			Animation			= Swipe
				AnimationName	= MUBalrog_SKL.MUBalrog_ATKB
				AnimationMode	= ONCE
				UseWeaponTiming	= Yes
			End
		End
		
		AnimationState			= FIRING_OR_PREATTACK_C
			Animation			= Chop
				AnimationName	= MUBalrog_SKL.MUBalrog_ATKA
				AnimationMode	= ONCE
				UseWeaponTiming	= Yes
			End
			ParticleSysBone		= SWORDBONE BalrogSword FollowBone:yes
		End