#include "evaluate.hxx"
#include "visitors/sqlite_visitor.hxx"
#include "solvers/discrete_tomography/discrete_tomography.h"
#include "lp_interface/lp_gurobi.hxx"

using namespace LP_MP;

std::string dt_synthetic_prefix = "discrete_tomography_datasets/discrete_tomography_synthetic/mp";

std::string dt_synthetic_prefix_2_1 = "/2/1/";
std::vector<std::string> dt_synthetic_sparsity_1 = {
   {"1/0.10_0.10_100.txt"},
   {"1/0.10_0.10_10.txt"},
   {"1/0.10_0.10_11.txt"},
   {"1/0.10_0.10_12.txt"},
   {"1/0.10_0.10_13.txt"},
   {"1/0.10_0.10_14.txt"},
   {"1/0.10_0.10_15.txt"},
   {"1/0.10_0.10_16.txt"},
   {"1/0.10_0.10_17.txt"},
   {"1/0.10_0.10_18.txt"},
   {"1/0.10_0.10_19.txt"},
   {"1/0.10_0.10_1.txt"},
   {"1/0.10_0.10_20.txt"},
   {"1/0.10_0.10_21.txt"},
   {"1/0.10_0.10_22.txt"},
   {"1/0.10_0.10_23.txt"},
   {"1/0.10_0.10_24.txt"},
   {"1/0.10_0.10_25.txt"},
   {"1/0.10_0.10_26.txt"},
   {"1/0.10_0.10_27.txt"},
   {"1/0.10_0.10_28.txt"},
   {"1/0.10_0.10_29.txt"},
   {"1/0.10_0.10_2.txt"},
   {"1/0.10_0.10_30.txt"},
   {"1/0.10_0.10_31.txt"},
   {"1/0.10_0.10_32.txt"},
   {"1/0.10_0.10_33.txt"},
   {"1/0.10_0.10_34.txt"},
   {"1/0.10_0.10_35.txt"},
   {"1/0.10_0.10_36.txt"},
   {"1/0.10_0.10_37.txt"},
   {"1/0.10_0.10_38.txt"},
   {"1/0.10_0.10_39.txt"},
   {"1/0.10_0.10_3.txt"},
   {"1/0.10_0.10_40.txt"},
   {"1/0.10_0.10_41.txt"},
   {"1/0.10_0.10_42.txt"},
   {"1/0.10_0.10_43.txt"},
   {"1/0.10_0.10_44.txt"},
   {"1/0.10_0.10_45.txt"},
   {"1/0.10_0.10_46.txt"},
   {"1/0.10_0.10_47.txt"},
   {"1/0.10_0.10_48.txt"},
   {"1/0.10_0.10_49.txt"},
   {"1/0.10_0.10_4.txt"},
   {"1/0.10_0.10_50.txt"},
   {"1/0.10_0.10_51.txt"},
   {"1/0.10_0.10_52.txt"},
   {"1/0.10_0.10_53.txt"},
   {"1/0.10_0.10_54.txt"},
   {"1/0.10_0.10_55.txt"},
   {"1/0.10_0.10_56.txt"},
   {"1/0.10_0.10_57.txt"},
   {"1/0.10_0.10_58.txt"},
   {"1/0.10_0.10_59.txt"},
   {"1/0.10_0.10_5.txt"},
   {"1/0.10_0.10_60.txt"},
   {"1/0.10_0.10_61.txt"},
   {"1/0.10_0.10_62.txt"},
   {"1/0.10_0.10_63.txt"},
   {"1/0.10_0.10_64.txt"},
   {"1/0.10_0.10_65.txt"},
   {"1/0.10_0.10_66.txt"},
   {"1/0.10_0.10_67.txt"},
   {"1/0.10_0.10_68.txt"},
   {"1/0.10_0.10_69.txt"},
   {"1/0.10_0.10_6.txt"},
   {"1/0.10_0.10_70.txt"},
   {"1/0.10_0.10_71.txt"},
   {"1/0.10_0.10_72.txt"},
   {"1/0.10_0.10_73.txt"},
   {"1/0.10_0.10_74.txt"},
   {"1/0.10_0.10_75.txt"},
   {"1/0.10_0.10_76.txt"},
   {"1/0.10_0.10_77.txt"},
   {"1/0.10_0.10_78.txt"},
   {"1/0.10_0.10_79.txt"},
   {"1/0.10_0.10_7.txt"},
   {"1/0.10_0.10_80.txt"},
   {"1/0.10_0.10_81.txt"},
   {"1/0.10_0.10_82.txt"},
   {"1/0.10_0.10_83.txt"},
   {"1/0.10_0.10_84.txt"},
   {"1/0.10_0.10_85.txt"},
   {"1/0.10_0.10_86.txt"},
   {"1/0.10_0.10_87.txt"},
   {"1/0.10_0.10_88.txt"},
   {"1/0.10_0.10_89.txt"},
   {"1/0.10_0.10_8.txt"},
   {"1/0.10_0.10_90.txt"},
   {"1/0.10_0.10_91.txt"},
   {"1/0.10_0.10_92.txt"},
   {"1/0.10_0.10_93.txt"},
   {"1/0.10_0.10_94.txt"},
   {"1/0.10_0.10_95.txt"},
   {"1/0.10_0.10_96.txt"},
   {"1/0.10_0.10_97.txt"},
   {"1/0.10_0.10_98.txt"},
   {"1/0.10_0.10_99.txt"},
   {"1/0.10_0.10_9.txt"}
};

