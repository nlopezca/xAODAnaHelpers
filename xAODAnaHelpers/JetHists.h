
#ifndef xAODAnaHelpers_JetHists_H
#define xAODAnaHelpers_JetHists_H

#include "xAODAnaHelpers/IParticleHists.h"
#include "xAODAnaHelpers/HelperClasses.h"
#include "xAODAnaHelpers/TracksInJetHists.h"
#include <xAODJet/JetContainer.h>
#include "xAODAnaHelpers/Jet.h"
#include "xAODAnaHelpers/EventInfo.h"
#include "xAODAnaHelpers/OnlineBeamSpotTool.h"

ANA_MSG_HEADER(msgJetHists)

class JetHists : public IParticleHists
{
  public:


  JetHists(std::string name, std::string detailStr, const std::string& prefix="jet", const std::string& titleprefix="jet");
    virtual ~JetHists() ;

    virtual StatusCode initialize();
    virtual StatusCode execute( const xAOD::Jet* jet, float eventWeight, const xAOD::EventInfo* eventInfo = 0 );
    virtual StatusCode execute( const xAH::Jet* jet,  float eventWeight, const xAH::EventInfo* eventInfo = 0);
    virtual StatusCode finalize();

    using HistogramManager::book; // make other overloaded version of book() to show up in subclass
    using IParticleHists::execute; // overload
    virtual void record(EL::IWorker* wk);

  protected:

    virtual StatusCode execute( const xAOD::IParticle* particle, float eventWeight, const xAOD::EventInfo* eventInfo = 0 );
    virtual StatusCode execute( const xAH::Particle* particle,   float eventWeight, const xAH::EventInfo* eventInfo = 0 );

    // holds bools that control which histograms are filled
    HelperClasses::JetInfoSwitch* m_infoSwitch;

  private:

    std::string m_titlePrefix;
    xAH::OnlineBeamSpotTool      m_onlineBSTool;  //!

    // clean
    TH1D* m_jetTime;                //!
    TH1D* m_LArQuality;             //!
    TH1D* m_hecq;                   //!
    TH1D* m_negE;                   //!
    TH1D* m_avLArQF;                //!
    TH1D* m_bchCorrCell;            //!
    TH1D* m_N90Const;               //!
    //TH1D* m_LArQmean;
    //TH1D* m_LArBadHVEFrac;
    //TH1D* m_LArBadHVNCell;
    //TH1D* m_OotFracClusters5;
    //TH1D* m_OotFracClusters10;
    //TH1D* m_LeadingClusterPt;
    //TH1D* m_LeadingClusterSecondLambda;
    //TH1D* m_LeadingClusterCenterLambda;
    //TH1D* m_LeadingClusterSecondR;
    //TH1D* m_clean_passLooseBad;
    //TH1D* m_clean_passLooseBadUgly;
    //TH1D* m_clean_passTightBad;
    //TH1D* m_clean_passTightBadUgly;


    //layer
    TH1D* m_PreSamplerB;
    TH1D* m_EMB1;
    TH1D* m_EMB2;
    TH1D* m_EMB3;
    TH1D* m_PreSamplerE;            //!
    TH1D* m_EME1;                   //!
    TH1D* m_EME2;                   //!
    TH1D* m_EME3;                   //!
    TH1D* m_HEC0;                   //!
    TH1D* m_HEC1;                   //!
    TH1D* m_HEC2;                   //!
    TH1D* m_HEC3;                   //!
    TH1D* m_TileBar0;               //!
    TH1D* m_TileBar1;               //!
    TH1D* m_TileBar2;               //!
    TH1D* m_TileGap1;               //!
    TH1D* m_TileGap2;               //!
    TH1D* m_TileGap3;               //!
    TH1D* m_TileExt0;               //!
    TH1D* m_TileExt1;               //!
    TH1D* m_TileExt2;               //!
    TH1D* m_FCAL0;                  //!
    TH1D* m_FCAL1;                  //!
    TH1D* m_FCAL2;                  //!

    // area
    TH1D* m_actArea;                //!


    TH1D* m_chf;                    //!

    //energy
    TH1D* m_HECf;                   //!
    TH1D* m_EMf;                    //!
    TH1D* m_centroidR;              //!
    TH1D* m_fracSampMax;            //!
    TH1D* m_fracSampMaxIdx;         //!
    TH1D* m_lowEtFrac;              //!
    //TH1D* m_GhostMuonSegmentCount;
    //TH1D* m_Width;


