#include "VariadicTable.h"

int
main()
{
  // Tiny Table
  {
    VariadicTable<std::string, double, int, std::string> vt({"Name", "Weight", "Age", "Brother"},
                                                            10);

    vt.addRow("Cody", 180.2, 40, "John");
    vt.addRow("David", 175.3, 38, "Andrew");
    vt.addRow("Robert", 140.3, 27, "Fande");

    vt.print(std::cout);
  }

  // More Data
  {
    VariadicTable<std::string, double, double, double> vt({"Section", "Self", "Children", "Total"},
                                                          12);

    vt.setColumnFormat({VariadicTableColumnFormat::AUTO,
                        VariadicTableColumnFormat::SCIENTIFIC,
                        VariadicTableColumnFormat::FIXED,
                        VariadicTableColumnFormat::PERCENT});

    vt.setColumnPrecision({1, 3, 3, 2});

    vt.addRow("Root", 0.004525, 0.051815, 0.05634);
    vt.addRow("  MooseApp::setup", 1e-05, 0.037072, 0.037082);
    vt.addRow("    FileMesh::init", 3e-06, 0.001548, 0.001551);
    vt.addRow("      FileMesh::readMesh", 0.001548, 0, 0.001548);
    vt.addRow("    FileMesh::prepare", 5.1e-05, 0.000192, 0.000243);
    vt.addRow("    FEProblem::init", 6.7e-05, 0.002233, 0.0023);
    vt.addRow("      FEProblem::EquationSystems::Init", 0.002051, 0, 0.002051);
    vt.addRow("  MooseApp::execute", 0, 0.014732, 0.014732);
    vt.addRow("    FEProblem::initialSetup", 0.000376, 0.003268, 0.003644);
    vt.addRow("      FEProblem::projectSolution", 0.000144, 0, 0.000144);
    vt.addRow("    FEProblem::solve", 0.001181, 0.004169, 0.00535);
    vt.addRow("      FEProblem::computeResidualSys", 7e-06, 0.003489, 0.003496);
    vt.addRow("        FEProblem::computeResidualInternal", 1.3e-05, 0.003476, 0.003489);
    vt.addRow("          FEProblem::computeResidualTags", 4.9e-05, 0.003427, 0.003476);
    vt.addRow("            AuxiliarySystem::computeNodalVars", 0.000209, 1e-06, 0.00021);
    vt.addRow("      FEProblem::computeJacobianInternal", 1e-06, 0.000605, 0.000606);
    vt.addRow("        FEProblem::computeJacobianTags", 1e-05, 0.000595, 0.000605);
    vt.addRow("      Console::outputStep", 6e-05, 0, 6e-05);
    vt.addRow("    FEProblem::outputStep", 8.7e-05, 0.005496, 0.005583);
    vt.addRow("      PerfGraphOutput::outputStep", 4.3e-05, 0, 4.3e-05);
    vt.addRow("      Exodus::outputStep", 0.005395, 0, 0.005395);
    vt.addRow("      Console::outputStep", 5.8e-05, 0, 5.8e-05);

    vt.print(std::cout);
  }
}