std::vector<std::string> dt_synthetic_sparsity_2 = {
   {"2/0.20_0.20_100.txt"},
   {"2/0.20_0.20_10.txt"},
   {"2/0.20_0.20_11.txt"},
   {"2/0.20_0.20_12.txt"},
   {"2/0.20_0.20_13.txt"},
   {"2/0.20_0.20_14.txt"},
   {"2/0.20_0.20_15.txt"},
   {"2/0.20_0.20_16.txt"},
   {"2/0.20_0.20_17.txt"},
   {"2/0.20_0.20_18.txt"},
   {"2/0.20_0.20_19.txt"},
   {"2/0.20_0.20_1.txt"},
   {"2/0.20_0.20_20.txt"},
   {"2/0.20_0.20_21.txt"},
   {"2/0.20_0.20_22.txt"},
   {"2/0.20_0.20_23.txt"},
   {"2/0.20_0.20_24.txt"},
   {"2/0.20_0.20_25.txt"},
   {"2/0.20_0.20_26.txt"},
   {"2/0.20_0.20_27.txt"},
   {"2/0.20_0.20_28.txt"},
   {"2/0.20_0.20_29.txt"},
   {"2/0.20_0.20_2.txt"},
   {"2/0.20_0.20_30.txt"},
   {"2/0.20_0.20_31.txt"},
   {"2/0.20_0.20_32.txt"},
   {"2/0.20_0.20_33.txt"},
   {"2/0.20_0.20_34.txt"},
   {"2/0.20_0.20_35.txt"},
   {"2/0.20_0.20_36.txt"},
   {"2/0.20_0.20_37.txt"},
   {"2/0.20_0.20_38.txt"},
   {"2/0.20_0.20_39.txt"},
   {"2/0.20_0.20_3.txt"},
   {"2/0.20_0.20_40.txt"},
   {"2/0.20_0.20_41.txt"},
   {"2/0.20_0.20_42.txt"},
   {"2/0.20_0.20_43.txt"},
   {"2/0.20_0.20_44.txt"},
   {"2/0.20_0.20_45.txt"},
   {"2/0.20_0.20_46.txt"},
   {"2/0.20_0.20_47.txt"},
   {"2/0.20_0.20_48.txt"},
   {"2/0.20_0.20_49.txt"},
   {"2/0.20_0.20_4.txt"},
   {"2/0.20_0.20_50.txt"},
   {"2/0.20_0.20_51.txt"},
   {"2/0.20_0.20_52.txt"},
   {"2/0.20_0.20_53.txt"},
   {"2/0.20_0.20_54.txt"},
   {"2/0.20_0.20_55.txt"},
   {"2/0.20_0.20_56.txt"},
   {"2/0.20_0.20_57.txt"},
   {"2/0.20_0.20_58.txt"},
   {"2/0.20_0.20_59.txt"},
   {"2/0.20_0.20_5.txt"},
   {"2/0.20_0.20_60.txt"},
   {"2/0.20_0.20_61.txt"},
   {"2/0.20_0.20_62.txt"},
   {"2/0.20_0.20_63.txt"},
   {"2/0.20_0.20_64.txt"},
   {"2/0.20_0.20_65.txt"},
   {"2/0.20_0.20_66.txt"},
   {"2/0.20_0.20_67.txt"},
   {"2/0.20_0.20_68.txt"},
   {"2/0.20_0.20_69.txt"},
   {"2/0.20_0.20_6.txt"},
   {"2/0.20_0.20_70.txt"},
   {"2/0.20_0.20_71.txt"},
   {"2/0.20_0.20_72.txt"},
   {"2/0.20_0.20_73.txt"},
   {"2/0.20_0.20_74.txt"},
   {"2/0.20_0.20_75.txt"},
   {"2/0.20_0.20_76.txt"},
   {"2/0.20_0.20_77.txt"},
   {"2/0.20_0.20_78.txt"},
   {"2/0.20_0.20_79.txt"},
   {"2/0.20_0.20_7.txt"},
   {"2/0.20_0.20_80.txt"},
   {"2/0.20_0.20_81.txt"},
   {"2/0.20_0.20_82.txt"},
   {"2/0.20_0.20_83.txt"},
   {"2/0.20_0.20_84.txt"},
   {"2/0.20_0.20_85.txt"},
   {"2/0.20_0.20_86.txt"},
   {"2/0.20_0.20_87.txt"},
   {"2/0.20_0.20_88.txt"},
   {"2/0.20_0.20_89.txt"},
   {"2/0.20_0.20_8.txt"},
   {"2/0.20_0.20_90.txt"},
   {"2/0.20_0.20_91.txt"},
   {"2/0.20_0.20_92.txt"},
   {"2/0.20_0.20_93.txt"},
   {"2/0.20_0.20_94.txt"},
   {"2/0.20_0.20_95.txt"},
   {"2/0.20_0.20_96.txt"},
   {"2/0.20_0.20_97.txt"},
   {"2/0.20_0.20_98.txt"},
   {"2/0.20_0.20_99.txt"},
   {"2/0.20_0.20_9.txt"}
};   

std::vector<std::string> dt_synthetic_sparsity_3 = {
   {"3/0.30_0.30_100.txt"},
   {"3/0.30_0.30_10.txt"},
   {"3/0.30_0.30_11.txt"},
   {"3/0.30_0.30_12.txt"},
   {"3/0.30_0.30_13.txt"},
   {"3/0.30_0.30_14.txt"},
   {"3/0.30_0.30_15.txt"},
   {"3/0.30_0.30_16.txt"},
   {"3/0.30_0.30_17.txt"},
   {"3/0.30_0.30_18.txt"},
   {"3/0.30_0.30_19.txt"},
   {"3/0.30_0.30_1.txt"},
   {"3/0.30_0.30_20.txt"},
   {"3/0.30_0.30_21.txt"},
   {"3/0.30_0.30_22.txt"},
   {"3/0.30_0.30_23.txt"},
   {"3/0.30_0.30_24.txt"},
   {"3/0.30_0.30_25.txt"},
   {"3/0.30_0.30_26.txt"},
   {"3/0.30_0.30_27.txt"},
   {"3/0.30_0.30_28.txt"},
   {"3/0.30_0.30_29.txt"},
   {"3/0.30_0.30_2.txt"},
   {"3/0.30_0.30_30.txt"},
   {"3/0.30_0.30_31.txt"},
   {"3/0.30_0.30_32.txt"},
   {"3/0.30_0.30_33.txt"},
   {"3/0.30_0.30_34.txt"},
   {"3/0.30_0.30_35.txt"},
   {"3/0.30_0.30_36.txt"},
   {"3/0.30_0.30_37.txt"},
   {"3/0.30_0.30_38.txt"},
   {"3/0.30_0.30_39.txt"},
   {"3/0.30_0.30_3.txt"},
   {"3/0.30_0.30_40.txt"},
   {"3/0.30_0.30_41.txt"},
   {"3/0.30_0.30_42.txt"},
   {"3/0.30_0.30_43.txt"},
   {"3/0.30_0.30_44.txt"},
   {"3/0.30_0.30_45.txt"},
   {"3/0.30_0.30_46.txt"},
   {"3/0.30_0.30_47.txt"},
   {"3/0.30_0.30_48.txt"},
   {"3/0.30_0.30_49.txt"},
   {"3/0.30_0.30_4.txt"},
   {"3/0.30_0.30_50.txt"},
   {"3/0.30_0.30_51.txt"},
   {"3/0.30_0.30_52.txt"},
   {"3/0.30_0.30_53.txt"},
   {"3/0.30_0.30_54.txt"},
   {"3/0.30_0.30_55.txt"},
   {"3/0.30_0.30_56.txt"},
   {"3/0.30_0.30_57.txt"},
   {"3/0.30_0.30_58.txt"},
   {"3/0.30_0.30_59.txt"},
   {"3/0.30_0.30_5.txt"},
   {"3/0.30_0.30_60.txt"},
   {"3/0.30_0.30_61.txt"},
   {"3/0.30_0.30_62.txt"},
   {"3/0.30_0.30_63.txt"},
   {"3/0.30_0.30_64.txt"},
   {"3/0.30_0.30_65.txt"},
   {"3/0.30_0.30_66.txt"},
   {"3/0.30_0.30_67.txt"},
   {"3/0.30_0.30_68.txt"},
   {"3/0.30_0.30_69.txt"},
   {"3/0.30_0.30_6.txt"},
   {"3/0.30_0.30_70.txt"},
   {"3/0.30_0.30_71.txt"},
   {"3/0.30_0.30_72.txt"},
   {"3/0.30_0.30_73.txt"},
   {"3/0.30_0.30_74.txt"},
   {"3/0.30_0.30_75.txt"},
   {"3/0.30_0.30_76.txt"},
   {"3/0.30_0.30_77.txt"},
   {"3/0.30_0.30_78.txt"},
   {"3/0.30_0.30_79.txt"},
   {"3/0.30_0.30_7.txt"},
   {"3/0.30_0.30_80.txt"},
   {"3/0.30_0.30_81.txt"},
   {"3/0.30_0.30_82.txt"},
   {"3/0.30_0.30_83.txt"},
   {"3/0.30_0.30_84.txt"},
   {"3/0.30_0.30_85.txt"},
   {"3/0.30_0.30_86.txt"},
   {"3/0.30_0.30_87.txt"},
   {"3/0.30_0.30_88.txt"},
   {"3/0.30_0.30_89.txt"},
   {"3/0.30_0.30_8.txt"},
   {"3/0.30_0.30_90.txt"},
   {"3/0.30_0.30_91.txt"},
   {"3/0.30_0.30_92.txt"},
   {"3/0.30_0.30_93.txt"},
   {"3/0.30_0.30_94.txt"},
   {"3/0.30_0.30_95.txt"},
   {"3/0.30_0.30_96.txt"},
   {"3/0.30_0.30_97.txt"},
   {"3/0.30_0.30_98.txt"},
   {"3/0.30_0.30_99.txt"},
   {"3/0.30_0.30_9.txt"}
};

