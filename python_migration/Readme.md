# Migration Process

This folder contains the input and output for the python 2 to 3 migration. Using 2to3.py too.

Most of the code taken from nupic's github repository. One exception is the nupic/bindings folder. This has been taken from sitepackage (e.g. C:\Python27\Lib\site-packages\nupic\bindings).
All *.pyd and *.pyc files been removed manually. As well as, Swig generated files, algorithms.py, engine_internal.py, and  math.py.


python c:\Python36\Tools\scripts\2to3.py --output-dir D:\nupic\python_migration\output -W -n D:\nupic\python_migration\input > D:\nupic\python_migration\2to3_output.txt
python c:\Python36\Tools\scripts\2to3.py --output-dir D:\nupic\python_migration\output\bindings -W -n D:\nupic\python_migration\input\bindings > D:\nupic\python_migration\2to3_output__bindings.txt


# Console output

C:\Users\chhenning>python c:\Python36\Tools\scripts\2to3.py --output-dir D:\nupic\python_migration\output -W -n D:\nupic\python_migration\input > D:\nupic\python_migration\2to3_output.txt
WARNING: --write-unchanged-files/-W implies -w.
lib2to3.main: Output in 'D:\\nupic\\python_migration\\output' will mirror the input directory 'D:\\nupic\\python_migration\\input' layout.
RefactoringTool: Skipping optional fixer: buffer
RefactoringTool: Skipping optional fixer: idioms
RefactoringTool: Skipping optional fixer: set_literal
RefactoringTool: Skipping optional fixer: ws_comma
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\bindings\sparse_matrix_how_to.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\bindings\sparse_matrix_how_to.py to D:\nupic\python_migration\output\examples\bindings\sparse_matrix_how_to.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\bindings\svm_how_to.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\bindings\svm_how_to.py to D:\nupic\python_migration\output\examples\bindings\svm_how_to.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\network\core_encoders_demo.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\network\core_encoders_demo.py to D:\nupic\python_migration\output\examples\network\core_encoders_demo.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\network\custom_region_demo.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\network\custom_region_demo.py to D:\nupic\python_migration\output\examples\network\custom_region_demo.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\network\hierarchy_network_demo.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\network\hierarchy_network_demo.py to D:\nupic\python_migration\output\examples\network\hierarchy_network_demo.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\network\network_api_demo.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\network\network_api_demo.py to D:\nupic\python_migration\output\examples\network\network_api_demo.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\network\temporal_anomaly_network_demo.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\network\temporal_anomaly_network_demo.py to D:\nupic\python_migration\output\examples\network\temporal_anomaly_network_demo.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\network\custom_region\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\network\custom_region\__init__.py to D:\nupic\python_migration\output\examples\network\custom_region\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\network\custom_region\identity_region.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\network\custom_region\identity_region.py to D:\nupic\python_migration\output\examples\network\custom_region\identity_region.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\clients\cpu\cpu.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\clients\cpu\cpu.py to D:\nupic\python_migration\output\examples\opf\clients\cpu\cpu.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\clients\cpu\model_params.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\clients\cpu\model_params.py to D:\nupic\python_migration\output\examples\opf\clients\cpu\model_params.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\clients\hotgym\anomaly\hotgym_anomaly.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\clients\hotgym\anomaly\hotgym_anomaly.py to D:\nupic\python_migration\output\examples\opf\clients\hotgym\anomaly\hotgym_anomaly.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\clients\hotgym\anomaly\model_params.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\clients\hotgym\anomaly\model_params.py to D:\nupic\python_migration\output\examples\opf\clients\hotgym\anomaly\model_params.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\clients\hotgym\anomaly\one_gym\nupic_anomaly_output.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\clients\hotgym\anomaly\one_gym\nupic_anomaly_output.py to D:\nupic\python_migration\output\examples\opf\clients\hotgym\anomaly\one_gym\nupic_anomaly_output.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\clients\hotgym\anomaly\one_gym\remove_tuesdays.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\clients\hotgym\anomaly\one_gym\remove_tuesdays.py to D:\nupic\python_migration\output\examples\opf\clients\hotgym\anomaly\one_gym\remove_tuesdays.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\clients\hotgym\anomaly\one_gym\run.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\clients\hotgym\anomaly\one_gym\run.py to D:\nupic\python_migration\output\examples\opf\clients\hotgym\anomaly\one_gym\run.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\clients\hotgym\anomaly\one_gym\model_params\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\clients\hotgym\anomaly\one_gym\model_params\__init__.py to D:\nupic\python_migration\output\examples\opf\clients\hotgym\anomaly\one_gym\model_params\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\clients\hotgym\anomaly\one_gym\model_params\rec_center_hourly_model_params.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\clients\hotgym\anomaly\one_gym\model_params\rec_center_hourly_model_params.py to D:\nupic\python_migration\output\examples\opf\clients\hotgym\anomaly\one_gym\model_params\rec_center_hourly_model_params.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\clients\hotgym\prediction\one_gym\cleanup.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\clients\hotgym\prediction\one_gym\cleanup.py to D:\nupic\python_migration\output\examples\opf\clients\hotgym\prediction\one_gym\cleanup.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\clients\hotgym\prediction\one_gym\nupic_output.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\clients\hotgym\prediction\one_gym\nupic_output.py to D:\nupic\python_migration\output\examples\opf\clients\hotgym\prediction\one_gym\nupic_output.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\clients\hotgym\prediction\one_gym\run.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\clients\hotgym\prediction\one_gym\run.py to D:\nupic\python_migration\output\examples\opf\clients\hotgym\prediction\one_gym\run.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\clients\hotgym\prediction\one_gym\swarm.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\clients\hotgym\prediction\one_gym\swarm.py to D:\nupic\python_migration\output\examples\opf\clients\hotgym\prediction\one_gym\swarm.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\clients\hotgym\prediction\one_gym\swarm_description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\clients\hotgym\prediction\one_gym\swarm_description.py to D:\nupic\python_migration\output\examples\opf\clients\hotgym\prediction\one_gym\swarm_description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\clients\hotgym\simple\hotgym.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\clients\hotgym\simple\hotgym.py to D:\nupic\python_migration\output\examples\opf\clients\hotgym\simple\hotgym.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\clients\hotgym\simple\model_params.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\clients\hotgym\simple\model_params.py to D:\nupic\python_migration\output\examples\opf\clients\hotgym\simple\model_params.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\clients\nyctaxi\model_params.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\clients\nyctaxi\model_params.py to D:\nupic\python_migration\output\examples\opf\clients\nyctaxi\model_params.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\clients\nyctaxi\nyctaxi_anomaly.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\clients\nyctaxi\nyctaxi_anomaly.py to D:\nupic\python_migration\output\examples\opf\clients\nyctaxi\nyctaxi_anomaly.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\10field_few2_skewed\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\10field_few2_skewed\description.py to D:\nupic\python_migration\output\examples\opf\experiments\anomaly\spatial\10field_few2_skewed\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\10field_few_skewed\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\10field_few_skewed\description.py to D:\nupic\python_migration\output\examples\opf\experiments\anomaly\spatial\10field_few_skewed\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\10field_many_skewed\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\10field_many_skewed\description.py to D:\nupic\python_migration\output\examples\opf\experiments\anomaly\spatial\10field_many_skewed\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\1field_few_balanced\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\1field_few_balanced\description.py to D:\nupic\python_migration\output\examples\opf\experiments\anomaly\spatial\1field_few_balanced\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\1field_few_skewed\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\1field_few_skewed\description.py to D:\nupic\python_migration\output\examples\opf\experiments\anomaly\spatial\1field_few_skewed\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\2field_few_6040\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\2field_few_6040\description.py to D:\nupic\python_migration\output\examples\opf\experiments\anomaly\spatial\2field_few_6040\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\2field_few_balanced\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\2field_few_balanced\description.py to D:\nupic\python_migration\output\examples\opf\experiments\anomaly\spatial\2field_few_balanced\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\2field_few_skewed\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\2field_few_skewed\description.py to D:\nupic\python_migration\output\examples\opf\experiments\anomaly\spatial\2field_few_skewed\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\2field_many_balanced\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\2field_many_balanced\description.py to D:\nupic\python_migration\output\examples\opf\experiments\anomaly\spatial\2field_many_balanced\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\2field_many_novelAtEnd\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\2field_many_novelAtEnd\description.py to D:\nupic\python_migration\output\examples\opf\experiments\anomaly\spatial\2field_many_novelAtEnd\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\2fields_many_skewed\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\2fields_many_skewed\description.py to D:\nupic\python_migration\output\examples\opf\experiments\anomaly\spatial\2fields_many_skewed\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\novel_combination\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\novel_combination\description.py to D:\nupic\python_migration\output\examples\opf\experiments\anomaly\spatial\novel_combination\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\simple\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\simple\description.py to D:\nupic\python_migration\output\examples\opf\experiments\anomaly\spatial\simple\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\anomaly\temporal\hotgym\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\anomaly\temporal\hotgym\description.py to D:\nupic\python_migration\output\examples\opf\experiments\anomaly\temporal\hotgym\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\anomaly\temporal\saw_200\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\anomaly\temporal\saw_200\description.py to D:\nupic\python_migration\output\examples\opf\experiments\anomaly\temporal\saw_200\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\anomaly\temporal\saw_big\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\anomaly\temporal\saw_big\description.py to D:\nupic\python_migration\output\examples\opf\experiments\anomaly\temporal\saw_big\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\anomaly\temporal\simple\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\anomaly\temporal\simple\description.py to D:\nupic\python_migration\output\examples\opf\experiments\anomaly\temporal\simple\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\classification\makeDatasets.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\classification\makeDatasets.py to D:\nupic\python_migration\output\examples\opf\experiments\classification\makeDatasets.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\classification\base_category\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\classification\base_category\description.py to D:\nupic\python_migration\output\examples\opf\experiments\classification\base_category\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\classification\base_scalar\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\classification\base_scalar\description.py to D:\nupic\python_migration\output\examples\opf\experiments\classification\base_scalar\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\classification\category_TM_0\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\classification\category_TM_0\description.py to D:\nupic\python_migration\output\examples\opf\experiments\classification\category_TM_0\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\classification\category_TM_1\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\classification\category_TM_1\description.py to D:\nupic\python_migration\output\examples\opf\experiments\classification\category_TM_1\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\classification\category_hub_TP_0\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\classification\category_hub_TP_0\description.py to D:\nupic\python_migration\output\examples\opf\experiments\classification\category_hub_TP_0\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\classification\scalar_TP_0\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\classification\scalar_TP_0\description.py to D:\nupic\python_migration\output\examples\opf\experiments\classification\scalar_TP_0\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\classification\scalar_TP_1\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\classification\scalar_TP_1\description.py to D:\nupic\python_migration\output\examples\opf\experiments\classification\scalar_TP_1\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\classification\scalar_encoder_0\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\classification\scalar_encoder_0\description.py to D:\nupic\python_migration\output\examples\opf\experiments\classification\scalar_encoder_0\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\missing_record\make_datasets.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\missing_record\make_datasets.py to D:\nupic\python_migration\output\examples\opf\experiments\missing_record\make_datasets.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\missing_record\base\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\missing_record\base\description.py to D:\nupic\python_migration\output\examples\opf\experiments\missing_record\base\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\missing_record\simple_0\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\missing_record\simple_0\description.py to D:\nupic\python_migration\output\examples\opf\experiments\missing_record\simple_0\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\multistep\make_datasets.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\make_datasets.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\make_datasets.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\multistep\base\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\base\description.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\base\description.py.
RefactoringTool: Can't parse D:\nupic\python_migration\input\examples\opf\experiments\multistep\base\permutations_simple_3.py: ParseError: bad input: type=22, value='=', context=(' ', (61, 15))
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\multistep\base\permutations_simple_3.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\base\permutations_simple_3.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\base\permutations_simple_3.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\multistep\first_order_0\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\first_order_0\description.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\first_order_0\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym\description.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\hotgym\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym\permutations.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym\permutations.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\hotgym\permutations.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym\permutations_sp.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym\permutations_sp.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\hotgym\permutations_sp.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_enc\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_enc\description.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\hotgym_best_enc\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_sp\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_sp\description.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\hotgym_best_sp\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_sp_16K\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_sp_16K\description.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\hotgym_best_sp_16K\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_sp_5step\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_sp_5step\description.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\hotgym_best_sp_5step\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_sp_5step_16K\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_sp_5step_16K\description.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\hotgym_best_sp_5step_16K\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_tp\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_tp\description.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\hotgym_best_tp\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_tp_16K\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_tp_16K\description.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\hotgym_best_tp_16K\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_tp_5step\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_tp_5step\description.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\hotgym_best_tp_5step\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_0\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_0\description.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\simple_0\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_0_f2\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_0_f2\description.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\simple_0_f2\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_1\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_1\description.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\simple_1\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_1_f2\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_1_f2\description.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\simple_1_f2\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_2\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_2\description.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\simple_2\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_3\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_3\description.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\simple_3\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_3_enc\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_3_enc\description.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\simple_3_enc\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_3_f2\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_3_f2\description.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\simple_3_f2\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_3_sp\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_3_sp\description.py to D:\nupic\python_migration\output\examples\opf\experiments\multistep\simple_3_sp\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\opfrunexperiment_test\checkpoints\base.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\opfrunexperiment_test\checkpoints\base.py to D:\nupic\python_migration\output\examples\opf\experiments\opfrunexperiment_test\checkpoints\base.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\opfrunexperiment_test\checkpoints\a\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\opfrunexperiment_test\checkpoints\a\description.py to D:\nupic\python_migration\output\examples\opf\experiments\opfrunexperiment_test\checkpoints\a\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\opfrunexperiment_test\checkpoints\a_plus_b\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\opfrunexperiment_test\checkpoints\a_plus_b\description.py to D:\nupic\python_migration\output\examples\opf\experiments\opfrunexperiment_test\checkpoints\a_plus_b\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\opfrunexperiment_test\checkpoints\b\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\opfrunexperiment_test\checkpoints\b\description.py to D:\nupic\python_migration\output\examples\opf\experiments\opfrunexperiment_test\checkpoints\b\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\opfrunexperiment_test\simpleOPF\hotgym\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\opfrunexperiment_test\simpleOPF\hotgym\description.py to D:\nupic\python_migration\output\examples\opf\experiments\opfrunexperiment_test\simpleOPF\hotgym\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\opfrunexperiment_test\simpleOPF\hotgym_1hr_agg\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\opfrunexperiment_test\simpleOPF\hotgym_1hr_agg\description.py to D:\nupic\python_migration\output\examples\opf\experiments\opfrunexperiment_test\simpleOPF\hotgym_1hr_agg\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\opfrunexperiment_test\simpleOPF\hotgym_no_agg\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\opfrunexperiment_test\simpleOPF\hotgym_no_agg\description.py to D:\nupic\python_migration\output\examples\opf\experiments\opfrunexperiment_test\simpleOPF\hotgym_no_agg\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\params\EnsembleOnline.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\params\EnsembleOnline.py to D:\nupic\python_migration\output\examples\opf\experiments\params\EnsembleOnline.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\params\test_all.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\params\test_all.py to D:\nupic\python_migration\output\examples\opf\experiments\params\test_all.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\make_datasets.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\make_datasets.py to D:\nupic\python_migration\output\examples\opf\experiments\spatial_classification\make_datasets.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\run_exp_generator.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\run_exp_generator.py to D:\nupic\python_migration\output\examples\opf\experiments\spatial_classification\run_exp_generator.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\auto_generated\searchDef.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\auto_generated\searchDef.py to D:\nupic\python_migration\output\examples\opf\experiments\spatial_classification\auto_generated\searchDef.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\base\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\base\description.py to D:\nupic\python_migration\output\examples\opf\experiments\spatial_classification\base\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\category_0\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\category_0\description.py to D:\nupic\python_migration\output\examples\opf\experiments\spatial_classification\category_0\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\category_1\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\category_1\description.py to D:\nupic\python_migration\output\examples\opf\experiments\spatial_classification\category_1\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\scalar_0\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\scalar_0\description.py to D:\nupic\python_migration\output\examples\opf\experiments\spatial_classification\scalar_0\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\scalar_1\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\scalar_1\description.py to D:\nupic\python_migration\output\examples\opf\experiments\spatial_classification\scalar_1\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\opf\experiments\template\base\descriptionTemplate.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\experiments\template\base\descriptionTemplate.py to D:\nupic\python_migration\output\examples\opf\experiments\template\base\descriptionTemplate.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\simple_server\demo.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\simple_server\demo.py to D:\nupic\python_migration\output\examples\opf\simple_server\demo.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\simple_server\model_params.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\simple_server\model_params.py to D:\nupic\python_migration\output\examples\opf\simple_server\model_params.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\tools\sp_plotter.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\tools\sp_plotter.py to D:\nupic\python_migration\output\examples\opf\tools\sp_plotter.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\tools\testDiagnostics.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\tools\testDiagnostics.py to D:\nupic\python_migration\output\examples\opf\tools\testDiagnostics.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\opf\tools\MirrorImageViz\mirrorImageViz.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\opf\tools\MirrorImageViz\mirrorImageViz.py to D:\nupic\python_migration\output\examples\opf\tools\MirrorImageViz\mirrorImageViz.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\prediction\category_prediction\clean.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\category_prediction\clean.py to D:\nupic\python_migration\output\examples\prediction\category_prediction\clean.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\prediction\category_prediction\run.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\category_prediction\run.py to D:\nupic\python_migration\output\examples\prediction\category_prediction\run.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\prediction\experiments\inspect_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\experiments\inspect_test.py to D:\nupic\python_migration\output\examples\prediction\experiments\inspect_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\1\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\1\description.py to D:\nupic\python_migration\output\examples\prediction\experiments\confidenceTest\1\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\2\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\2\description.py to D:\nupic\python_migration\output\examples\prediction\experiments\confidenceTest\2\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\3\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\3\description.py to D:\nupic\python_migration\output\examples\prediction\experiments\confidenceTest\3\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\base\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\base\description.py to D:\nupic\python_migration\output\examples\prediction\experiments\confidenceTest\base\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\base\permutations_firstOrder.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\base\permutations_firstOrder.py to D:\nupic\python_migration\output\examples\prediction\experiments\confidenceTest\base\permutations_firstOrder.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\base\permutations_quick.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\base\permutations_quick.py to D:\nupic\python_migration\output\examples\prediction\experiments\confidenceTest\base\permutations_quick.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\base\permutations_secondOrder0.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\base\permutations_secondOrder0.py to D:\nupic\python_migration\output\examples\prediction\experiments\confidenceTest\base\permutations_secondOrder0.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\firstOrder\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\firstOrder\description.py to D:\nupic\python_migration\output\examples\prediction\experiments\confidenceTest\firstOrder\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\secondOrder0\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\secondOrder0\description.py to D:\nupic\python_migration\output\examples\prediction\experiments\confidenceTest\secondOrder0\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\secondOrder1\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\secondOrder1\description.py to D:\nupic\python_migration\output\examples\prediction\experiments\confidenceTest\secondOrder1\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\secondOrder2\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\secondOrder2\description.py to D:\nupic\python_migration\output\examples\prediction\experiments\confidenceTest\secondOrder2\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\bSDRHighDC\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\bSDRHighDC\description.py to D:\nupic\python_migration\output\examples\prediction\experiments\dutyCycle\bSDRHighDC\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\bSDRSameDC\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\bSDRSameDC\description.py to D:\nupic\python_migration\output\examples\prediction\experiments\dutyCycle\bSDRSameDC\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\base\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\base\description.py to D:\nupic\python_migration\output\examples\prediction\experiments\dutyCycle\base\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\base\permutations.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\base\permutations.py to D:\nupic\python_migration\output\examples\prediction\experiments\dutyCycle\base\permutations.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\base\permutationsActiveCount.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\base\permutationsActiveCount.py to D:\nupic\python_migration\output\examples\prediction\experiments\dutyCycle\base\permutationsActiveCount.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\base\permutationsData.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\base\permutationsData.py to D:\nupic\python_migration\output\examples\prediction\experiments\dutyCycle\base\permutationsData.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\base\permutationsEncoder.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\base\permutationsEncoder.py to D:\nupic\python_migration\output\examples\prediction\experiments\dutyCycle\base\permutationsEncoder.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\problem\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\problem\description.py to D:\nupic\python_migration\output\examples\prediction\experiments\dutyCycle\problem\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\prediction\experiments\generated_data\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\prediction\experiments\generated_data\description.py to D:\nupic\python_migration\output\examples\prediction\experiments\generated_data\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\sp\hello_sp.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\sp\hello_sp.py to D:\nupic\python_migration\output\examples\sp\hello_sp.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\sp\sp_tutorial.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\sp\sp_tutorial.py to D:\nupic\python_migration\output\examples\sp\sp_tutorial.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\swarm\test_db.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\swarm\test_db.py to D:\nupic\python_migration\output\examples\swarm\test_db.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\tm\hello_tm.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\tm\hello_tm.py to D:\nupic\python_migration\output\examples\tm\hello_tm.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\tm\tm_constant_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\tm\tm_constant_test.py to D:\nupic\python_migration\output\examples\tm\tm_constant_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\tm\tm_high_order.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\tm\tm_high_order.py to D:\nupic\python_migration\output\examples\tm\tm_high_order.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\tm\tm_overlapping_sequences.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\tm\tm_overlapping_sequences.py to D:\nupic\python_migration\output\examples\tm\tm_overlapping_sequences.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\tm\tm_segment_learning.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\tm\tm_segment_learning.py to D:\nupic\python_migration\output\examples\tm\tm_segment_learning.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\examples\tm\tm_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\examples\tm\tm_test.py to D:\nupic\python_migration\output\examples\tm\tm_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\__init__.py to D:\nupic\python_migration\output\nupic\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\serializable.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\serializable.py to D:\nupic\python_migration\output\nupic\serializable.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\simple_server.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\simple_server.py to D:\nupic\python_migration\output\nupic\simple_server.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\utils.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\utils.py to D:\nupic\python_migration\output\nupic\utils.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\algorithms\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\__init__.py to D:\nupic\python_migration\output\nupic\algorithms\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\algorithms\anomaly.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\anomaly.py to D:\nupic\python_migration\output\nupic\algorithms\anomaly.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\algorithms\anomaly_likelihood.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\anomaly_likelihood.py to D:\nupic\python_migration\output\nupic\algorithms\anomaly_likelihood.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\algorithms\backtracking_tm.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\backtracking_tm.py to D:\nupic\python_migration\output\nupic\algorithms\backtracking_tm.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\algorithms\backtracking_tm_cpp.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\backtracking_tm_cpp.py to D:\nupic\python_migration\output\nupic\algorithms\backtracking_tm_cpp.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\algorithms\backtracking_tm_shim.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\backtracking_tm_shim.py to D:\nupic\python_migration\output\nupic\algorithms\backtracking_tm_shim.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\algorithms\connections.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\connections.py to D:\nupic\python_migration\output\nupic\algorithms\connections.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\algorithms\fdrutilities.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\fdrutilities.py to D:\nupic\python_migration\output\nupic\algorithms\fdrutilities.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\algorithms\knn_classifier.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\knn_classifier.py to D:\nupic\python_migration\output\nupic\algorithms\knn_classifier.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\algorithms\sdr_classifier.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\sdr_classifier.py to D:\nupic\python_migration\output\nupic\algorithms\sdr_classifier.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\algorithms\sdr_classifier_diff.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\sdr_classifier_diff.py to D:\nupic\python_migration\output\nupic\algorithms\sdr_classifier_diff.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\algorithms\sdr_classifier_factory.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\sdr_classifier_factory.py to D:\nupic\python_migration\output\nupic\algorithms\sdr_classifier_factory.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\algorithms\spatial_pooler.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\spatial_pooler.py to D:\nupic\python_migration\output\nupic\algorithms\spatial_pooler.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\algorithms\temporal_memory.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\temporal_memory.py to D:\nupic\python_migration\output\nupic\algorithms\temporal_memory.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\algorithms\temporal_memory_shim.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\temporal_memory_shim.py to D:\nupic\python_migration\output\nupic\algorithms\temporal_memory_shim.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\algorithms\utils.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\utils.py to D:\nupic\python_migration\output\nupic\algorithms\utils.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\algorithms\monitor_mixin\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\monitor_mixin\__init__.py to D:\nupic\python_migration\output\nupic\algorithms\monitor_mixin\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\algorithms\monitor_mixin\metric.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\monitor_mixin\metric.py to D:\nupic\python_migration\output\nupic\algorithms\monitor_mixin\metric.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\algorithms\monitor_mixin\monitor_mixin_base.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\monitor_mixin\monitor_mixin_base.py to D:\nupic\python_migration\output\nupic\algorithms\monitor_mixin\monitor_mixin_base.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\algorithms\monitor_mixin\plot.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\monitor_mixin\plot.py to D:\nupic\python_migration\output\nupic\algorithms\monitor_mixin\plot.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\algorithms\monitor_mixin\temporal_memory_monitor_mixin.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\monitor_mixin\temporal_memory_monitor_mixin.py to D:\nupic\python_migration\output\nupic\algorithms\monitor_mixin\temporal_memory_monitor_mixin.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\algorithms\monitor_mixin\trace.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\algorithms\monitor_mixin\trace.py to D:\nupic\python_migration\output\nupic\algorithms\monitor_mixin\trace.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\bindings\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\bindings\__init__.py to D:\nupic\python_migration\output\nupic\bindings\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\bindings\check.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\bindings\check.py to D:\nupic\python_migration\output\nupic\bindings\check.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\bindings\regions\PyRegion.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\bindings\regions\PyRegion.py to D:\nupic\python_migration\output\nupic\bindings\regions\PyRegion.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\bindings\regions\TestNode.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\bindings\regions\TestNode.py to D:\nupic\python_migration\output\nupic\bindings\regions\TestNode.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\bindings\regions\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\bindings\regions\__init__.py to D:\nupic\python_migration\output\nupic\bindings\regions\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\data\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\__init__.py to D:\nupic\python_migration\output\nupic\data\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\data\aggregator.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\aggregator.py to D:\nupic\python_migration\output\nupic\data\aggregator.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\data\category_filter.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\category_filter.py to D:\nupic\python_migration\output\nupic\data\category_filter.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\data\dict_utils.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\dict_utils.py to D:\nupic\python_migration\output\nupic\data\dict_utils.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\data\field_meta.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\field_meta.py to D:\nupic\python_migration\output\nupic\data\field_meta.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\data\file_record_stream.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\file_record_stream.py to D:\nupic\python_migration\output\nupic\data\file_record_stream.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\data\filters.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\filters.py to D:\nupic\python_migration\output\nupic\data\filters.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\data\function_source.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\function_source.py to D:\nupic\python_migration\output\nupic\data\function_source.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\data\inference_shifter.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\inference_shifter.py to D:\nupic\python_migration\output\nupic\data\inference_shifter.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\data\json_helpers.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\json_helpers.py to D:\nupic\python_migration\output\nupic\data\json_helpers.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\data\record_stream.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\record_stream.py to D:\nupic\python_migration\output\nupic\data\record_stream.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\data\sorter.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\sorter.py to D:\nupic\python_migration\output\nupic\data\sorter.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\data\stats.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\stats.py to D:\nupic\python_migration\output\nupic\data\stats.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\data\stats_v2.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\stats_v2.py to D:\nupic\python_migration\output\nupic\data\stats_v2.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\data\stream_reader.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\stream_reader.py to D:\nupic\python_migration\output\nupic\data\stream_reader.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\data\utils.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\utils.py to D:\nupic\python_migration\output\nupic\data\utils.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\data\generators\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\generators\__init__.py to D:\nupic\python_migration\output\nupic\data\generators\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\data\generators\anomalyzer.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\generators\anomalyzer.py to D:\nupic\python_migration\output\nupic\data\generators\anomalyzer.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\data\generators\data_generator.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\generators\data_generator.py to D:\nupic\python_migration\output\nupic\data\generators\data_generator.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\data\generators\distributions.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\generators\distributions.py to D:\nupic\python_migration\output\nupic\data\generators\distributions.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\data\generators\pattern_machine.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\generators\pattern_machine.py to D:\nupic\python_migration\output\nupic\data\generators\pattern_machine.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\data\generators\sequence_machine.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\data\generators\sequence_machine.py to D:\nupic\python_migration\output\nupic\data\generators\sequence_machine.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\database\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\database\__init__.py to D:\nupic\python_migration\output\nupic\database\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\database\client_jobs_dao.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\database\client_jobs_dao.py to D:\nupic\python_migration\output\nupic\database\client_jobs_dao.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\database\connection.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\database\connection.py to D:\nupic\python_migration\output\nupic\database\connection.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\datafiles\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\datafiles\__init__.py to D:\nupic\python_migration\output\nupic\datafiles\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\datafiles\extra\firstOrder\raw\makeDataset.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\datafiles\extra\firstOrder\raw\makeDataset.py to D:\nupic\python_migration\output\nupic\datafiles\extra\firstOrder\raw\makeDataset.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\datafiles\extra\generated\GenerateSampleData.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\datafiles\extra\generated\GenerateSampleData.py to D:\nupic\python_migration\output\nupic\datafiles\extra\generated\GenerateSampleData.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\datafiles\extra\gym\raw\makeDataset.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\datafiles\extra\gym\raw\makeDataset.py to D:\nupic\python_migration\output\nupic\datafiles\extra\gym\raw\makeDataset.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\datafiles\extra\hotgym\raw\makeDataset.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\datafiles\extra\hotgym\raw\makeDataset.py to D:\nupic\python_migration\output\nupic\datafiles\extra\hotgym\raw\makeDataset.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\datafiles\extra\regression\makeDataset.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\datafiles\extra\regression\makeDataset.py to D:\nupic\python_migration\output\nupic\datafiles\extra\regression\makeDataset.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\datafiles\extra\secondOrder\makeDataset.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\datafiles\extra\secondOrder\makeDataset.py to D:\nupic\python_migration\output\nupic\datafiles\extra\secondOrder\makeDataset.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\encoders\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\encoders\__init__.py to D:\nupic\python_migration\output\nupic\encoders\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\encoders\adaptive_scalar.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\encoders\adaptive_scalar.py to D:\nupic\python_migration\output\nupic\encoders\adaptive_scalar.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\encoders\base.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\encoders\base.py to D:\nupic\python_migration\output\nupic\encoders\base.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\encoders\category.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\encoders\category.py to D:\nupic\python_migration\output\nupic\encoders\category.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\encoders\coordinate.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\encoders\coordinate.py to D:\nupic\python_migration\output\nupic\encoders\coordinate.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\encoders\date.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\encoders\date.py to D:\nupic\python_migration\output\nupic\encoders\date.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\encoders\delta.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\encoders\delta.py to D:\nupic\python_migration\output\nupic\encoders\delta.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\encoders\geospatial_coordinate.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\encoders\geospatial_coordinate.py to D:\nupic\python_migration\output\nupic\encoders\geospatial_coordinate.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\encoders\logarithm.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\encoders\logarithm.py to D:\nupic\python_migration\output\nupic\encoders\logarithm.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\encoders\multi.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\encoders\multi.py to D:\nupic\python_migration\output\nupic\encoders\multi.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\encoders\pass_through.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\encoders\pass_through.py to D:\nupic\python_migration\output\nupic\encoders\pass_through.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\encoders\random_distributed_scalar.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\encoders\random_distributed_scalar.py to D:\nupic\python_migration\output\nupic\encoders\random_distributed_scalar.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\encoders\scalar.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\encoders\scalar.py to D:\nupic\python_migration\output\nupic\encoders\scalar.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\encoders\scalar_space.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\encoders\scalar_space.py to D:\nupic\python_migration\output\nupic\encoders\scalar_space.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\encoders\sdr_category.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\encoders\sdr_category.py to D:\nupic\python_migration\output\nupic\encoders\sdr_category.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\encoders\sparse_pass_through.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\encoders\sparse_pass_through.py to D:\nupic\python_migration\output\nupic\encoders\sparse_pass_through.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\encoders\utils.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\encoders\utils.py to D:\nupic\python_migration\output\nupic\encoders\utils.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\engine\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\engine\__init__.py to D:\nupic\python_migration\output\nupic\engine\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\frameworks\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\__init__.py to D:\nupic\python_migration\output\nupic\frameworks\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\frameworks\opf\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\__init__.py to D:\nupic\python_migration\output\nupic\frameworks\opf\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\opf\client.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\client.py to D:\nupic\python_migration\output\nupic\frameworks\opf\client.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\frameworks\opf\exceptions.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\exceptions.py to D:\nupic\python_migration\output\nupic\frameworks\opf\exceptions.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\opf\exp_description_api.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\exp_description_api.py to D:\nupic\python_migration\output\nupic\frameworks\opf\exp_description_api.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\opf\exp_description_helpers.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\exp_description_helpers.py to D:\nupic\python_migration\output\nupic\frameworks\opf\exp_description_helpers.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\opf\experiment_runner.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\experiment_runner.py to D:\nupic\python_migration\output\nupic\frameworks\opf\experiment_runner.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\opf\helpers.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\helpers.py to D:\nupic\python_migration\output\nupic\frameworks\opf\helpers.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\opf\htm_prediction_model.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\htm_prediction_model.py to D:\nupic\python_migration\output\nupic\frameworks\opf\htm_prediction_model.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\opf\htm_prediction_model_callbacks.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\htm_prediction_model_callbacks.py to D:\nupic\python_migration\output\nupic\frameworks\opf\htm_prediction_model_callbacks.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\opf\htm_prediction_model_classifier_helper.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\htm_prediction_model_classifier_helper.py to D:\nupic\python_migration\output\nupic\frameworks\opf\htm_prediction_model_classifier_helper.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\opf\metrics.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\metrics.py to D:\nupic\python_migration\output\nupic\frameworks\opf\metrics.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\opf\model.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\model.py to D:\nupic\python_migration\output\nupic\frameworks\opf\model.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\frameworks\opf\model_callbacks.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\model_callbacks.py to D:\nupic\python_migration\output\nupic\frameworks\opf\model_callbacks.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\opf\model_factory.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\model_factory.py to D:\nupic\python_migration\output\nupic\frameworks\opf\model_factory.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\opf\opf_basic_environment.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\opf_basic_environment.py to D:\nupic\python_migration\output\nupic\frameworks\opf\opf_basic_environment.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\opf\opf_environment.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\opf_environment.py to D:\nupic\python_migration\output\nupic\frameworks\opf\opf_environment.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\opf\opf_task_driver.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\opf_task_driver.py to D:\nupic\python_migration\output\nupic\frameworks\opf\opf_task_driver.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\opf\opf_utils.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\opf_utils.py to D:\nupic\python_migration\output\nupic\frameworks\opf\opf_utils.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\opf\periodic.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\periodic.py to D:\nupic\python_migration\output\nupic\frameworks\opf\periodic.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\opf\prediction_metrics_manager.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\prediction_metrics_manager.py to D:\nupic\python_migration\output\nupic\frameworks\opf\prediction_metrics_manager.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\opf\previous_value_model.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\previous_value_model.py to D:\nupic\python_migration\output\nupic\frameworks\opf\previous_value_model.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\frameworks\opf\safe_interpreter.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\safe_interpreter.py to D:\nupic\python_migration\output\nupic\frameworks\opf\safe_interpreter.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\opf\two_gram_model.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\two_gram_model.py to D:\nupic\python_migration\output\nupic\frameworks\opf\two_gram_model.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\frameworks\opf\common_models\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\common_models\__init__.py to D:\nupic\python_migration\output\nupic\frameworks\opf\common_models\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\opf\common_models\cluster_params.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\common_models\cluster_params.py to D:\nupic\python_migration\output\nupic\frameworks\opf\common_models\cluster_params.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\frameworks\opf\jsonschema\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\opf\jsonschema\__init__.py to D:\nupic\python_migration\output\nupic\frameworks\opf\jsonschema\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\frameworks\viz\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\viz\__init__.py to D:\nupic\python_migration\output\nupic\frameworks\viz\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\viz\dot_renderer.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\viz\dot_renderer.py to D:\nupic\python_migration\output\nupic\frameworks\viz\dot_renderer.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\frameworks\viz\graphviz_renderer.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\viz\graphviz_renderer.py to D:\nupic\python_migration\output\nupic\frameworks\viz\graphviz_renderer.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\frameworks\viz\network_visualization.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\viz\network_visualization.py to D:\nupic\python_migration\output\nupic\frameworks\viz\network_visualization.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\frameworks\viz\networkx_renderer.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\viz\networkx_renderer.py to D:\nupic\python_migration\output\nupic\frameworks\viz\networkx_renderer.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\frameworks\viz\examples\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\viz\examples\__init__.py to D:\nupic\python_migration\output\nupic\frameworks\viz\examples\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\frameworks\viz\examples\visualize_network.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\frameworks\viz\examples\visualize_network.py to D:\nupic\python_migration\output\nupic\frameworks\viz\examples\visualize_network.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\math\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\math\__init__.py to D:\nupic\python_migration\output\nupic\math\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\math\cross.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\math\cross.py to D:\nupic\python_migration\output\nupic\math\cross.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\math\dist.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\math\dist.py to D:\nupic\python_migration\output\nupic\math\dist.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\math\logarithms.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\math\logarithms.py to D:\nupic\python_migration\output\nupic\math\logarithms.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\math\mvn.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\math\mvn.py to D:\nupic\python_migration\output\nupic\math\mvn.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\math\proposal.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\math\proposal.py to D:\nupic\python_migration\output\nupic\math\proposal.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\math\roc_utils.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\math\roc_utils.py to D:\nupic\python_migration\output\nupic\math\roc_utils.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\math\stats.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\math\stats.py to D:\nupic\python_migration\output\nupic\math\stats.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\math\topology.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\math\topology.py to D:\nupic\python_migration\output\nupic\math\topology.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\regions\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\regions\__init__.py to D:\nupic\python_migration\output\nupic\regions\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\regions\anomaly_likelihood_region.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\regions\anomaly_likelihood_region.py to D:\nupic\python_migration\output\nupic\regions\anomaly_likelihood_region.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\regions\anomaly_region.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\regions\anomaly_region.py to D:\nupic\python_migration\output\nupic\regions\anomaly_region.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\regions\knn_anomaly_classifier_region.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\regions\knn_anomaly_classifier_region.py to D:\nupic\python_migration\output\nupic\regions\knn_anomaly_classifier_region.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\regions\knn_classifier_region.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\regions\knn_classifier_region.py to D:\nupic\python_migration\output\nupic\regions\knn_classifier_region.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\regions\pluggable_encoder_sensor.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\regions\pluggable_encoder_sensor.py to D:\nupic\python_migration\output\nupic\regions\pluggable_encoder_sensor.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\regions\record_sensor.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\regions\record_sensor.py to D:\nupic\python_migration\output\nupic\regions\record_sensor.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\regions\sdr_classifier_region.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\regions\sdr_classifier_region.py to D:\nupic\python_migration\output\nupic\regions\sdr_classifier_region.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\regions\sp_region.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\regions\sp_region.py to D:\nupic\python_migration\output\nupic\regions\sp_region.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\regions\spec.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\regions\spec.py to D:\nupic\python_migration\output\nupic\regions\spec.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\regions\test_region.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\regions\test_region.py to D:\nupic\python_migration\output\nupic\regions\test_region.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\regions\tm_region.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\regions\tm_region.py to D:\nupic\python_migration\output\nupic\regions\tm_region.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\regions\unimportable_node.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\regions\unimportable_node.py to D:\nupic\python_migration\output\nupic\regions\unimportable_node.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\regions\extra\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\regions\extra\__init__.py to D:\nupic\python_migration\output\nupic\regions\extra\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\support\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\support\__init__.py to D:\nupic\python_migration\output\nupic\support\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\support\configuration.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\support\configuration.py to D:\nupic\python_migration\output\nupic\support\configuration.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\support\configuration_base.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\support\configuration_base.py to D:\nupic\python_migration\output\nupic\support\configuration_base.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\support\configuration_custom.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\support\configuration_custom.py to D:\nupic\python_migration\output\nupic\support\configuration_custom.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\support\console_printer.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\support\console_printer.py to D:\nupic\python_migration\output\nupic\support\console_printer.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\support\decorators.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\support\decorators.py to D:\nupic\python_migration\output\nupic\support\decorators.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\support\enum.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\support\enum.py to D:\nupic\python_migration\output\nupic\support\enum.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\support\fs_helpers.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\support\fs_helpers.py to D:\nupic\python_migration\output\nupic\support\fs_helpers.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\support\group_by.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\support\group_by.py to D:\nupic\python_migration\output\nupic\support\group_by.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\support\lock_attributes.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\support\lock_attributes.py to D:\nupic\python_migration\output\nupic\support\lock_attributes.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\support\pymysql_helpers.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\support\pymysql_helpers.py to D:\nupic\python_migration\output\nupic\support\pymysql_helpers.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\support\unittesthelpers\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\support\unittesthelpers\__init__.py to D:\nupic\python_migration\output\nupic\support\unittesthelpers\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\support\unittesthelpers\abstract_temporal_memory_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\support\unittesthelpers\abstract_temporal_memory_test.py to D:\nupic\python_migration\output\nupic\support\unittesthelpers\abstract_temporal_memory_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\support\unittesthelpers\algorithm_test_helpers.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\support\unittesthelpers\algorithm_test_helpers.py to D:\nupic\python_migration\output\nupic\support\unittesthelpers\algorithm_test_helpers.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\support\unittesthelpers\test_framework_helpers.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\support\unittesthelpers\test_framework_helpers.py to D:\nupic\python_migration\output\nupic\support\unittesthelpers\test_framework_helpers.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\support\unittesthelpers\testcasebase.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\support\unittesthelpers\testcasebase.py to D:\nupic\python_migration\output\nupic\support\unittesthelpers\testcasebase.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\swarming\ModelRunner.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\ModelRunner.py to D:\nupic\python_migration\output\nupic\swarming\ModelRunner.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\swarming\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\__init__.py to D:\nupic\python_migration\output\nupic\swarming\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\swarming\api.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\api.py to D:\nupic\python_migration\output\nupic\swarming\api.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\swarming\dummy_model_runner.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\dummy_model_runner.py to D:\nupic\python_migration\output\nupic\swarming\dummy_model_runner.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\swarming\experiment_utils.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\experiment_utils.py to D:\nupic\python_migration\output\nupic\swarming\experiment_utils.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\swarming\hypersearch_v2.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\hypersearch_v2.py to D:\nupic\python_migration\output\nupic\swarming\hypersearch_v2.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\swarming\hypersearch_worker.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\hypersearch_worker.py to D:\nupic\python_migration\output\nupic\swarming\hypersearch_worker.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\swarming\model_chooser.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\model_chooser.py to D:\nupic\python_migration\output\nupic\swarming\model_chooser.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\swarming\permutation_helpers.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\permutation_helpers.py to D:\nupic\python_migration\output\nupic\swarming\permutation_helpers.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\swarming\permutations_runner.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\permutations_runner.py to D:\nupic\python_migration\output\nupic\swarming\permutations_runner.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\swarming\utils.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\utils.py to D:\nupic\python_migration\output\nupic\swarming\utils.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\swarming\exp_generator\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\exp_generator\__init__.py to D:\nupic\python_migration\output\nupic\swarming\exp_generator\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\swarming\exp_generator\experiment_generator.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\exp_generator\experiment_generator.py to D:\nupic\python_migration\output\nupic\swarming\exp_generator\experiment_generator.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\swarming\hypersearch\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\hypersearch\__init__.py to D:\nupic\python_migration\output\nupic\swarming\hypersearch\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\swarming\hypersearch\error_codes.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\hypersearch\error_codes.py to D:\nupic\python_migration\output\nupic\swarming\hypersearch\error_codes.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\swarming\hypersearch\extended_logger.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\hypersearch\extended_logger.py to D:\nupic\python_migration\output\nupic\swarming\hypersearch\extended_logger.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\swarming\hypersearch\hs_state.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\hypersearch\hs_state.py to D:\nupic\python_migration\output\nupic\swarming\hypersearch\hs_state.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\swarming\hypersearch\model_terminator.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\hypersearch\model_terminator.py to D:\nupic\python_migration\output\nupic\swarming\hypersearch\model_terminator.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\swarming\hypersearch\object_json.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\hypersearch\object_json.py to D:\nupic\python_migration\output\nupic\swarming\hypersearch\object_json.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\swarming\hypersearch\particle.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\hypersearch\particle.py to D:\nupic\python_migration\output\nupic\swarming\hypersearch\particle.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\swarming\hypersearch\permutation_helpers.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\hypersearch\permutation_helpers.py to D:\nupic\python_migration\output\nupic\swarming\hypersearch\permutation_helpers.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\swarming\hypersearch\regression.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\hypersearch\regression.py to D:\nupic\python_migration\output\nupic\swarming\hypersearch\regression.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\swarming\hypersearch\support.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\hypersearch\support.py to D:\nupic\python_migration\output\nupic\swarming\hypersearch\support.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\nupic\swarming\hypersearch\swarm_terminator.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\hypersearch\swarm_terminator.py to D:\nupic\python_migration\output\nupic\swarming\hypersearch\swarm_terminator.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\nupic\swarming\jsonschema\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\nupic\swarming\jsonschema\__init__.py to D:\nupic\python_migration\output\nupic\swarming\jsonschema\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\scripts\run_experiment_classifier_diff.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\scripts\run_experiment_classifier_diff.py to D:\nupic\python_migration\output\scripts\run_experiment_classifier_diff.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\scripts\run_nupic_tests.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\scripts\run_nupic_tests.py to D:\nupic\python_migration\output\scripts\run_nupic_tests.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\scripts\run_opf_experiment.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\scripts\run_opf_experiment.py to D:\nupic\python_migration\output\scripts\run_opf_experiment.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\scripts\run_swarm.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\scripts\run_swarm.py to D:\nupic\python_migration\output\scripts\run_swarm.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\scripts\temporal_memory_performance_benchmark.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\scripts\temporal_memory_performance_benchmark.py to D:\nupic\python_migration\output\scripts\temporal_memory_performance_benchmark.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\scripts\profiling\enc_profile.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\scripts\profiling\enc_profile.py to D:\nupic\python_migration\output\scripts\profiling\enc_profile.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\scripts\profiling\profile_opf_memory.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\scripts\profiling\profile_opf_memory.py to D:\nupic\python_migration\output\scripts\profiling\profile_opf_memory.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\scripts\profiling\sp_profile.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\scripts\profiling\sp_profile.py to D:\nupic\python_migration\output\scripts\profiling\sp_profile.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\scripts\profiling\tm_profile.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\scripts\profiling\tm_profile.py to D:\nupic\python_migration\output\scripts\profiling\tm_profile.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\__init__.py to D:\nupic\python_migration\output\tests\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\external\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\external\__init__.py to D:\nupic\python_migration\output\tests\external\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\external\asteval_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\external\asteval_test.py to D:\nupic\python_migration\output\tests\external\asteval_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\external\testfixture_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\external\testfixture_test.py to D:\nupic\python_migration\output\tests\external\testfixture_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\integration\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\__init__.py to D:\nupic\python_migration\output\tests\integration\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\integration\nupic\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\__init__.py to D:\nupic\python_migration\output\tests\integration\nupic\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\integration\nupic\algorithms\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\algorithms\__init__.py to D:\nupic\python_migration\output\tests\integration\nupic\algorithms\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\algorithms\extensive_tm_cpp_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\algorithms\extensive_tm_cpp_test.py to D:\nupic\python_migration\output\tests\integration\nupic\algorithms\extensive_tm_cpp_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\algorithms\extensive_tm_py_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\algorithms\extensive_tm_py_test.py to D:\nupic\python_migration\output\tests\integration\nupic\algorithms\extensive_tm_py_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\algorithms\extensive_tm_test_base.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\algorithms\extensive_tm_test_base.py to D:\nupic\python_migration\output\tests\integration\nupic\algorithms\extensive_tm_test_base.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\algorithms\tm_likelihood_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\algorithms\tm_likelihood_test.py to D:\nupic\python_migration\output\tests\integration\nupic\algorithms\tm_likelihood_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\algorithms\tm_overlapping_sequences_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\algorithms\tm_overlapping_sequences_test.py to D:\nupic\python_migration\output\tests\integration\nupic\algorithms\tm_overlapping_sequences_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\algorithms\tm_segment_learning.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\algorithms\tm_segment_learning.py to D:\nupic\python_migration\output\tests\integration\nupic\algorithms\tm_segment_learning.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\algorithms\tm_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\algorithms\tm_test.py to D:\nupic\python_migration\output\tests\integration\nupic\algorithms\tm_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\algorithms\tutorial_temporal_memory_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\algorithms\tutorial_temporal_memory_test.py to D:\nupic\python_migration\output\tests\integration\nupic\algorithms\tutorial_temporal_memory_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\integration\nupic\algorithms\knn_classifier_test\categories_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\algorithms\knn_classifier_test\categories_test.py to D:\nupic\python_migration\output\tests\integration\nupic\algorithms\knn_classifier_test\categories_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\algorithms\knn_classifier_test\classifier_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\algorithms\knn_classifier_test\classifier_test.py to D:\nupic\python_migration\output\tests\integration\nupic\algorithms\knn_classifier_test\classifier_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\integration\nupic\algorithms\knn_classifier_test\pca_knn_data.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\algorithms\knn_classifier_test\pca_knn_data.py to D:\nupic\python_migration\output\tests\integration\nupic\algorithms\knn_classifier_test\pca_knn_data.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\integration\nupic\algorithms\monitor_mixin\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\algorithms\monitor_mixin\__init__.py to D:\nupic\python_migration\output\tests\integration\nupic\algorithms\monitor_mixin\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\algorithms\monitor_mixin\temporal_memory_monitor_mixin_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\algorithms\monitor_mixin\temporal_memory_monitor_mixin_test.py to D:\nupic\python_migration\output\tests\integration\nupic\algorithms\monitor_mixin\temporal_memory_monitor_mixin_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\integration\nupic\data\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\data\__init__.py to D:\nupic\python_migration\output\tests\integration\nupic\data\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\data\aggregation_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\data\aggregation_test.py to D:\nupic\python_migration\output\tests\integration\nupic\data\aggregation_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\integration\nupic\engine\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\engine\__init__.py to D:\nupic\python_migration\output\tests\integration\nupic\engine\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\engine\network_checkpoint_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\engine\network_checkpoint_test.py to D:\nupic\python_migration\output\tests\integration\nupic\engine\network_checkpoint_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\engine\network_creation_common.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\engine\network_creation_common.py to D:\nupic\python_migration\output\tests\integration\nupic\engine\network_creation_common.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\engine\network_testnode_interchangeability.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\engine\network_testnode_interchangeability.py to D:\nupic\python_migration\output\tests\integration\nupic\engine\network_testnode_interchangeability.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\engine\network_twonode_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\engine\network_twonode_test.py to D:\nupic\python_migration\output\tests\integration\nupic\engine\network_twonode_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\engine\temporal_memory_compatibility_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\engine\temporal_memory_compatibility_test.py to D:\nupic\python_migration\output\tests\integration\nupic\engine\temporal_memory_compatibility_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\engine\vector_file_sensor_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\engine\vector_file_sensor_test.py to D:\nupic\python_migration\output\tests\integration\nupic\engine\vector_file_sensor_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\integration\nupic\opf\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\__init__.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\expgenerator_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\expgenerator_test.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\expgenerator_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\hotgym_regression_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\hotgym_regression_test.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\hotgym_regression_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\htmpredictionmodel_serialization_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\htmpredictionmodel_serialization_test.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\htmpredictionmodel_serialization_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_stress_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_stress_test.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_checkpoint_stress_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_experiment_results_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_experiment_results_test.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_experiment_results_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_experiments_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_experiments_test.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_experiments_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_region_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_region_test.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_region_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\integration\nupic\opf\prediction_metrics_manager_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\prediction_metrics_manager_test.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\prediction_metrics_manager_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\opf_checkpoint_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\opf_checkpoint_test.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_checkpoint_test\opf_checkpoint_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\backwards_compatibility\base.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\backwards_compatibility\base.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_checkpoint_test\experiments\backwards_compatibility\base.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\backwards_compatibility\a\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\backwards_compatibility\a\description.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_checkpoint_test\experiments\backwards_compatibility\a\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\non_temporal_multi_step\base.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\non_temporal_multi_step\base.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_checkpoint_test\experiments\non_temporal_multi_step\base.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\non_temporal_multi_step\a\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\non_temporal_multi_step\a\description.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_checkpoint_test\experiments\non_temporal_multi_step\a\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\non_temporal_multi_step\a_plus_b\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\non_temporal_multi_step\a_plus_b\description.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_checkpoint_test\experiments\non_temporal_multi_step\a_plus_b\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\non_temporal_multi_step\b\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\non_temporal_multi_step\b\description.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_checkpoint_test\experiments\non_temporal_multi_step\b\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_anomaly\base.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_anomaly\base.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_anomaly\base.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_anomaly\a\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_anomaly\a\description.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_anomaly\a\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_anomaly\a_plus_b\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_anomaly\a_plus_b\description.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_anomaly\a_plus_b\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_anomaly\b\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_anomaly\b\description.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_anomaly\b\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_multi_step\base.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_multi_step\base.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_multi_step\base.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_multi_step\a\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_multi_step\a\description.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_multi_step\a\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_multi_step\a_plus_b\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_multi_step\a_plus_b\description.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_multi_step\a_plus_b\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_multi_step\b\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_multi_step\b\description.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_multi_step\b\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_description_template_test\opf_description_template_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_description_template_test\opf_description_template_test.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_description_template_test\opf_description_template_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_description_template_test\experiments\gym\base.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_description_template_test\experiments\gym\base.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_description_template_test\experiments\gym\base.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_description_template_test\experiments\gym\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_description_template_test\experiments\gym\description.py to D:\nupic\python_migration\output\tests\integration\nupic\opf\opf_description_template_test\experiments\gym\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\integration\nupic\regions\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\regions\__init__.py to D:\nupic\python_migration\output\tests\integration\nupic\regions\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\regions\multiclass_knn_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\regions\multiclass_knn_test.py to D:\nupic\python_migration\output\tests\integration\nupic\regions\multiclass_knn_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\integration\nupic\regions\single_step_sdr_classifier_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\integration\nupic\regions\single_step_sdr_classifier_test.py to D:\nupic\python_migration\output\tests\integration\nupic\regions\single_step_sdr_classifier_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\regression\run_opf_benchmarks_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\regression\run_opf_benchmarks_test.py to D:\nupic\python_migration\output\tests\regression\run_opf_benchmarks_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\swarming\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\__init__.py to D:\nupic\python_migration\output\tests\swarming\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\swarming\nupic\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\__init__.py to D:\nupic\python_migration\output\tests\swarming\nupic\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\swarming\nupic\swarming\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\__init__.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\swarming\nupic\swarming\swarming_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\swarming_test.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\swarming_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\delta\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\delta\description.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\delta\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\delta\permutations.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\delta\permutations.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\delta\permutations.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\dummyV2\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\dummyV2\description.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\dummyV2\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\dummyV2\permutations.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\dummyV2\permutations.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\dummyV2\permutations.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\dummy_multi_v2\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\dummy_multi_v2\description.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\dummy_multi_v2\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\dummy_multi_v2\permutations.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\dummy_multi_v2\permutations.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\dummy_multi_v2\permutations.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\field_contrib_temporal\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\field_contrib_temporal\description.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\field_contrib_temporal\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\field_contrib_temporal\permutations.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\field_contrib_temporal\permutations.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\field_contrib_temporal\permutations.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\field_threshold_temporal\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\field_threshold_temporal\description.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\field_threshold_temporal\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\field_threshold_temporal\permutations.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\field_threshold_temporal\permutations.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\field_threshold_temporal\permutations.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\input_predicted_field\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\input_predicted_field\description.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\input_predicted_field\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\input_predicted_field\permutations.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\input_predicted_field\permutations.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\input_predicted_field\permutations.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\legacy_cla_multistep\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\legacy_cla_multistep\description.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\legacy_cla_multistep\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\legacy_cla_multistep\permutations.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\legacy_cla_multistep\permutations.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\legacy_cla_multistep\permutations.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\max_branching_temporal\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\max_branching_temporal\description.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\max_branching_temporal\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\max_branching_temporal\permutations.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\max_branching_temporal\permutations.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\max_branching_temporal\permutations.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\oneField\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\oneField\description.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\oneField\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\oneField\permutations.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\oneField\permutations.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\oneField\permutations.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\simpleV2\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\simpleV2\description.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\simpleV2\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\simpleV2\permutations.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\simpleV2\permutations.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\simpleV2\permutations.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\simple_cla_multistep\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\simple_cla_multistep\description.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\simple_cla_multistep\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\simple_cla_multistep\permutations.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\simple_cla_multistep\permutations.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\simple_cla_multistep\permutations.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\smart_speculation_spatial_classification\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\smart_speculation_spatial_classification\description.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\smart_speculation_spatial_classification\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\smart_speculation_spatial_classification\permutations.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\smart_speculation_spatial_classification\permutations.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\smart_speculation_spatial_classification\permutations.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\smart_speculation_temporal\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\smart_speculation_temporal\description.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\smart_speculation_temporal\description.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\smart_speculation_temporal\permutations.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\smart_speculation_temporal\permutations.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\smart_speculation_temporal\permutations.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\spatial_classification\description.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\spatial_classification\description.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\spatial_classification\description.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\spatial_classification\permutations.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\spatial_classification\permutations.py to D:\nupic\python_migration\output\tests\swarming\nupic\swarming\experiments\spatial_classification\permutations.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\__init__.py to D:\nupic\python_migration\output\tests\unit\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\__init__.py to D:\nupic\python_migration\output\tests\unit\nupic\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\serializable_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\serializable_test.py to D:\nupic\python_migration\output\tests\unit\nupic\serializable_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\utils_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\utils_test.py to D:\nupic\python_migration\output\tests\unit\nupic\utils_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\algorithms\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\__init__.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\algorithms\anomaly_likelihood_jeff_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\anomaly_likelihood_jeff_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\anomaly_likelihood_jeff_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\algorithms\anomaly_likelihood_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\anomaly_likelihood_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\anomaly_likelihood_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\algorithms\anomaly_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\anomaly_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\anomaly_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\algorithms\backtracking_tm_constant_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\backtracking_tm_constant_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\backtracking_tm_constant_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\algorithms\backtracking_tm_cpp2_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\backtracking_tm_cpp2_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\backtracking_tm_cpp2_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\algorithms\backtracking_tm_cpp_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\backtracking_tm_cpp_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\backtracking_tm_cpp_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\algorithms\backtracking_tm_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\backtracking_tm_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\backtracking_tm_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\algorithms\connections_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\connections_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\connections_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\algorithms\inhibition_object_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\inhibition_object_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\inhibition_object_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\algorithms\knn_classifier_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\knn_classifier_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\knn_classifier_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\algorithms\sdr_classifier_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\sdr_classifier_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\sdr_classifier_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\algorithms\sp_learn_inference_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\sp_learn_inference_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\sp_learn_inference_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\algorithms\sp_overlap_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\sp_overlap_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\sp_overlap_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\algorithms\spatial_pooler_boost_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\spatial_pooler_boost_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\spatial_pooler_boost_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\algorithms\spatial_pooler_compatability_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\spatial_pooler_compatability_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\spatial_pooler_compatability_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\algorithms\spatial_pooler_compute_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\spatial_pooler_compute_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\spatial_pooler_compute_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\algorithms\spatial_pooler_cpp_api_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\spatial_pooler_cpp_api_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\spatial_pooler_cpp_api_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\algorithms\spatial_pooler_cpp_unit_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\spatial_pooler_cpp_unit_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\spatial_pooler_cpp_unit_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\algorithms\spatial_pooler_py_api_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\spatial_pooler_py_api_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\spatial_pooler_py_api_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\algorithms\spatial_pooler_unit_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\spatial_pooler_unit_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\spatial_pooler_unit_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\algorithms\temporal_memory_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\temporal_memory_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\temporal_memory_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\algorithms\monitor_mixin\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\monitor_mixin\__init__.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\monitor_mixin\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\algorithms\monitor_mixin\metric_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\monitor_mixin\metric_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\monitor_mixin\metric_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\algorithms\monitor_mixin\trace_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\algorithms\monitor_mixin\trace_test.py to D:\nupic\python_migration\output\tests\unit\nupic\algorithms\monitor_mixin\trace_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\data\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\data\__init__.py to D:\nupic\python_migration\output\tests\unit\nupic\data\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\data\aggregator_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\data\aggregator_test.py to D:\nupic\python_migration\output\tests\unit\nupic\data\aggregator_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\data\dictutils_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\data\dictutils_test.py to D:\nupic\python_migration\output\tests\unit\nupic\data\dictutils_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\data\fieldmeta_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\data\fieldmeta_test.py to D:\nupic\python_migration\output\tests\unit\nupic\data\fieldmeta_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\data\file_record_stream_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\data\file_record_stream_test.py to D:\nupic\python_migration\output\tests\unit\nupic\data\file_record_stream_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\data\filters_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\data\filters_test.py to D:\nupic\python_migration\output\tests\unit\nupic\data\filters_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\data\functionsource_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\data\functionsource_test.py to D:\nupic\python_migration\output\tests\unit\nupic\data\functionsource_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\data\inference_shifter_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\data\inference_shifter_test.py to D:\nupic\python_migration\output\tests\unit\nupic\data\inference_shifter_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\data\record_stream_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\data\record_stream_test.py to D:\nupic\python_migration\output\tests\unit\nupic\data\record_stream_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\data\utils_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\data\utils_test.py to D:\nupic\python_migration\output\tests\unit\nupic\data\utils_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\data\generators\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\data\generators\__init__.py to D:\nupic\python_migration\output\tests\unit\nupic\data\generators\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\data\generators\anomalyzer_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\data\generators\anomalyzer_test.py to D:\nupic\python_migration\output\tests\unit\nupic\data\generators\anomalyzer_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\data\generators\pattern_machine_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\data\generators\pattern_machine_test.py to D:\nupic\python_migration\output\tests\unit\nupic\data\generators\pattern_machine_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\data\generators\sequence_machine_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\data\generators\sequence_machine_test.py to D:\nupic\python_migration\output\tests\unit\nupic\data\generators\sequence_machine_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\docs\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\docs\__init__.py to D:\nupic\python_migration\output\tests\unit\nupic\docs\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\docs\examples_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\docs\examples_test.py to D:\nupic\python_migration\output\tests\unit\nupic\docs\examples_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\encoders\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\encoders\__init__.py to D:\nupic\python_migration\output\tests\unit\nupic\encoders\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\encoders\adaptivescalar_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\encoders\adaptivescalar_test.py to D:\nupic\python_migration\output\tests\unit\nupic\encoders\adaptivescalar_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\encoders\category_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\encoders\category_test.py to D:\nupic\python_migration\output\tests\unit\nupic\encoders\category_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\encoders\coordinate_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\encoders\coordinate_test.py to D:\nupic\python_migration\output\tests\unit\nupic\encoders\coordinate_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\encoders\date_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\encoders\date_test.py to D:\nupic\python_migration\output\tests\unit\nupic\encoders\date_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\encoders\delta_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\encoders\delta_test.py to D:\nupic\python_migration\output\tests\unit\nupic\encoders\delta_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\encoders\geospatial_coordinate_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\encoders\geospatial_coordinate_test.py to D:\nupic\python_migration\output\tests\unit\nupic\encoders\geospatial_coordinate_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\encoders\logenc_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\encoders\logenc_test.py to D:\nupic\python_migration\output\tests\unit\nupic\encoders\logenc_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\encoders\multi_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\encoders\multi_test.py to D:\nupic\python_migration\output\tests\unit\nupic\encoders\multi_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\encoders\pass_through_encoder_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\encoders\pass_through_encoder_test.py to D:\nupic\python_migration\output\tests\unit\nupic\encoders\pass_through_encoder_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\encoders\random_distributed_scalar_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\encoders\random_distributed_scalar_test.py to D:\nupic\python_migration\output\tests\unit\nupic\encoders\random_distributed_scalar_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\encoders\scalar_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\encoders\scalar_test.py to D:\nupic\python_migration\output\tests\unit\nupic\encoders\scalar_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\encoders\scalarspace_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\encoders\scalarspace_test.py to D:\nupic\python_migration\output\tests\unit\nupic\encoders\scalarspace_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\encoders\sdrcategory_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\encoders\sdrcategory_test.py to D:\nupic\python_migration\output\tests\unit\nupic\encoders\sdrcategory_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\encoders\sparse_pass_through_encoder_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\encoders\sparse_pass_through_encoder_test.py to D:\nupic\python_migration\output\tests\unit\nupic\encoders\sparse_pass_through_encoder_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\engine\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\engine\__init__.py to D:\nupic\python_migration\output\tests\unit\nupic\engine\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\engine\network_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\engine\network_test.py to D:\nupic\python_migration\output\tests\unit\nupic\engine\network_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\engine\syntactic_sugar_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\engine\syntactic_sugar_test.py to D:\nupic\python_migration\output\tests\unit\nupic\engine\syntactic_sugar_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\engine\unified_py_parameter_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\engine\unified_py_parameter_test.py to D:\nupic\python_migration\output\tests\unit\nupic\engine\unified_py_parameter_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\frameworks\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\frameworks\__init__.py to D:\nupic\python_migration\output\tests\unit\nupic\frameworks\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\__init__.py to D:\nupic\python_migration\output\tests\unit\nupic\frameworks\opf\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\htmpredictionmodel_classifier_helper_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\htmpredictionmodel_classifier_helper_test.py to D:\nupic\python_migration\output\tests\unit\nupic\frameworks\opf\htmpredictionmodel_classifier_helper_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\htmpredictionmodel_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\htmpredictionmodel_test.py to D:\nupic\python_migration\output\tests\unit\nupic\frameworks\opf\htmpredictionmodel_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\opf_metrics_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\opf_metrics_test.py to D:\nupic\python_migration\output\tests\unit\nupic\frameworks\opf\opf_metrics_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\previous_value_model_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\previous_value_model_test.py to D:\nupic\python_migration\output\tests\unit\nupic\frameworks\opf\previous_value_model_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\safe_interpreter_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\safe_interpreter_test.py to D:\nupic\python_migration\output\tests\unit\nupic\frameworks\opf\safe_interpreter_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\two_gram_model_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\two_gram_model_test.py to D:\nupic\python_migration\output\tests\unit\nupic\frameworks\opf\two_gram_model_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\common_models\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\common_models\__init__.py to D:\nupic\python_migration\output\tests\unit\nupic\frameworks\opf\common_models\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\common_models\cluster_params_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\common_models\cluster_params_test.py to D:\nupic\python_migration\output\tests\unit\nupic\frameworks\opf\common_models\cluster_params_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\math\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\math\__init__.py to D:\nupic\python_migration\output\tests\unit\nupic\math\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\math\lgamma_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\math\lgamma_test.py to D:\nupic\python_migration\output\tests\unit\nupic\math\lgamma_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\math\topology_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\math\topology_test.py to D:\nupic\python_migration\output\tests\unit\nupic\math\topology_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\regions\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\regions\__init__.py to D:\nupic\python_migration\output\tests\unit\nupic\regions\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\regions\anomaly_likelihood_region_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\regions\anomaly_likelihood_region_test.py to D:\nupic\python_migration\output\tests\unit\nupic\regions\anomaly_likelihood_region_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\regions\anomaly_region_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\regions\anomaly_region_test.py to D:\nupic\python_migration\output\tests\unit\nupic\regions\anomaly_region_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\regions\knn_anomaly_classifier_region_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\regions\knn_anomaly_classifier_region_test.py to D:\nupic\python_migration\output\tests\unit\nupic\regions\knn_anomaly_classifier_region_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\regions\knn_classifier_region_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\regions\knn_classifier_region_test.py to D:\nupic\python_migration\output\tests\unit\nupic\regions\knn_classifier_region_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\regions\record_sensor_region_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\regions\record_sensor_region_test.py to D:\nupic\python_migration\output\tests\unit\nupic\regions\record_sensor_region_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\regions\regions_spec_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\regions\regions_spec_test.py to D:\nupic\python_migration\output\tests\unit\nupic\regions\regions_spec_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\regions\sdr_classifier_region_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\regions\sdr_classifier_region_test.py to D:\nupic\python_migration\output\tests\unit\nupic\regions\sdr_classifier_region_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\regions\tm_region_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\regions\tm_region_test.py to D:\nupic\python_migration\output\tests\unit\nupic\regions\tm_region_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\research\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\research\__init__.py to D:\nupic\python_migration\output\tests\unit\nupic\research\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\support\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\support\__init__.py to D:\nupic\python_migration\output\tests\unit\nupic\support\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\support\configuration_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\support\configuration_test.py to D:\nupic\python_migration\output\tests\unit\nupic\support\configuration_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\support\custom_configuration_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\support\custom_configuration_test.py to D:\nupic\python_migration\output\tests\unit\nupic\support\custom_configuration_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\tests\unit\nupic\support\decorators_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\support\decorators_test.py to D:\nupic\python_migration\output\tests\unit\nupic\support\decorators_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\support\group_by_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\support\group_by_test.py to D:\nupic\python_migration\output\tests\unit\nupic\support\group_by_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\support\object_json_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\support\object_json_test.py to D:\nupic\python_migration\output\tests\unit\nupic\support\object_json_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\tests\unit\nupic\support\consoleprinter_test\consoleprinter_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\tests\unit\nupic\support\consoleprinter_test\consoleprinter_test.py to D:\nupic\python_migration\output\tests\unit\nupic\support\consoleprinter_test\consoleprinter_test.py.
RefactoringTool: Files that were modified:
RefactoringTool: D:\nupic\python_migration\input\examples\bindings\sparse_matrix_how_to.py
RefactoringTool: D:\nupic\python_migration\input\examples\bindings\svm_how_to.py
RefactoringTool: D:\nupic\python_migration\input\examples\network\core_encoders_demo.py
RefactoringTool: D:\nupic\python_migration\input\examples\network\custom_region_demo.py
RefactoringTool: D:\nupic\python_migration\input\examples\network\hierarchy_network_demo.py
RefactoringTool: D:\nupic\python_migration\input\examples\network\network_api_demo.py
RefactoringTool: D:\nupic\python_migration\input\examples\network\temporal_anomaly_network_demo.py
RefactoringTool: D:\nupic\python_migration\input\examples\network\custom_region\__init__.py
RefactoringTool: D:\nupic\python_migration\input\examples\network\custom_region\identity_region.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\clients\cpu\cpu.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\clients\cpu\model_params.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\clients\hotgym\anomaly\hotgym_anomaly.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\clients\hotgym\anomaly\model_params.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\clients\hotgym\anomaly\one_gym\nupic_anomaly_output.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\clients\hotgym\anomaly\one_gym\remove_tuesdays.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\clients\hotgym\anomaly\one_gym\run.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\clients\hotgym\anomaly\one_gym\model_params\__init__.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\clients\hotgym\anomaly\one_gym\model_params\rec_center_hourly_model_params.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\clients\hotgym\prediction\one_gym\cleanup.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\clients\hotgym\prediction\one_gym\nupic_output.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\clients\hotgym\prediction\one_gym\run.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\clients\hotgym\prediction\one_gym\swarm.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\clients\hotgym\prediction\one_gym\swarm_description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\clients\hotgym\simple\hotgym.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\clients\hotgym\simple\model_params.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\clients\nyctaxi\model_params.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\clients\nyctaxi\nyctaxi_anomaly.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\10field_few2_skewed\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\10field_few_skewed\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\10field_many_skewed\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\1field_few_balanced\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\1field_few_skewed\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\2field_few_6040\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\2field_few_balanced\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\2field_few_skewed\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\2field_many_balanced\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\2field_many_novelAtEnd\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\2fields_many_skewed\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\novel_combination\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\anomaly\spatial\simple\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\anomaly\temporal\hotgym\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\anomaly\temporal\saw_200\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\anomaly\temporal\saw_big\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\anomaly\temporal\simple\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\classification\makeDatasets.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\classification\base_category\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\classification\base_scalar\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\classification\category_TM_0\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\classification\category_TM_1\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\classification\category_hub_TP_0\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\classification\scalar_TP_0\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\classification\scalar_TP_1\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\classification\scalar_encoder_0\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\missing_record\make_datasets.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\missing_record\base\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\missing_record\simple_0\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\make_datasets.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\base\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\base\permutations_simple_3.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\first_order_0\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym\permutations.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym\permutations_sp.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_enc\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_sp\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_sp_16K\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_sp_5step\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_sp_5step_16K\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_tp\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_tp_16K\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\hotgym_best_tp_5step\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_0\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_0_f2\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_1\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_1_f2\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_2\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_3\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_3_enc\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_3_f2\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\multistep\simple_3_sp\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\opfrunexperiment_test\checkpoints\base.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\opfrunexperiment_test\checkpoints\a\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\opfrunexperiment_test\checkpoints\a_plus_b\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\opfrunexperiment_test\checkpoints\b\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\opfrunexperiment_test\simpleOPF\hotgym\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\opfrunexperiment_test\simpleOPF\hotgym_1hr_agg\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\opfrunexperiment_test\simpleOPF\hotgym_no_agg\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\params\EnsembleOnline.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\params\test_all.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\make_datasets.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\run_exp_generator.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\auto_generated\searchDef.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\base\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\category_0\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\category_1\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\scalar_0\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\spatial_classification\scalar_1\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\experiments\template\base\descriptionTemplate.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\simple_server\demo.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\simple_server\model_params.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\tools\sp_plotter.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\tools\testDiagnostics.py
RefactoringTool: D:\nupic\python_migration\input\examples\opf\tools\MirrorImageViz\mirrorImageViz.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\category_prediction\clean.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\category_prediction\run.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\experiments\inspect_test.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\1\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\2\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\3\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\base\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\base\permutations_firstOrder.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\base\permutations_quick.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\base\permutations_secondOrder0.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\firstOrder\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\secondOrder0\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\secondOrder1\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\experiments\confidenceTest\secondOrder2\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\bSDRHighDC\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\bSDRSameDC\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\base\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\base\permutations.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\base\permutationsActiveCount.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\base\permutationsData.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\base\permutationsEncoder.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\experiments\dutyCycle\problem\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\prediction\experiments\generated_data\description.py
RefactoringTool: D:\nupic\python_migration\input\examples\sp\hello_sp.py
RefactoringTool: D:\nupic\python_migration\input\examples\sp\sp_tutorial.py
RefactoringTool: D:\nupic\python_migration\input\examples\swarm\test_db.py
RefactoringTool: D:\nupic\python_migration\input\examples\tm\hello_tm.py
RefactoringTool: D:\nupic\python_migration\input\examples\tm\tm_constant_test.py
RefactoringTool: D:\nupic\python_migration\input\examples\tm\tm_high_order.py
RefactoringTool: D:\nupic\python_migration\input\examples\tm\tm_overlapping_sequences.py
RefactoringTool: D:\nupic\python_migration\input\examples\tm\tm_segment_learning.py
RefactoringTool: D:\nupic\python_migration\input\examples\tm\tm_test.py
RefactoringTool: D:\nupic\python_migration\input\nupic\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\serializable.py
RefactoringTool: D:\nupic\python_migration\input\nupic\simple_server.py
RefactoringTool: D:\nupic\python_migration\input\nupic\utils.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\anomaly.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\anomaly_likelihood.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\backtracking_tm.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\backtracking_tm_cpp.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\backtracking_tm_shim.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\connections.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\fdrutilities.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\knn_classifier.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\sdr_classifier.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\sdr_classifier_diff.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\sdr_classifier_factory.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\spatial_pooler.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\temporal_memory.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\temporal_memory_shim.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\utils.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\monitor_mixin\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\monitor_mixin\metric.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\monitor_mixin\monitor_mixin_base.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\monitor_mixin\plot.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\monitor_mixin\temporal_memory_monitor_mixin.py
RefactoringTool: D:\nupic\python_migration\input\nupic\algorithms\monitor_mixin\trace.py
RefactoringTool: D:\nupic\python_migration\input\nupic\bindings\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\bindings\check.py
RefactoringTool: D:\nupic\python_migration\input\nupic\bindings\regions\PyRegion.py
RefactoringTool: D:\nupic\python_migration\input\nupic\bindings\regions\TestNode.py
RefactoringTool: D:\nupic\python_migration\input\nupic\bindings\regions\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\aggregator.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\category_filter.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\dict_utils.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\field_meta.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\file_record_stream.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\filters.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\function_source.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\inference_shifter.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\json_helpers.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\record_stream.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\sorter.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\stats.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\stats_v2.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\stream_reader.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\utils.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\generators\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\generators\anomalyzer.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\generators\data_generator.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\generators\distributions.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\generators\pattern_machine.py
RefactoringTool: D:\nupic\python_migration\input\nupic\data\generators\sequence_machine.py
RefactoringTool: D:\nupic\python_migration\input\nupic\database\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\database\client_jobs_dao.py
RefactoringTool: D:\nupic\python_migration\input\nupic\database\connection.py
RefactoringTool: D:\nupic\python_migration\input\nupic\datafiles\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\datafiles\extra\firstOrder\raw\makeDataset.py
RefactoringTool: D:\nupic\python_migration\input\nupic\datafiles\extra\generated\GenerateSampleData.py
RefactoringTool: D:\nupic\python_migration\input\nupic\datafiles\extra\gym\raw\makeDataset.py
RefactoringTool: D:\nupic\python_migration\input\nupic\datafiles\extra\hotgym\raw\makeDataset.py
RefactoringTool: D:\nupic\python_migration\input\nupic\datafiles\extra\regression\makeDataset.py
RefactoringTool: D:\nupic\python_migration\input\nupic\datafiles\extra\secondOrder\makeDataset.py
RefactoringTool: D:\nupic\python_migration\input\nupic\encoders\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\encoders\adaptive_scalar.py
RefactoringTool: D:\nupic\python_migration\input\nupic\encoders\base.py
RefactoringTool: D:\nupic\python_migration\input\nupic\encoders\category.py
RefactoringTool: D:\nupic\python_migration\input\nupic\encoders\coordinate.py
RefactoringTool: D:\nupic\python_migration\input\nupic\encoders\date.py
RefactoringTool: D:\nupic\python_migration\input\nupic\encoders\delta.py
RefactoringTool: D:\nupic\python_migration\input\nupic\encoders\geospatial_coordinate.py
RefactoringTool: D:\nupic\python_migration\input\nupic\encoders\logarithm.py
RefactoringTool: D:\nupic\python_migration\input\nupic\encoders\multi.py
RefactoringTool: D:\nupic\python_migration\input\nupic\encoders\pass_through.py
RefactoringTool: D:\nupic\python_migration\input\nupic\encoders\random_distributed_scalar.py
RefactoringTool: D:\nupic\python_migration\input\nupic\encoders\scalar.py
RefactoringTool: D:\nupic\python_migration\input\nupic\encoders\scalar_space.py
RefactoringTool: D:\nupic\python_migration\input\nupic\encoders\sdr_category.py
RefactoringTool: D:\nupic\python_migration\input\nupic\encoders\sparse_pass_through.py
RefactoringTool: D:\nupic\python_migration\input\nupic\encoders\utils.py
RefactoringTool: D:\nupic\python_migration\input\nupic\engine\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\client.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\exceptions.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\exp_description_api.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\exp_description_helpers.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\experiment_runner.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\helpers.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\htm_prediction_model.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\htm_prediction_model_callbacks.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\htm_prediction_model_classifier_helper.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\metrics.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\model.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\model_callbacks.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\model_factory.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\opf_basic_environment.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\opf_environment.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\opf_task_driver.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\opf_utils.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\periodic.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\prediction_metrics_manager.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\previous_value_model.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\safe_interpreter.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\two_gram_model.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\common_models\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\common_models\cluster_params.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\opf\jsonschema\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\viz\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\viz\dot_renderer.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\viz\graphviz_renderer.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\viz\network_visualization.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\viz\networkx_renderer.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\viz\examples\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\frameworks\viz\examples\visualize_network.py
RefactoringTool: D:\nupic\python_migration\input\nupic\math\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\math\cross.py
RefactoringTool: D:\nupic\python_migration\input\nupic\math\dist.py
RefactoringTool: D:\nupic\python_migration\input\nupic\math\logarithms.py
RefactoringTool: D:\nupic\python_migration\input\nupic\math\mvn.py
RefactoringTool: D:\nupic\python_migration\input\nupic\math\proposal.py
RefactoringTool: D:\nupic\python_migration\input\nupic\math\roc_utils.py
RefactoringTool: D:\nupic\python_migration\input\nupic\math\stats.py
RefactoringTool: D:\nupic\python_migration\input\nupic\math\topology.py
RefactoringTool: D:\nupic\python_migration\input\nupic\regions\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\regions\anomaly_likelihood_region.py
RefactoringTool: D:\nupic\python_migration\input\nupic\regions\anomaly_region.py
RefactoringTool: D:\nupic\python_migration\input\nupic\regions\knn_anomaly_classifier_region.py
RefactoringTool: D:\nupic\python_migration\input\nupic\regions\knn_classifier_region.py
RefactoringTool: D:\nupic\python_migration\input\nupic\regions\pluggable_encoder_sensor.py
RefactoringTool: D:\nupic\python_migration\input\nupic\regions\record_sensor.py
RefactoringTool: D:\nupic\python_migration\input\nupic\regions\sdr_classifier_region.py
RefactoringTool: D:\nupic\python_migration\input\nupic\regions\sp_region.py
RefactoringTool: D:\nupic\python_migration\input\nupic\regions\spec.py
RefactoringTool: D:\nupic\python_migration\input\nupic\regions\test_region.py
RefactoringTool: D:\nupic\python_migration\input\nupic\regions\tm_region.py
RefactoringTool: D:\nupic\python_migration\input\nupic\regions\unimportable_node.py
RefactoringTool: D:\nupic\python_migration\input\nupic\regions\extra\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\support\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\support\configuration.py
RefactoringTool: D:\nupic\python_migration\input\nupic\support\configuration_base.py
RefactoringTool: D:\nupic\python_migration\input\nupic\support\configuration_custom.py
RefactoringTool: D:\nupic\python_migration\input\nupic\support\console_printer.py
RefactoringTool: D:\nupic\python_migration\input\nupic\support\decorators.py
RefactoringTool: D:\nupic\python_migration\input\nupic\support\enum.py
RefactoringTool: D:\nupic\python_migration\input\nupic\support\fs_helpers.py
RefactoringTool: D:\nupic\python_migration\input\nupic\support\group_by.py
RefactoringTool: D:\nupic\python_migration\input\nupic\support\lock_attributes.py
RefactoringTool: D:\nupic\python_migration\input\nupic\support\pymysql_helpers.py
RefactoringTool: D:\nupic\python_migration\input\nupic\support\unittesthelpers\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\support\unittesthelpers\abstract_temporal_memory_test.py
RefactoringTool: D:\nupic\python_migration\input\nupic\support\unittesthelpers\algorithm_test_helpers.py
RefactoringTool: D:\nupic\python_migration\input\nupic\support\unittesthelpers\test_framework_helpers.py
RefactoringTool: D:\nupic\python_migration\input\nupic\support\unittesthelpers\testcasebase.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\ModelRunner.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\api.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\dummy_model_runner.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\experiment_utils.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\hypersearch_v2.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\hypersearch_worker.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\model_chooser.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\permutation_helpers.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\permutations_runner.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\utils.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\exp_generator\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\exp_generator\experiment_generator.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\hypersearch\__init__.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\hypersearch\error_codes.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\hypersearch\extended_logger.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\hypersearch\hs_state.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\hypersearch\model_terminator.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\hypersearch\object_json.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\hypersearch\particle.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\hypersearch\permutation_helpers.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\hypersearch\regression.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\hypersearch\support.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\hypersearch\swarm_terminator.py
RefactoringTool: D:\nupic\python_migration\input\nupic\swarming\jsonschema\__init__.py
RefactoringTool: D:\nupic\python_migration\input\scripts\run_experiment_classifier_diff.py
RefactoringTool: D:\nupic\python_migration\input\scripts\run_nupic_tests.py
RefactoringTool: D:\nupic\python_migration\input\scripts\run_opf_experiment.py
RefactoringTool: D:\nupic\python_migration\input\scripts\run_swarm.py
RefactoringTool: D:\nupic\python_migration\input\scripts\temporal_memory_performance_benchmark.py
RefactoringTool: D:\nupic\python_migration\input\scripts\profiling\enc_profile.py
RefactoringTool: D:\nupic\python_migration\input\scripts\profiling\profile_opf_memory.py
RefactoringTool: D:\nupic\python_migration\input\scripts\profiling\sp_profile.py
RefactoringTool: D:\nupic\python_migration\input\scripts\profiling\tm_profile.py
RefactoringTool: D:\nupic\python_migration\input\tests\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\external\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\external\asteval_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\external\testfixture_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\algorithms\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\algorithms\extensive_tm_cpp_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\algorithms\extensive_tm_py_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\algorithms\extensive_tm_test_base.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\algorithms\tm_likelihood_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\algorithms\tm_overlapping_sequences_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\algorithms\tm_segment_learning.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\algorithms\tm_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\algorithms\tutorial_temporal_memory_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\algorithms\knn_classifier_test\categories_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\algorithms\knn_classifier_test\classifier_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\algorithms\knn_classifier_test\pca_knn_data.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\algorithms\monitor_mixin\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\algorithms\monitor_mixin\temporal_memory_monitor_mixin_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\data\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\data\aggregation_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\engine\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\engine\network_checkpoint_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\engine\network_creation_common.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\engine\network_testnode_interchangeability.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\engine\network_twonode_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\engine\temporal_memory_compatibility_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\engine\vector_file_sensor_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\expgenerator_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\hotgym_regression_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\htmpredictionmodel_serialization_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_stress_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_experiment_results_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_experiments_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_region_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\prediction_metrics_manager_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\opf_checkpoint_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\backwards_compatibility\base.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\backwards_compatibility\a\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\non_temporal_multi_step\base.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\non_temporal_multi_step\a\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\non_temporal_multi_step\a_plus_b\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\non_temporal_multi_step\b\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_anomaly\base.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_anomaly\a\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_anomaly\a_plus_b\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_anomaly\b\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_multi_step\base.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_multi_step\a\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_multi_step\a_plus_b\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_checkpoint_test\experiments\temporal_multi_step\b\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_description_template_test\opf_description_template_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_description_template_test\experiments\gym\base.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\opf\opf_description_template_test\experiments\gym\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\regions\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\regions\multiclass_knn_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\integration\nupic\regions\single_step_sdr_classifier_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\regression\run_opf_benchmarks_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\swarming_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\delta\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\delta\permutations.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\dummyV2\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\dummyV2\permutations.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\dummy_multi_v2\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\dummy_multi_v2\permutations.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\field_contrib_temporal\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\field_contrib_temporal\permutations.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\field_threshold_temporal\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\field_threshold_temporal\permutations.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\input_predicted_field\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\input_predicted_field\permutations.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\legacy_cla_multistep\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\legacy_cla_multistep\permutations.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\max_branching_temporal\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\max_branching_temporal\permutations.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\oneField\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\oneField\permutations.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\simpleV2\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\simpleV2\permutations.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\simple_cla_multistep\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\simple_cla_multistep\permutations.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\smart_speculation_spatial_classification\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\smart_speculation_spatial_classification\permutations.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\smart_speculation_temporal\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\smart_speculation_temporal\permutations.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\spatial_classification\description.py
RefactoringTool: D:\nupic\python_migration\input\tests\swarming\nupic\swarming\experiments\spatial_classification\permutations.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\serializable_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\utils_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\anomaly_likelihood_jeff_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\anomaly_likelihood_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\anomaly_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\backtracking_tm_constant_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\backtracking_tm_cpp2_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\backtracking_tm_cpp_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\backtracking_tm_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\connections_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\inhibition_object_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\knn_classifier_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\sdr_classifier_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\sp_learn_inference_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\sp_overlap_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\spatial_pooler_boost_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\spatial_pooler_compatability_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\spatial_pooler_compute_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\spatial_pooler_cpp_api_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\spatial_pooler_cpp_unit_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\spatial_pooler_py_api_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\spatial_pooler_unit_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\temporal_memory_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\monitor_mixin\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\monitor_mixin\metric_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\algorithms\monitor_mixin\trace_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\data\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\data\aggregator_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\data\dictutils_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\data\fieldmeta_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\data\file_record_stream_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\data\filters_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\data\functionsource_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\data\inference_shifter_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\data\record_stream_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\data\utils_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\data\generators\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\data\generators\anomalyzer_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\data\generators\pattern_machine_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\data\generators\sequence_machine_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\docs\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\docs\examples_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\encoders\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\encoders\adaptivescalar_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\encoders\category_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\encoders\coordinate_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\encoders\date_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\encoders\delta_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\encoders\geospatial_coordinate_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\encoders\logenc_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\encoders\multi_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\encoders\pass_through_encoder_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\encoders\random_distributed_scalar_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\encoders\scalar_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\encoders\scalarspace_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\encoders\sdrcategory_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\encoders\sparse_pass_through_encoder_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\engine\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\engine\network_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\engine\syntactic_sugar_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\engine\unified_py_parameter_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\frameworks\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\htmpredictionmodel_classifier_helper_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\htmpredictionmodel_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\opf_metrics_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\previous_value_model_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\safe_interpreter_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\two_gram_model_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\common_models\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\frameworks\opf\common_models\cluster_params_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\math\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\math\lgamma_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\math\topology_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\regions\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\regions\anomaly_likelihood_region_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\regions\anomaly_region_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\regions\knn_anomaly_classifier_region_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\regions\knn_classifier_region_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\regions\record_sensor_region_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\regions\regions_spec_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\regions\sdr_classifier_region_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\regions\tm_region_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\research\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\support\__init__.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\support\configuration_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\support\custom_configuration_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\support\decorators_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\support\group_by_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\support\object_json_test.py
RefactoringTool: D:\nupic\python_migration\input\tests\unit\nupic\support\consoleprinter_test\consoleprinter_test.py
RefactoringTool: Warnings/messages while refactoring:
RefactoringTool: ### In file D:\nupic\python_migration\input\examples\tm\tm_overlapping_sequences.py ###
RefactoringTool: Line 332: could not convert: raise "Not implemented for more than 2 TMs"
RefactoringTool: Python 3 does not support string exceptions
RefactoringTool: ### In file D:\nupic\python_migration\input\tests\integration\nupic\algorithms\tm_overlapping_sequences_test.py ###
RefactoringTool: Line 326: could not convert: raise "Not implemented for more than 2 TMs"
RefactoringTool: Python 3 does not support string exceptions
RefactoringTool: There was 1 error:
RefactoringTool: Can't parse D:\nupic\python_migration\input\examples\opf\experiments\multistep\base\permutations_simple_3.py: ParseError: bad input: type=22, value='=', context=(' ', (61, 15))


