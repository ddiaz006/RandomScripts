dir=hadded/
lumi=117
dolog=kTRUE
vars=(
  _AllJets_AODCaloJetMedianLog10TrackAngle
  _AllJets_AODCaloJetMedianLog10IPSig
  _AllJets_AODCaloJetAlphaMax
)
regions=(
  TwoMuZH
  #TwoMuDY
)

 #var=_AllJets_AODCaloJetAlphaMax
 #var=_AllJets_AODCaloJetMedianLog10IPSig
## var=_AllJets_AODCaloJetMedianLog10TrackAngle
 #var=_nSelectedAODCaloJetTag
 #var=_AOD_dileptonNewB_Pt
 #var=_dileptonNewB_Pt

# root -l -b -q 'plot_TV.C("hadded/" ,"TwoEleDY'$var'"  ,kFALSE,"117", "" )'
# root -l -b -q 'plot_TV.C("hadded/" ,"TwoMuDY'$var'"   ,kFALSE,"117", "" )'
# root -l -b -q 'plot_TV.C("hadded/" ,"EleMuOSOF'$var'" ,kFALSE,"117", "" )'
# root -l -b -q 'plot_TV.C("hadded/" ,"EleMuOSOFL'$var'",kFALSE,"117", "" )'
# 
# root -l -b -q 'plot_TV.C("hadded/" ,"TwoEleDY'$var'"  ,kTRUE,"117", "" )'
# root -l -b -q 'plot_TV.C("hadded/" ,"TwoMuDY'$var'"   ,kTRUE,"117", "" )'
# root -l -b -q 'plot_TV.C("hadded/" ,"EleMuOSOF'$var'" ,kTRUE,"117", "" )'
# root -l -b -q 'plot_TV.C("hadded/" ,"EleMuOSOFL'$var'",kTRUE,"117", "" )'

 #root -l -b -q 'plot_TV.C("inputs_JEC_Heavy_PreApp_2_setCMSenv_ninetyTF_FinalShifts_SFFix/hadded/" ,"TwoMuZH'$var'"  ,kTRUE,"117", "" )'
 
 #root -l -b -q 'plot_TV.C("hadded/" ,"TwoMuOffZ'$var'"  ,kFALSE,"117", "" )'
 #root -l -b -q 'plot_TV.C("hadded/" ,"TwoEleOffZ'$var'"  ,kFALSE,"117", "" )'
 
 #root -l -b -q 'plot_TV.C("hadded/" ,"eemumu'$var'"  ,kFALSE,"117", "" )'
 #root -l -b -q 'plot_TV.C("hadded/" ,"TwoEleZH'$var'"  ,kTRUE,"117", "" )'
 #root -l -b -q 'plot_TV.C("hadded/" ,"TwoEleZH'$var'"  ,kFALSE,"117", "" )'
## root -l -b -q 'plot_TV.C("hadded/" ,"TwoMuZH'$var'"  ,kTRUE,"117", "" )'
## root -l -b -q 'plot_TV.C("hadded/" ,"TwoMuZH'$var'"  ,kFALSE,"117", "" )'
 #root -l -b -q 'plot_TV.C("hadded/" ,"TwoMuDY'$var'"  ,kTRUE,"117", "" )'
 #root -l -b -q 'plot_TV.C("hadded/" ,"TwoMuDY'$var'"  ,kFALSE,"117", "" )'

for region in ${regions[@]}
do
  for var in ${vars[@]} 
  do
    root -l -b -q 'plot_TV.C("'$dir'" ,"'$region$var'"  ,'$dolog',"'$lumi'", "" )'
  done
done