std::vector<std::string> dt_synthetic_sparsity_4 = {
   {"4/0.40_0.40_100.txt"},
   {"4/0.40_0.40_10.txt"},
   {"4/0.40_0.40_11.txt"},
   {"4/0.40_0.40_12.txt"},
   {"4/0.40_0.40_13.txt"},
   {"4/0.40_0.40_14.txt"},
   {"4/0.40_0.40_15.txt"},
   {"4/0.40_0.40_16.txt"},
   {"4/0.40_0.40_17.txt"},
   {"4/0.40_0.40_18.txt"},
   {"4/0.40_0.40_19.txt"},
   {"4/0.40_0.40_1.txt"},
   {"4/0.40_0.40_20.txt"},
   {"4/0.40_0.40_21.txt"},
   {"4/0.40_0.40_22.txt"},
   {"4/0.40_0.40_23.txt"},
   {"4/0.40_0.40_24.txt"},
   {"4/0.40_0.40_25.txt"},
   {"4/0.40_0.40_26.txt"},
   {"4/0.40_0.40_27.txt"},
   {"4/0.40_0.40_28.txt"},
   {"4/0.40_0.40_29.txt"},
   {"4/0.40_0.40_2.txt"},
   {"4/0.40_0.40_30.txt"},
   {"4/0.40_0.40_31.txt"},
   {"4/0.40_0.40_32.txt"},
   {"4/0.40_0.40_33.txt"},
   {"4/0.40_0.40_34.txt"},
   {"4/0.40_0.40_35.txt"},
   {"4/0.40_0.40_36.txt"},
   {"4/0.40_0.40_37.txt"},
   {"4/0.40_0.40_38.txt"},
   {"4/0.40_0.40_39.txt"},
   {"4/0.40_0.40_3.txt"},
   {"4/0.40_0.40_40.txt"},
   {"4/0.40_0.40_41.txt"},
   {"4/0.40_0.40_42.txt"},
   {"4/0.40_0.40_43.txt"},
   {"4/0.40_0.40_44.txt"},
   {"4/0.40_0.40_45.txt"},
   {"4/0.40_0.40_46.txt"},
   {"4/0.40_0.40_47.txt"},
   {"4/0.40_0.40_48.txt"},
   {"4/0.40_0.40_49.txt"},
   {"4/0.40_0.40_4.txt"},
   {"4/0.40_0.40_50.txt"},
   {"4/0.40_0.40_51.txt"},
   {"4/0.40_0.40_52.txt"},
   {"4/0.40_0.40_53.txt"},
   {"4/0.40_0.40_54.txt"},
   {"4/0.40_0.40_55.txt"},
   {"4/0.40_0.40_56.txt"},
   {"4/0.40_0.40_57.txt"},
   {"4/0.40_0.40_58.txt"},
   {"4/0.40_0.40_59.txt"},
   {"4/0.40_0.40_5.txt"},
   {"4/0.40_0.40_60.txt"},
   {"4/0.40_0.40_61.txt"},
   {"4/0.40_0.40_62.txt"},
   {"4/0.40_0.40_63.txt"},
   {"4/0.40_0.40_64.txt"},
   {"4/0.40_0.40_65.txt"},
   {"4/0.40_0.40_66.txt"},
   {"4/0.40_0.40_67.txt"},
   {"4/0.40_0.40_68.txt"},
   {"4/0.40_0.40_69.txt"},
   {"4/0.40_0.40_6.txt"},
   {"4/0.40_0.40_70.txt"},
   {"4/0.40_0.40_71.txt"},
   {"4/0.40_0.40_72.txt"},
   {"4/0.40_0.40_73.txt"},
   {"4/0.40_0.40_74.txt"},
   {"4/0.40_0.40_75.txt"},
   {"4/0.40_0.40_76.txt"},
   {"4/0.40_0.40_77.txt"},
   {"4/0.40_0.40_78.txt"},
   {"4/0.40_0.40_79.txt"},
   {"4/0.40_0.40_7.txt"},
   {"4/0.40_0.40_80.txt"},
   {"4/0.40_0.40_81.txt"},
   {"4/0.40_0.40_82.txt"},
   {"4/0.40_0.40_83.txt"},
   {"4/0.40_0.40_84.txt"},
   {"4/0.40_0.40_85.txt"},
   {"4/0.40_0.40_86.txt"},
   {"4/0.40_0.40_87.txt"},
   {"4/0.40_0.40_88.txt"},
   {"4/0.40_0.40_89.txt"},
   {"4/0.40_0.40_8.txt"},
   {"4/0.40_0.40_90.txt"},
   {"4/0.40_0.40_91.txt"},
   {"4/0.40_0.40_92.txt"},
   {"4/0.40_0.40_93.txt"},
   {"4/0.40_0.40_94.txt"},
   {"4/0.40_0.40_95.txt"},
   {"4/0.40_0.40_96.txt"},
   {"4/0.40_0.40_97.txt"},
   {"4/0.40_0.40_98.txt"},
   {"4/0.40_0.40_99.txt"},
   {"4/0.40_0.40_9.txt"}
};

