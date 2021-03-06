#ifndef MPM_MPM_H_
#define MPM_MPM_H_

#include <memory>
#include <vector>

#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "mesh.h"

namespace mpm {
//! MPM class
//! \brief MPM class calls solver and algorithm
//! \details MPM class: implicit and explicit MPM
//! \tparam Tdim Dimension
template <unsigned Tdim>
class MPM {
 public:
  //! Constructor
  MPM() {
    // Unique id
    analysis_uuid_ =
        boost::lexical_cast<std::string>(boost::uuids::random_generator()());
    meshes_.clear();
  };

  //! Initialise mesh
  virtual bool initialise() = 0;

 protected:
  //! A unique id for the analysis
  std::string analysis_uuid_;

  //! Time step size
  double dt_{std::numeric_limits<double>::max()};

  //! Number of steps
  unsigned long long nsteps_{std::numeric_limits<unsigned long long>::max()};

  //! Mesh object
  std::vector<std::unique_ptr<mpm::Mesh<Tdim>>> meshes_;
};
}  // namespace mpm

#endif  // MPM_MPM_H_
