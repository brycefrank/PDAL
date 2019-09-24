#pragma once

#include <pdal/Filter.hpp>
#include <pdal/pdal_internal.hpp>

namespace pdal
{

class PDAL_DLL BryceFilter : public Filter
{
public:
    BryceFilter() : Filter() {}
    std::string getName() const;

private:
    double m_value;
    Dimension::Id m_myDimension;

    virtual void addDimensions(PointLayoutPtr layout);
    virtual void addArgs(ProgramArgs& args);
    virtual PointViewSet run(PointViewPtr view);

    BryceFilter& operator=(const BryceFilter&); // not implemented
    BryceFilter(const BryceFilter&);            // not implemented
};

} // namespace pdal