std::vector<std::string> dt_synthetic_sparsity_5 = {
   {"5/0.50_0.48_100.txt"},
   {"5/0.50_0.48_66.txt"},
   {"5/0.50_0.48_67.txt"},
   {"5/0.50_0.48_68.txt"},
   {"5/0.50_0.48_69.txt"},
   {"5/0.50_0.48_70.txt"},
   {"5/0.50_0.48_71.txt"},
   {"5/0.50_0.48_72.txt"},
   {"5/0.50_0.48_73.txt"},
   {"5/0.50_0.48_74.txt"},
   {"5/0.50_0.48_75.txt"},
   {"5/0.50_0.48_76.txt"},
   {"5/0.50_0.48_77.txt"},
   {"5/0.50_0.48_78.txt"},
   {"5/0.50_0.48_79.txt"},
   {"5/0.50_0.48_80.txt"},
   {"5/0.50_0.48_81.txt"},
   {"5/0.50_0.48_82.txt"},
   {"5/0.50_0.48_83.txt"},
   {"5/0.50_0.48_84.txt"},
   {"5/0.50_0.48_85.txt"},
   {"5/0.50_0.48_86.txt"},
   {"5/0.50_0.48_87.txt"},
   {"5/0.50_0.48_88.txt"},
   {"5/0.50_0.48_89.txt"},
   {"5/0.50_0.48_90.txt"},
   {"5/0.50_0.48_91.txt"},
   {"5/0.50_0.48_92.txt"},
   {"5/0.50_0.48_93.txt"},
   {"5/0.50_0.48_94.txt"},
   {"5/0.50_0.48_95.txt"},
   {"5/0.50_0.48_96.txt"},
   {"5/0.50_0.48_97.txt"},
   {"5/0.50_0.48_98.txt"},
   {"5/0.50_0.48_99.txt"},
   {"5/0.50_0.49_33.txt"},
   {"5/0.50_0.49_34.txt"},
   {"5/0.50_0.49_35.txt"},
   {"5/0.50_0.49_36.txt"},
   {"5/0.50_0.49_37.txt"},
   {"5/0.50_0.49_38.txt"},
   {"5/0.50_0.49_39.txt"},
   {"5/0.50_0.49_40.txt"},
   {"5/0.50_0.49_41.txt"},
   {"5/0.50_0.49_42.txt"},
   {"5/0.50_0.49_43.txt"},
   {"5/0.50_0.49_44.txt"},
   {"5/0.50_0.49_45.txt"},
   {"5/0.50_0.49_46.txt"},
   {"5/0.50_0.49_47.txt"},
   {"5/0.50_0.49_48.txt"},
   {"5/0.50_0.49_49.txt"},
   {"5/0.50_0.49_50.txt"},
   {"5/0.50_0.49_51.txt"},
   {"5/0.50_0.49_52.txt"},
   {"5/0.50_0.49_53.txt"},
   {"5/0.50_0.49_54.txt"},
   {"5/0.50_0.49_55.txt"},
   {"5/0.50_0.49_56.txt"},
   {"5/0.50_0.49_57.txt"},
   {"5/0.50_0.49_58.txt"},
   {"5/0.50_0.49_59.txt"},
   {"5/0.50_0.49_60.txt"},
   {"5/0.50_0.49_61.txt"},
   {"5/0.50_0.49_62.txt"},
   {"5/0.50_0.49_63.txt"},
   {"5/0.50_0.49_64.txt"},
   {"5/0.50_0.49_65.txt"},
   {"5/0.50_0.50_10.txt"},
   {"5/0.50_0.50_11.txt"},
   {"5/0.50_0.50_12.txt"},
   {"5/0.50_0.50_13.txt"},
   {"5/0.50_0.50_14.txt"},
   {"5/0.50_0.50_15.txt"},
   {"5/0.50_0.50_16.txt"},
   {"5/0.50_0.50_17.txt"},
   {"5/0.50_0.50_18.txt"},
   {"5/0.50_0.50_19.txt"},
   {"5/0.50_0.50_1.txt"},
   {"5/0.50_0.50_20.txt"},
   {"5/0.50_0.50_21.txt"},
   {"5/0.50_0.50_22.txt"},
   {"5/0.50_0.50_23.txt"},
   {"5/0.50_0.50_24.txt"},
   {"5/0.50_0.50_25.txt"},
   {"5/0.50_0.50_26.txt"},
   {"5/0.50_0.50_27.txt"},
   {"5/0.50_0.50_28.txt"},
   {"5/0.50_0.50_29.txt"},
   {"5/0.50_0.50_2.txt"},
   {"5/0.50_0.50_30.txt"},
   {"5/0.50_0.50_31.txt"},
   {"5/0.50_0.50_32.txt"},
   {"5/0.50_0.50_3.txt"},
   {"5/0.50_0.50_4.txt"},
   {"5/0.50_0.50_5.txt"},
   {"5/0.50_0.50_6.txt"},
   {"5/0.50_0.50_7.txt"},
   {"5/0.50_0.50_8.txt"},
   {"5/0.50_0.50_9.txt"}
};