# Console output for migrating bindings/

Microsoft Windows [Version 10.0.16299.192]
(c) 2017 Microsoft Corporation. All rights reserved.

C:\Users\chhenning>python c:\Python36\Tools\scripts\2to3.py --output-dir D:\nupic\python_migration\output\bindings -W -n D:\nupic\python_migration\input\bindings > D:\nupic\python_migration\2to3_output__bindings.txt
WARNING: --write-unchanged-files/-W implies -w.
lib2to3.main: Output in 'D:\\nupic\\python_migration\\output\\bindings' will mirror the input directory 'D:\\nupic\\python_migration\\input\\bindings' layout.
RefactoringTool: Skipping optional fixer: buffer
RefactoringTool: Skipping optional fixer: idioms
RefactoringTool: Skipping optional fixer: set_literal
RefactoringTool: Skipping optional fixer: ws_comma
RefactoringTool: Refactored D:\nupic\python_migration\input\bindings\py\setup.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\setup.py to D:\nupic\python_migration\output\bindings\py\setup.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\bindings\py\src\nupic\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\src\nupic\__init__.py to D:\nupic\python_migration\output\bindings\py\src\nupic\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\__init__.py to D:\nupic\python_migration\output\bindings\py\src\nupic\bindings\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\check.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\check.py to D:\nupic\python_migration\output\bindings\py\src\nupic\bindings\check.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\regions\PyRegion.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\regions\PyRegion.py to D:\nupic\python_migration\output\bindings\py\src\nupic\bindings\regions\PyRegion.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\regions\TestNode.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\regions\TestNode.py to D:\nupic\python_migration\output\bindings\py\src\nupic\bindings\regions\TestNode.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\regions\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\regions\__init__.py to D:\nupic\python_migration\output\bindings\py\src\nupic\bindings\regions\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\tools\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\tools\__init__.py to D:\nupic\python_migration\output\bindings\py\src\nupic\bindings\tools\__init__.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\tools\cyclical_serialization_perf.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\tools\cyclical_serialization_perf.py to D:\nupic\python_migration\output\bindings\py\src\nupic\bindings\tools\cyclical_serialization_perf.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\tools\random_serialization_perf.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\tools\random_serialization_perf.py to D:\nupic\python_migration\output\bindings\py\src\nupic\bindings\tools\random_serialization_perf.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\tools\serialization_test_py_region.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\tools\serialization_test_py_region.py to D:\nupic\python_migration\output\bindings\py\src\nupic\bindings\tools\serialization_test_py_region.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\bindings\py\src\nupic\proto\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\src\nupic\proto\__init__.py to D:\nupic\python_migration\output\bindings\py\src\nupic\proto\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\bindings\py\tests\__init__.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\tests\__init__.py to D:\nupic\python_migration\output\bindings\py\tests\__init__.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\bindings\py\tests\array_algorithms_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\tests\array_algorithms_test.py to D:\nupic\python_migration\output\bindings\py\tests\array_algorithms_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\bindings\py\tests\cast_mode_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\tests\cast_mode_test.py to D:\nupic\python_migration\output\bindings\py\tests\cast_mode_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\bindings\py\tests\check_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\tests\check_test.py to D:\nupic\python_migration\output\bindings\py\tests\check_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\bindings\py\tests\connections_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\tests\connections_test.py to D:\nupic\python_migration\output\bindings\py\tests\connections_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\bindings\py\tests\network_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\tests\network_test.py to D:\nupic\python_migration\output\bindings\py\tests\network_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\bindings\py\tests\nupic_random_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\tests\nupic_random_test.py to D:\nupic\python_migration\output\bindings\py\tests\nupic_random_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\bindings\py\tests\pyregion_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\tests\pyregion_test.py to D:\nupic\python_migration\output\bindings\py\tests\pyregion_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\bindings\py\tests\segment_sparse_matrix_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\tests\segment_sparse_matrix_test.py to D:\nupic\python_migration\output\bindings\py\tests\segment_sparse_matrix_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\bindings\py\tests\sparse_binary_matrix_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\tests\sparse_binary_matrix_test.py to D:\nupic\python_migration\output\bindings\py\tests\sparse_binary_matrix_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\bindings\py\tests\sparse_matrix_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\tests\sparse_matrix_test.py to D:\nupic\python_migration\output\bindings\py\tests\sparse_matrix_test.py.
RefactoringTool: No changes to D:\nupic\python_migration\input\bindings\py\tests\temporal_memory_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\tests\temporal_memory_test.py to D:\nupic\python_migration\output\bindings\py\tests\temporal_memory_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\bindings\py\tests\algorithms\cells4_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\tests\algorithms\cells4_test.py to D:\nupic\python_migration\output\bindings\py\tests\algorithms\cells4_test.py.
RefactoringTool: Refactored D:\nupic\python_migration\input\bindings\py\tests\algorithms\svm_test.py
RefactoringTool: Writing converted D:\nupic\python_migration\input\bindings\py\tests\algorithms\svm_test.py to D:\nupic\python_migration\output\bindings\py\tests\algorithms\svm_test.py.
RefactoringTool: Files that were modified:
RefactoringTool: D:\nupic\python_migration\input\bindings\py\setup.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\src\nupic\__init__.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\__init__.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\check.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\regions\PyRegion.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\regions\TestNode.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\regions\__init__.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\tools\__init__.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\tools\cyclical_serialization_perf.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\tools\random_serialization_perf.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\src\nupic\bindings\tools\serialization_test_py_region.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\src\nupic\proto\__init__.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\tests\__init__.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\tests\array_algorithms_test.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\tests\cast_mode_test.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\tests\check_test.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\tests\connections_test.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\tests\network_test.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\tests\nupic_random_test.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\tests\pyregion_test.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\tests\segment_sparse_matrix_test.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\tests\sparse_binary_matrix_test.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\tests\sparse_matrix_test.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\tests\temporal_memory_test.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\tests\algorithms\cells4_test.py
RefactoringTool: D:\nupic\python_migration\input\bindings\py\tests\algorithms\svm_test.py