    // resolution
    TH1D* m_jetGhostTruthPt;        //!
    TH2F* m_jetPt_vs_resolution;    //!
    TH2F* m_jetGhostTruthPt_vs_resolution; //!

    // truth jets
    TH1D* m_truthLabelID;          //!
    TH1D* m_hadronConeExclTruthLabelID;          //!
    TH1D* m_partonTruthLabelID;          //!
    TH1D* m_truthCount;            //!
    TH1D* m_truthPt;               //!
    TH1D* m_truthPt_m;               //!
    TH1D* m_truthPt_l;               //!
    TH1D* m_truthEta;               //!
    TH1D* m_truthPhi;               //!
    TH1D* m_truthDr_B;             //!
    TH1D* m_truthDr_C;             //!
    TH1D* m_truthDr_T;             //!
    //TH1D *m_GhostTruthAssociationFraction;

    // Detailed truth jet plots
    TH1D* m_truthCount_BhadFinal;  //!
    TH1D* m_truthCount_BhadInit ;  //!
    TH1D* m_truthCount_BQFinal  ;  //!
    TH1D* m_truthPt_BhadFinal;  //!
    TH1D* m_truthPt_BhadInit ;  //!
    TH1D* m_truthPt_BQFinal  ;  //!

    TH1D* m_truthCount_ChadFinal;  //!
    TH1D* m_truthCount_ChadInit ;  //!
    TH1D* m_truthCount_CQFinal  ;  //!
    TH1D* m_truthPt_ChadFinal;  //!
    TH1D* m_truthPt_ChadInit ;  //!
    TH1D* m_truthPt_CQFinal  ;  //!


    TH1D* m_truthCount_TausFinal; //!
    TH1D* m_truthPt_TausFinal   ; //!

    // JVC
    TH1D* m_JVC; //!

    // Flavor Tag
    TH1D* m_MV1   ; //!
    TH1D* m_MV2c00   ; //!
    TH1D* m_MV2c10   ; //!
    TH1D* m_MV2c10_l ; //!
    TH1D* m_MV2c20   ; //!
    TH1D* m_COMB   ; //!
    TH1D* m_SV0             ; //!
    TH1D* m_JetFitter       ; //!
    //TH1D* m_MV2;
    //TH2F* m_IP3DvsMV2c20;



    TProfile* m_vtxClass_vs_lBlock; //!
    TProfile* m_vtxEff10_vs_lBlock; //!
    TProfile* m_vtxEff1_vs_lBlock; //!
    TProfile* m_vtxEff10_raw_vs_lBlock; //!
    TProfile* m_vtxEff1_raw_vs_lBlock; //!
    TProfile* m_vtxEff10_noDummy_vs_lBlock; //!
    TProfile* m_vtxEff1_noDummy_vs_lBlock; //!
    TProfile* m_frac_MV240_vs_actMu; //!
    TProfile* m_frac_MV250_vs_actMu; //!
    TProfile* m_frac_MV260_vs_actMu; //!
    TProfile* m_frac_MV270_vs_actMu; //!
    TProfile* m_frac_MV277_vs_actMu; //!
    TProfile* m_frac_MV285_vs_actMu; //!
    TProfile* m_frac_MV240_vs_lBlock; //!
    TProfile* m_frac_MV250_vs_lBlock; //!
    TProfile* m_frac_MV260_vs_lBlock; //!
    TProfile* m_frac_MV270_vs_lBlock; //!
    TProfile* m_frac_MV277_vs_lBlock; //!
    TProfile* m_frac_MV285_vs_lBlock; //!



    TH1D* m_trkSum_ntrk     ; //!
    TH1D* m_trkSum_sPt      ; //!
    TH1D* m_trkSum_vPt      ; //!
    TH1D* m_trkSum_vAbsEta  ; //!
    TH1D* m_width           ; //!
    TH1D* m_n_trk_sigd0cut  ; //!
    TH1D* m_trk3_d0sig      ; //!
    TH1D* m_trk3_z0sig      ; //!
    TH1D* m_sv_scaled_efc   ; //!
    TH1D* m_jf_scaled_efc   ; //!