std::vector<std::string> dt_synthetic_sparsity_6 = {
   {"6/0.60_0.57_100.txt"},
   {"6/0.60_0.57_88.txt"},
   {"6/0.60_0.57_89.txt"},
   {"6/0.60_0.57_90.txt"},
   {"6/0.60_0.57_91.txt"},
   {"6/0.60_0.57_92.txt"},
   {"6/0.60_0.57_93.txt"},
   {"6/0.60_0.57_94.txt"},
   {"6/0.60_0.57_95.txt"},
   {"6/0.60_0.57_96.txt"},
   {"6/0.60_0.57_97.txt"},
   {"6/0.60_0.57_98.txt"},
   {"6/0.60_0.57_99.txt"},
   {"6/0.60_0.58_19.txt"},
   {"6/0.60_0.58_20.txt"},
   {"6/0.60_0.58_21.txt"},
   {"6/0.60_0.58_22.txt"},
   {"6/0.60_0.58_23.txt"},
   {"6/0.60_0.58_24.txt"},
   {"6/0.60_0.58_25.txt"},
   {"6/0.60_0.58_26.txt"},
   {"6/0.60_0.58_27.txt"},
   {"6/0.60_0.58_28.txt"},
   {"6/0.60_0.58_29.txt"},
   {"6/0.60_0.58_30.txt"},
   {"6/0.60_0.58_31.txt"},
   {"6/0.60_0.58_32.txt"},
   {"6/0.60_0.58_33.txt"},
   {"6/0.60_0.58_34.txt"},
   {"6/0.60_0.58_35.txt"},
   {"6/0.60_0.58_36.txt"},
   {"6/0.60_0.58_37.txt"},
   {"6/0.60_0.58_38.txt"},
   {"6/0.60_0.58_39.txt"},
   {"6/0.60_0.58_40.txt"},
   {"6/0.60_0.58_41.txt"},
   {"6/0.60_0.58_42.txt"},
   {"6/0.60_0.58_43.txt"},
   {"6/0.60_0.58_44.txt"},
   {"6/0.60_0.58_45.txt"},
   {"6/0.60_0.58_46.txt"},
   {"6/0.60_0.58_47.txt"},
   {"6/0.60_0.58_48.txt"},
   {"6/0.60_0.58_49.txt"},
   {"6/0.60_0.58_50.txt"},
   {"6/0.60_0.58_51.txt"},
   {"6/0.60_0.58_52.txt"},
   {"6/0.60_0.58_53.txt"},
   {"6/0.60_0.58_54.txt"},
   {"6/0.60_0.58_55.txt"},
   {"6/0.60_0.58_56.txt"},
   {"6/0.60_0.58_57.txt"},
   {"6/0.60_0.58_58.txt"},
   {"6/0.60_0.58_59.txt"},
   {"6/0.60_0.58_60.txt"},
   {"6/0.60_0.58_61.txt"},
   {"6/0.60_0.58_62.txt"},
   {"6/0.60_0.58_63.txt"},
   {"6/0.60_0.58_64.txt"},
   {"6/0.60_0.58_65.txt"},
   {"6/0.60_0.58_66.txt"},
   {"6/0.60_0.58_67.txt"},
   {"6/0.60_0.58_68.txt"},
   {"6/0.60_0.58_69.txt"},
   {"6/0.60_0.58_70.txt"},
   {"6/0.60_0.58_71.txt"},
   {"6/0.60_0.58_72.txt"},
   {"6/0.60_0.58_73.txt"},
   {"6/0.60_0.58_74.txt"},
   {"6/0.60_0.58_75.txt"},
   {"6/0.60_0.58_76.txt"},
   {"6/0.60_0.58_77.txt"},
   {"6/0.60_0.58_78.txt"},
   {"6/0.60_0.58_79.txt"},
   {"6/0.60_0.58_80.txt"},
   {"6/0.60_0.58_81.txt"},
   {"6/0.60_0.58_82.txt"},
   {"6/0.60_0.58_83.txt"},
   {"6/0.60_0.58_84.txt"},
   {"6/0.60_0.58_85.txt"},
   {"6/0.60_0.58_86.txt"},
   {"6/0.60_0.58_87.txt"},
   {"6/0.60_0.59_10.txt"},
   {"6/0.60_0.59_11.txt"},
   {"6/0.60_0.59_12.txt"},
   {"6/0.60_0.59_13.txt"},
   {"6/0.60_0.59_14.txt"},
   {"6/0.60_0.59_15.txt"},
   {"6/0.60_0.59_16.txt"},
   {"6/0.60_0.59_17.txt"},
   {"6/0.60_0.59_18.txt"},
   {"6/0.60_0.59_6.txt"},
   {"6/0.60_0.59_7.txt"},
   {"6/0.60_0.59_8.txt"},
   {"6/0.60_0.59_9.txt"},
   {"6/0.60_0.60_1.txt"},
   {"6/0.60_0.60_2.txt"},
   {"6/0.60_0.60_3.txt"},
   {"6/0.60_0.60_4.txt"},
   {"6/0.60_0.60_5.txt"}
};

std::vector<std::string> dt_synthetic_sparsity_7 = {
   {"7/0.70_0.67_100.txt"},
   {"7/0.70_0.67_26.txt"},
   {"7/0.70_0.67_27.txt"},
   {"7/0.70_0.67_28.txt"},
   {"7/0.70_0.67_29.txt"},
   {"7/0.70_0.67_30.txt"},
   {"7/0.70_0.67_31.txt"},
   {"7/0.70_0.67_32.txt"},
   {"7/0.70_0.67_33.txt"},
   {"7/0.70_0.67_34.txt"},
   {"7/0.70_0.67_35.txt"},
   {"7/0.70_0.67_36.txt"},
   {"7/0.70_0.67_37.txt"},
   {"7/0.70_0.67_38.txt"},
   {"7/0.70_0.67_39.txt"},
   {"7/0.70_0.67_40.txt"},
   {"7/0.70_0.67_41.txt"},
   {"7/0.70_0.67_42.txt"},
   {"7/0.70_0.67_43.txt"},
   {"7/0.70_0.67_44.txt"},
   {"7/0.70_0.67_45.txt"},
   {"7/0.70_0.67_46.txt"},
   {"7/0.70_0.67_47.txt"},
   {"7/0.70_0.67_48.txt"},
   {"7/0.70_0.67_49.txt"},
   {"7/0.70_0.67_50.txt"},
   {"7/0.70_0.67_51.txt"},
   {"7/0.70_0.67_52.txt"},
   {"7/0.70_0.67_53.txt"},
   {"7/0.70_0.67_54.txt"},
   {"7/0.70_0.67_55.txt"},
   {"7/0.70_0.67_56.txt"},
   {"7/0.70_0.67_57.txt"},
   {"7/0.70_0.67_58.txt"},
   {"7/0.70_0.67_59.txt"},
   {"7/0.70_0.67_60.txt"},
   {"7/0.70_0.67_61.txt"},
   {"7/0.70_0.67_62.txt"},
   {"7/0.70_0.67_63.txt"},
   {"7/0.70_0.67_64.txt"},
   {"7/0.70_0.67_65.txt"},
   {"7/0.70_0.67_66.txt"},
   {"7/0.70_0.67_67.txt"},
   {"7/0.70_0.67_68.txt"},
   {"7/0.70_0.67_69.txt"},
   {"7/0.70_0.67_70.txt"},
   {"7/0.70_0.67_71.txt"},
   {"7/0.70_0.67_72.txt"},
   {"7/0.70_0.67_73.txt"},
   {"7/0.70_0.67_74.txt"},
   {"7/0.70_0.67_75.txt"},
   {"7/0.70_0.67_76.txt"},
   {"7/0.70_0.67_77.txt"},
   {"7/0.70_0.67_78.txt"},
   {"7/0.70_0.67_79.txt"},
   {"7/0.70_0.67_80.txt"},
   {"7/0.70_0.67_81.txt"},
   {"7/0.70_0.67_82.txt"},
   {"7/0.70_0.67_83.txt"},
   {"7/0.70_0.67_84.txt"},
   {"7/0.70_0.67_85.txt"},
   {"7/0.70_0.67_86.txt"},
   {"7/0.70_0.67_87.txt"},
   {"7/0.70_0.67_88.txt"},
   {"7/0.70_0.67_89.txt"},
   {"7/0.70_0.67_90.txt"},
   {"7/0.70_0.67_91.txt"},
   {"7/0.70_0.67_92.txt"},
   {"7/0.70_0.67_93.txt"},
   {"7/0.70_0.67_94.txt"},
   {"7/0.70_0.67_95.txt"},
   {"7/0.70_0.67_96.txt"},
   {"7/0.70_0.67_97.txt"},
   {"7/0.70_0.67_98.txt"},
   {"7/0.70_0.67_99.txt"},
   {"7/0.70_0.68_10.txt"},
   {"7/0.70_0.68_11.txt"},
   {"7/0.70_0.68_12.txt"},
   {"7/0.70_0.68_13.txt"},
   {"7/0.70_0.68_14.txt"},
   {"7/0.70_0.68_15.txt"},
   {"7/0.70_0.68_16.txt"},
   {"7/0.70_0.68_17.txt"},
   {"7/0.70_0.68_18.txt"},
   {"7/0.70_0.68_19.txt"},
   {"7/0.70_0.68_20.txt"},
   {"7/0.70_0.68_21.txt"},
   {"7/0.70_0.68_22.txt"},
   {"7/0.70_0.68_23.txt"},
   {"7/0.70_0.68_24.txt"},
   {"7/0.70_0.68_25.txt"},
   {"7/0.70_0.68_3.txt"},
   {"7/0.70_0.68_4.txt"},
   {"7/0.70_0.68_5.txt"},
   {"7/0.70_0.68_6.txt"},
   {"7/0.70_0.68_7.txt"},
   {"7/0.70_0.68_8.txt"},
   {"7/0.70_0.68_9.txt"},
   {"7/0.70_0.69_1.txt"},
   {"7/0.70_0.69_2.txt"}
};   

