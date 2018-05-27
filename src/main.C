#include "VariadicTable.h"

int main()
{
  VariadicTable<std::string, double, double, double> pgt({"Section", "Self", "Children", "Total"});

  pgt.addRow({"Root", 0.004525, 0.051815, 0.05634});
  pgt.addRow({"  MooseApp::setup", 1e-05, 0.037072, 0.037082});
  pgt.addRow({"    FileMesh::init", 3e-06, 0.001548, 0.001551});
  pgt.addRow({"      FileMesh::readMesh", 0.001548, 0,0.001548});
  pgt.addRow({"    FileMesh::prepare", 5.1e-05, 0.000192, 0.000243});
  pgt.addRow({"    FEProblem::init", 6.7e-05, 0.002233, 0.0023});
  pgt.addRow({"      FEProblem::EquationSystems::Init", 0.002051, 0, 0.002051});
  pgt.addRow({"  MooseApp::execute", 0, 0.014732, 0.014732});
  pgt.addRow({"    FEProblem::initialSetup", 0.000376, 0.003268, 0.003644});
  pgt.addRow({"      FEProblem::projectSolution", 0.000144, 0, 0.000144});
  pgt.addRow({"    FEProblem::solve", 0.001181, 0.004169, 0.00535});
  pgt.addRow({"      FEProblem::computeResidualSys", 7e-06, 0.003489, 0.003496});
  pgt.addRow({"        FEProblem::computeResidualInternal", 1.3e-05, 0.003476, 0.003489});
  pgt.addRow({"          FEProblem::computeResidualTags", 4.9e-05, 0.003427, 0.003476});
  pgt.addRow({"            AuxiliarySystem::computeNodalVars", 0.000209, 1e-06, 0.00021});
  pgt.addRow({"      FEProblem::computeJacobianInternal", 1e-06, 0.000605, 0.000606});
  pgt.addRow({"        FEProblem::computeJacobianTags", 1e-05, 0.000595, 0.000605});
  pgt.addRow({"      Console::outputStep", 6e-05, 0, 6e-05});
  pgt.addRow({"    FEProblem::outputStep", 8.7e-05, 0.005496, 0.005583});
  pgt.addRow({"      PerfGraphOutput::outputStep", 4.3e-05, 0, 4.3e-05});
  pgt.addRow({"      Exodus::outputStep", 0.005395, 0, 0.005395});
  pgt.addRow({"      Console::outputStep", 5.8e-05, 0, 5.8e-05});

  pgt.print();
}