    TH1D* m_jf_nVTX           ; //!
    TH1D* m_jf_nSingleTracks  ; //!
    TH1D* m_jf_nTracksAtVtx   ; //!
    TH1D* m_jf_mass           ; //!
    TH1D* m_jf_energyFraction ; //!
    TH1D* m_jf_significance3d ; //!
    TH1D* m_jf_deltaeta       ; //!
    TH1D* m_jf_deltaeta_l     ; //!
    TH1D* m_jf_deltaphi       ; //!
    TH1D* m_jf_deltaphi_l     ; //!
    TH1D* m_jf_deltaR         ; //!
    TH1D* m_jf_N2Tpar         ; //!
    TH1D* m_jf_pb             ; //!
    TH1D* m_jf_pc             ; //!
    TH1D* m_jf_pu             ; //!
    TH1D* m_jf_mass_unco      ; //!
    TH1D* m_jf_dR_flight      ; //!

    TH1D* m_sv0_NGTinSvx ; //!
    TH1D* m_sv0_N2Tpair  ; //!
    TH1D* m_sv0_massvx   ; //!
    TH1D* m_sv0_efracsvx ; //!
    TH1D* m_sv0_normdist ; //!

    TH1D* m_SV1_pu       ; //!
    TH1D* m_SV1_pb       ; //!
    TH1D* m_SV1_pc       ; //!
    TH1D* m_SV1          ; //!
    TH1D* m_SV1_c        ; //!
    TH1D* m_SV1_cu       ; //!
    TH1D* m_sv1_NGTinSvx ; //!
    TH1D* m_sv1_N2Tpair  ; //!
    TH1D* m_sv1_massvx   ; //!
    TH1D* m_sv1_efracsvx ; //!
    TH1D* m_sv1_normdist ; //!
    TH1D* m_SV1_Lxy        ; //!
    TH1D* m_SV1_sig3d        ; //!
    TH1D* m_SV1_L3d        ; //!
    TH1D* m_SV1_distmatlay ; //!TH1D
    TH1D* m_SV1_dR         ; //!

    TH1D* m_nIP2DTracks              ; //!
    TH1D* m_IP2D_gradeOfTracks       ; //!
    TH1D* m_IP2D_flagFromV0ofTracks  ; //!
    TH1D* m_IP2D_valD0wrtPVofTracks  ; //!
    TH1D* m_IP2D_sigD0wrtPVofTracks  ; //!
    TH1D* m_IP2D_sigD0wrtPVofTracks_l; //!
    TH1D* m_IP2D_errD0wrtPVofTracks  ; //!
    TH1D* m_IP2D_weightBofTracks     ; //!
    TH1D* m_IP2D_weightCofTracks     ; //!
    TH1D* m_IP2D_weightUofTracks     ; //!
    TH1D* m_IP2D_pu                  ; //!
    TH1D* m_IP2D_pb                  ; //!
    TH1D* m_IP2D_pc                  ; //!
    TH1D* m_IP2D                     ; //!
    TH1D* m_IP2D_c                   ; //!
    TH1D* m_IP2D_cu                  ; //!

    TH1D* m_nIP3DTracks              ; //!
    TH1D* m_IP3D_gradeOfTracks       ; //!
    TH1D* m_IP3D_flagFromV0ofTracks  ; //!
    TH1D* m_IP3D_valD0wrtPVofTracks  ; //!
    TH1D* m_IP3D_sigD0wrtPVofTracks  ; //!
    TH1D* m_IP3D_sigD0wrtPVofTracks_l; //!
    TH1D* m_IP3D_errD0wrtPVofTracks  ; //!
    TH1D* m_IP3D_valZ0wrtPVofTracks  ; //!
    TH1D* m_IP3D_sigZ0wrtPVofTracks  ; //!
    TH1D* m_IP3D_sigZ0wrtPVofTracks_l; //!
    TH1D* m_IP3D_errZ0wrtPVofTracks  ; //!
    TH1D* m_IP3D_weightBofTracks     ; //!
    TH1D* m_IP3D_weightCofTracks     ; //!
    TH1D* m_IP3D_weightUofTracks     ; //!
    TH1D* m_IP3D_pu                  ; //!
    TH1D* m_IP3D_pb                  ; //!
    TH1D* m_IP3D_pc                  ; //!
    TH1D* m_IP3D                     ; //!
    TH1D* m_IP3D_c                   ; //!
    TH1D* m_IP3D_cu                  ; //!

    // substructure
    TH1D* m_tau1; //!
    TH1D* m_tau2; //!
    TH1D* m_tau3; //!
    TH1D* m_tau21; //!
    TH1D* m_tau32; //!
    TH1D* m_tau1_wta; //!
    TH1D* m_tau2_wta; //!
    TH1D* m_tau3_wta; //!
    TH1D* m_tau21_wta; //!
    TH1D* m_tau32_wta; //!
    TH1D* m_numConstituents; //!