std::vector<std::string> dt_synthetic_sparsity_8 = {
   {"8/0.80_0.76_100.txt"},
   {"8/0.80_0.76_51.txt"},
   {"8/0.80_0.76_52.txt"},
   {"8/0.80_0.76_53.txt"},
   {"8/0.80_0.76_54.txt"},
   {"8/0.80_0.76_55.txt"},
   {"8/0.80_0.76_56.txt"},
   {"8/0.80_0.76_57.txt"},
   {"8/0.80_0.76_58.txt"},
   {"8/0.80_0.76_59.txt"},
   {"8/0.80_0.76_60.txt"},
   {"8/0.80_0.76_61.txt"},
   {"8/0.80_0.76_62.txt"},
   {"8/0.80_0.76_63.txt"},
   {"8/0.80_0.76_64.txt"},
   {"8/0.80_0.76_65.txt"},
   {"8/0.80_0.76_66.txt"},
   {"8/0.80_0.76_67.txt"},
   {"8/0.80_0.76_68.txt"},
   {"8/0.80_0.76_69.txt"},
   {"8/0.80_0.76_70.txt"},
   {"8/0.80_0.76_71.txt"},
   {"8/0.80_0.76_72.txt"},
   {"8/0.80_0.76_73.txt"},
   {"8/0.80_0.76_74.txt"},
   {"8/0.80_0.76_75.txt"},
   {"8/0.80_0.76_76.txt"},
   {"8/0.80_0.76_77.txt"},
   {"8/0.80_0.76_78.txt"},
   {"8/0.80_0.76_79.txt"},
   {"8/0.80_0.76_80.txt"},
   {"8/0.80_0.76_81.txt"},
   {"8/0.80_0.76_82.txt"},
   {"8/0.80_0.76_83.txt"},
   {"8/0.80_0.76_84.txt"},
   {"8/0.80_0.76_85.txt"},
   {"8/0.80_0.76_86.txt"},
   {"8/0.80_0.76_87.txt"},
   {"8/0.80_0.76_88.txt"},
   {"8/0.80_0.76_89.txt"},
   {"8/0.80_0.76_90.txt"},
   {"8/0.80_0.76_91.txt"},
   {"8/0.80_0.76_92.txt"},
   {"8/0.80_0.76_93.txt"},
   {"8/0.80_0.76_94.txt"},
   {"8/0.80_0.76_95.txt"},
   {"8/0.80_0.76_96.txt"},
   {"8/0.80_0.76_97.txt"},
   {"8/0.80_0.76_98.txt"},
   {"8/0.80_0.76_99.txt"},
   {"8/0.80_0.77_10.txt"},
   {"8/0.80_0.77_11.txt"},
   {"8/0.80_0.77_12.txt"},
   {"8/0.80_0.77_13.txt"},
   {"8/0.80_0.77_14.txt"},
   {"8/0.80_0.77_15.txt"},
   {"8/0.80_0.77_16.txt"},
   {"8/0.80_0.77_17.txt"},
   {"8/0.80_0.77_18.txt"},
   {"8/0.80_0.77_19.txt"},
   {"8/0.80_0.77_20.txt"},
   {"8/0.80_0.77_21.txt"},
   {"8/0.80_0.77_22.txt"},
   {"8/0.80_0.77_23.txt"},
   {"8/0.80_0.77_24.txt"},
   {"8/0.80_0.77_25.txt"},
   {"8/0.80_0.77_26.txt"},
   {"8/0.80_0.77_27.txt"},
   {"8/0.80_0.77_28.txt"},
   {"8/0.80_0.77_29.txt"},
   {"8/0.80_0.77_30.txt"},
   {"8/0.80_0.77_31.txt"},
   {"8/0.80_0.77_32.txt"},
   {"8/0.80_0.77_33.txt"},
   {"8/0.80_0.77_34.txt"},
   {"8/0.80_0.77_35.txt"},
   {"8/0.80_0.77_36.txt"},
   {"8/0.80_0.77_37.txt"},
   {"8/0.80_0.77_38.txt"},
   {"8/0.80_0.77_39.txt"},
   {"8/0.80_0.77_40.txt"},
   {"8/0.80_0.77_41.txt"},
   {"8/0.80_0.77_42.txt"},
   {"8/0.80_0.77_43.txt"},
   {"8/0.80_0.77_44.txt"},
   {"8/0.80_0.77_45.txt"},
   {"8/0.80_0.77_46.txt"},
   {"8/0.80_0.77_47.txt"},
   {"8/0.80_0.77_48.txt"},
   {"8/0.80_0.77_49.txt"},
   {"8/0.80_0.77_50.txt"},
   {"8/0.80_0.77_5.txt"},
   {"8/0.80_0.77_6.txt"},
   {"8/0.80_0.77_7.txt"},
   {"8/0.80_0.77_8.txt"},
   {"8/0.80_0.77_9.txt"},
   {"8/0.80_0.78_2.txt"},
   {"8/0.80_0.78_3.txt"},
   {"8/0.80_0.78_4.txt"},
   {"8/0.80_0.79_1.txt"}
};

