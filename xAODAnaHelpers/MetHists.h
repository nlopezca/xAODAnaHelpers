#ifndef xAODAnaHelpers_MetHists_H
#define xAODAnaHelpers_MetHists_H

#include "xAODAnaHelpers/HistogramManager.h"
#include "xAODAnaHelpers/HelperClasses.h"
#include "xAODMissingET/MissingETContainer.h"

class MetHists : public HistogramManager
{
  public:


    MetHists(std::string name, std::string detailStr);
    virtual ~MetHists() ;

    bool m_debug;
    StatusCode initialize();
    StatusCode execute( const xAOD::MissingETContainer* met, float eventWeight );

    using HistogramManager::book; // make other overloaded version of book() to show up in subclass
    using HistogramManager::execute; // overload

  protected:

    // holds bools that control which histograms are filled
    HelperClasses::METInfoSwitch* m_infoSwitch;

  private:

    TH1D*   m_metFinalClus      ; //!
    TH1D*   m_metFinalClusPx    ; //!
    TH1D*   m_metFinalClusPy    ; //!
    TH1D*   m_metFinalClusSumEt ; //!
    TH1D*   m_metFinalClusPhi   ; //!

    TH1D*   m_metFinalTrk       ; //!
    TH1D*   m_metFinalTrkPx     ; //!
    TH1D*   m_metFinalTrkPy     ; //!
    TH1D*   m_metFinalTrkSumEt  ; //!
    TH1D*   m_metFinalTrkPhi    ; //!

};

#endif