    // Tracks in Jets
    TH1D* m_nTrk; //!
    TracksInJetHists* m_tracksInJet; //!

    // By eta
    TH1D* m_jetPt_eta_0_1; //!
    TH1D* m_jetPt_eta_1_2; //!
    TH1D* m_jetPt_eta_2_2p5; //!
    TH1D* m_jetPt_eta_1_2p5; //!

    // bs information
    TH1D* m_bs_online_vx; //!
    TH1D* m_bs_online_vy; //!
    TH1D* m_bs_online_vz; //!
    TH1D* m_bs_online_vz_l; //!

    TH1D* m_eta_bs_online_vz_0_1  ; //!
    TH1D* m_eta_bs_online_vz_1_1p5; //!
    TH1D* m_eta_bs_online_vz_1p5_2; //!

    // HLT Vertex Comp
    TH1D*     m_vtx_offline_x0; //!
    TH1D*     m_vtx_offline_y0; //!
    TH1D*     m_vtx_offline_z0; //!
    TH1D*     m_vtx_offline_z0_s; //!
    TH1D*     m_vtx_online_x0; //!
    TH1D*     m_vtx_online_y0; //!
    TH1D*     m_vtx_online_z0; //!
    TH1D*     m_vtx_online_z0_s; //!
    TH1D*     m_vtx_online_x0_raw; //!
    TH1D*     m_vtx_online_y0_raw; //!
    TH1D*     m_vtx_online_z0_raw; //!

    TH1D* m_vtxOnlineValid; //!
    TH1D* m_vtxOfflineValid; //!
    TH1D* m_vtxDiffz0; //!
    TH1D* m_vtxDiffz0_m; //!
    TH1D* m_vtxDiffz0_s; //!

    TH1D* m_vtxBkgDiffz0; //!
    TH1D* m_vtxBkgDiffz0_m; //!
    TH1D* m_vtxBkgDiffz0_s; //!

    TH1D* m_vtxDiffx0; //!
    TH1D* m_vtxDiffx0_l; //!

    TH1D* m_vtxDiffy0; //!
    TH1D* m_vtxDiffy0_l; //!

    TH1D* m_vtxClass; //!
    TProfile*   m_vtxDiffx0_vs_lBlock    ; //!
    TProfile*   m_vtxDiffy0_vs_lBlock    ; //!
    TProfile*   m_vtxDiffz0_vs_lBlock    ; //!

    TH2F* m_lumiB_runN; //!
    TH2F* m_lumiB_runN_vtxClass     ; //!
    TH2F* m_lumiB_runN_vtxDiffz0    ; //!
    TH2F* m_lumiB_runN_lumiB        ; //!
    TH2F* m_lumiB_runN_bs_online_vz ; //!
    TH2F* m_lumiB_runN_bs_den       ; //!

    TProfile*   m_vtx_online_x0_vs_vtx_online_z0; //!
    TProfile*   m_vtx_online_y0_vs_vtx_online_z0; //!

    // trackPV
    //TH1D* m_NumTrkPt1000PV;
    //TH1D* m_SumPtTrkPt1000PV;
    //TH1D* m_TrackWidthPt1000PV;
    //TH1D* m_NumTrkPt500PV;
    //TH1D* m_SumPtTrkPt500PV;
    //TH1D* m_TrackWidthPt500PV;
    //TH1D* m_JVFPV;

    // trackAll or trackPV
    //TH1D* m_Jvt;
    //TH1D* m_JvtJvfcorr;
    //TH1D* m_JvtRpt;


    // charge
    //TH1D *m_charge;

    TH1D* m_actualMu;                   // !
    TH1D* m_avgMu;
    TH1D* m_jetPt_avgMu_00_15;
    TH1D* m_jetPt_avgMu_15_25;
    TH1D* m_jetPt_avgMu_25;
    TH2F* m_avgMu_vs_jetPt;

    // Eta-phi map
    TH2F* m_etaPhi;

    // Some other 2D plots
    TH2F* m_vtxDiffz0_vs_vtx_offline_z0;
    TH2F* m_vtxDiffz0_s_vs_vtx_offline_z0;
    TH2F* m_vtxDiffz0_s_vs_vtxDiffx0;
    TH2F* m_vtxDiffz0_s_vs_vtxDiffy0;

    // TProfile in prep for showing it is flat
    TH2F*  m_vtxClass_vs_jetPt;

};

#endif