std::vector<std::string> dt_synthetic_sparsity_9 = {
   {"9/0.90_0.85_100.txt"},
   {"9/0.90_0.85_42.txt"},
   {"9/0.90_0.85_43.txt"},
   {"9/0.90_0.85_44.txt"},
   {"9/0.90_0.85_45.txt"},
   {"9/0.90_0.85_46.txt"},
   {"9/0.90_0.85_47.txt"},
   {"9/0.90_0.85_48.txt"},
   {"9/0.90_0.85_49.txt"},
   {"9/0.90_0.85_50.txt"},
   {"9/0.90_0.85_51.txt"},
   {"9/0.90_0.85_52.txt"},
   {"9/0.90_0.85_53.txt"},
   {"9/0.90_0.85_54.txt"},
   {"9/0.90_0.85_55.txt"},
   {"9/0.90_0.85_56.txt"},
   {"9/0.90_0.85_57.txt"},
   {"9/0.90_0.85_58.txt"},
   {"9/0.90_0.85_59.txt"},
   {"9/0.90_0.85_60.txt"},
   {"9/0.90_0.85_61.txt"},
   {"9/0.90_0.85_62.txt"},
   {"9/0.90_0.85_63.txt"},
   {"9/0.90_0.85_64.txt"},
   {"9/0.90_0.85_65.txt"},
   {"9/0.90_0.85_66.txt"},
   {"9/0.90_0.85_67.txt"},
   {"9/0.90_0.85_68.txt"},
   {"9/0.90_0.85_69.txt"},
   {"9/0.90_0.85_70.txt"},
   {"9/0.90_0.85_71.txt"},
   {"9/0.90_0.85_72.txt"},
   {"9/0.90_0.85_73.txt"},
   {"9/0.90_0.85_74.txt"},
   {"9/0.90_0.85_75.txt"},
   {"9/0.90_0.85_76.txt"},
   {"9/0.90_0.85_77.txt"},
   {"9/0.90_0.85_78.txt"},
   {"9/0.90_0.85_79.txt"},
   {"9/0.90_0.85_80.txt"},
   {"9/0.90_0.85_81.txt"},
   {"9/0.90_0.85_82.txt"},
   {"9/0.90_0.85_83.txt"},
   {"9/0.90_0.85_84.txt"},
   {"9/0.90_0.85_85.txt"},
   {"9/0.90_0.85_86.txt"},
   {"9/0.90_0.85_87.txt"},
   {"9/0.90_0.85_88.txt"},
   {"9/0.90_0.85_89.txt"},
   {"9/0.90_0.85_90.txt"},
   {"9/0.90_0.85_91.txt"},
   {"9/0.90_0.85_92.txt"},
   {"9/0.90_0.85_93.txt"},
   {"9/0.90_0.85_94.txt"},
   {"9/0.90_0.85_95.txt"},
   {"9/0.90_0.85_96.txt"},
   {"9/0.90_0.85_97.txt"},
   {"9/0.90_0.85_98.txt"},
   {"9/0.90_0.85_99.txt"},
   {"9/0.90_0.86_10.txt"},
   {"9/0.90_0.86_11.txt"},
   {"9/0.90_0.86_12.txt"},
   {"9/0.90_0.86_13.txt"},
   {"9/0.90_0.86_14.txt"},
   {"9/0.90_0.86_15.txt"},
   {"9/0.90_0.86_16.txt"},
   {"9/0.90_0.86_17.txt"},
   {"9/0.90_0.86_18.txt"},
   {"9/0.90_0.86_19.txt"},
   {"9/0.90_0.86_20.txt"},
   {"9/0.90_0.86_21.txt"},
   {"9/0.90_0.86_22.txt"},
   {"9/0.90_0.86_23.txt"},
   {"9/0.90_0.86_24.txt"},
   {"9/0.90_0.86_25.txt"},
   {"9/0.90_0.86_26.txt"},
   {"9/0.90_0.86_27.txt"},
   {"9/0.90_0.86_28.txt"},
   {"9/0.90_0.86_29.txt"},
   {"9/0.90_0.86_30.txt"},
   {"9/0.90_0.86_31.txt"},
   {"9/0.90_0.86_32.txt"},
   {"9/0.90_0.86_33.txt"},
   {"9/0.90_0.86_34.txt"},
   {"9/0.90_0.86_35.txt"},
   {"9/0.90_0.86_36.txt"},
   {"9/0.90_0.86_37.txt"},
   {"9/0.90_0.86_38.txt"},
   {"9/0.90_0.86_39.txt"},
   {"9/0.90_0.86_40.txt"},
   {"9/0.90_0.86_41.txt"},
   {"9/0.90_0.86_6.txt"},
   {"9/0.90_0.86_7.txt"},
   {"9/0.90_0.86_8.txt"},
   {"9/0.90_0.86_9.txt"},
   {"9/0.90_0.87_1.txt"},
   {"9/0.90_0.87_2.txt"},
   {"9/0.90_0.87_3.txt"},
   {"9/0.90_0.87_4.txt"},
   {"9/0.90_0.87_5.txt"}
};   

std::vector<std::string> sheep_logan = {
   {"2/Logan_64_2.txt"},
   {"2/Logan_256_2.txt"},
   {"4/Logan_64_4.txt"},
   {"4/Logan_256_4.txt"},
   {"6/Logan_64_6.txt"},
   {"6/Logan_256_6.txt"}
};

int main()
{
   // emulate command line options
   std::vector<std::string> options = {
      {"--maxIter"}, {"1000"},
      {"--timeout"}, {"36000"}, // one hour
      {"--minDualImprovement"}, {"0.00001"},
      {"--minDualImprovementInterval"}, {"50"},
      {"--lowerBoundComputationInterval"}, {"10"},
      {"--primalComputationInterval"}, {"100000"},
      //{"--overwriteDbRecord"}, // do zrobienia: possibly deactivate this. Then we do not overwrite
      //{"--tighten"},
      //{"--tightenIteration"}, {"500"},
      //{"--tightenInterval"}, {"20"},
      //{"--tightenConstraintsMax"}, {"50"},
      {"--LpInterval"}, {"100"},
      {"--LpTimelimit"}, {"36000"},
      {"--LpSolverThreads"}, {"1"},
      {"--LpRoundValue"}, {"1"},
      {"--databaseFile"}, {"discrete_tomography.db"}
   };

   std::vector<std::string> LP_only_options = {
      {"--maxIter"}, {"1"},
      {"--timeout"}, {"3600"}, // one hour
      {"--primalComputationInterval"}, {"100000"},
      //{"--overwriteDbRecord"}, // do zrobienia: possibly deactivate this. Then we do not overwrite
      //{"--tighten"},
      //{"--tightenIteration"}, {"500"},
      //{"--tightenInterval"}, {"20"},
      //{"--tightenConstraintsMax"}, {"50"},
      {"--LpInterval"}, {"50"},
      {"--LpTimelimit"}, {"3600"},
      {"--LpSolverThreads"}, {"1"},
      {"--databaseFile"}, {"discrete_tomography.db"}
   };


   using VisitorType = SqliteVisitor<StandardTighteningVisitor>;


   { // for overview
      std::string prefix = "discrete_tomography_datasets/discrete_tomography_synthetic/mp/"; 
         //RunSolver<FMC_DT_COMBINED,VisitorSolver<LpSolver<Solver<FMC_DT_COMBINED>,LpInterfaceGurobi>,VisitorType>>(DiscreteTomographyTextInput::ParseProblem<FMC_DT_COMBINED>,{{prefix + "2/" + dt_synthetic_sparsity_1[0]}} ,options,"p=2,s=1", "MP");
         //RunSolver<FMC_DT_COMBINED,VisitorSolver<LpSolver<Solver<FMC_DT_COMBINED>,LpInterfaceGurobi>,VisitorType>>(DiscreteTomographyTextInput::ParseProblem<FMC_DT_COMBINED>,{{prefix + "4/" + dt_synthetic_sparsity_1[0]}} ,options,"p=4, s=1", "MP");
         RunSolver<FMC_DT_COMBINED,VisitorSolver<LpSolver<Solver<FMC_DT_COMBINED>,LpInterfaceGurobi>,VisitorType>>(DiscreteTomographyTextInput::ParseProblem<FMC_DT_COMBINED>,{{prefix + sheep_logan[0]}} ,options,"sheep logan, p=2", "MP");

         //RunSolver<FMC_DT,VisitorSolver<LpSolver<Solver<FMC_DT_COMBINED>,LpInterfaceGurobi>,VisitorType>>(DiscreteTomographyTextInput::ParseProblem<FMC_DT_COMBINED>,{{prefix + "2/" + dt_synthetic_sparsity_1[0]}} ,LP_only_options,"p=2,s=1", "LP tight");
         //RunSolver<FMC_DT,VisitorSolver<LpSolver<Solver<FMC_DT_COMBINED>,LpInterfaceGurobi>,VisitorType>>(DiscreteTomographyTextInput::ParseProblem<FMC_DT_COMBINED>,{{prefix + "4/" + dt_synthetic_sparsity_1[0]}} ,LP_only_options,"p=4, s=1", "LP tight");
         //RunSolver<FMC_DT,VisitorSolver<LpSolver<Solver<FMC_DT_COMBINED>,LpInterfaceGurobi>,VisitorType>>(DiscreteTomographyTextInput::ParseProblem<FMC_DT_COMBINED>,{{prefix + "4/" + dt_synthetic_sparsity_1[0]}} ,LP_only_options,"sheep logan, p=2", "LP tight");

         //RunSolver<FMC_DT_NAIVE,VisitorSolver<LpSolver<Solver<FMC_DT_NAIVE>,LpInterfaceGurobi>,VisitorType>>(DiscreteTomographyTextInput::ParseProblem<FMC_DT_NAIVE>,{{prefix + "2/" + dt_synthetic_sparsity_1[0]}} ,LP_only_options,"p=2,s=1", "LP standard");
         //RunSolver<FMC_DT_NAIVE,VisitorSolver<LpSolver<Solver<FMC_DT_NAIVE>,LpInterfaceGurobi>,VisitorType>>(DiscreteTomographyTextInput::ParseProblem<FMC_DT_NAIVE>,{{prefix + "4/" + dt_synthetic_sparsity_1[0]}} ,LP_only_options,"p=4, s=1", "LP standard");
         RunSolver<FMC_DT_NAIVE,VisitorSolver<LpSolver<Solver<FMC_DT_NAIVE>,LpInterfaceGurobi>,VisitorType>>(DiscreteTomographyTextInput::ParseProblem<FMC_DT_NAIVE>,{{prefix + sheep_logan[0]}} ,LP_only_options,"sheep logan, p=2", "LP standard");

   }
   return 1;

   // run synthetic problems on all projection and sparsity levels 
   std::vector<std::string> projections = {{"2"},{"4"},{"6"}};
   std::vector<std::vector<std::string>> sparsities = {
      dt_synthetic_sparsity_1, 
      dt_synthetic_sparsity_2, 
      dt_synthetic_sparsity_3, 
      dt_synthetic_sparsity_4, 
      dt_synthetic_sparsity_5, 
      dt_synthetic_sparsity_6, 
      dt_synthetic_sparsity_7, 
      dt_synthetic_sparsity_8, 
      dt_synthetic_sparsity_9
   }; 
   int sparsity = 1;
   for(auto p : projections) {
      for(auto s : sparsities) {
         for(auto& i : s) {
            i = "discrete_tomography_datasets/discrete_tomography_synthetic/mp/" + p + "/" + i;
         }
         RunSolver<FMC_DT,VisitorSolver<LpSolver<Solver<FMC_DT>,LpInterfaceGurobi>,VisitorType>>(DiscreteTomographyTextInput::ParseProblem<FMC_DT>,s,options,p + " projections, sparsity " + std::to_string(sparsity) ,"MP");
      }
      sparsity++;
   }

   // run sheep logan 
   for(auto& i : sheep_logan) {
      i = "discrete_tomography_datasets/discrete_tomography_synthetic/mp/" + i;
   }
   RunSolver<FMC_DT,VisitorSolver<Solver<FMC_DT>,VisitorType>>(DiscreteTomographyTextInput::ParseProblem<FMC_DT>,sheep_logan,options,"sheep logan","MP");

   return 0;
}

