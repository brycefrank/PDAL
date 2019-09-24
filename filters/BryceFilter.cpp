#include "BryceFilter.hpp"

#include <pdal/pdal_internal.hpp>

namespace pdal
{

static PluginInfo const s_info{"filters.brycefilter", "My awesome filter",
                               "http://link/to/documentation"};

CREATE_SHARED_STAGE(BryceFilter, s_info)

std::string BryceFilter::getName() const
{
    return s_info.name;
}

void BryceFilter::addArgs(ProgramArgs& args)
{
    args.add("param", "Some parameter", m_value, 1.0);
}

void BryceFilter::addDimensions(PointLayoutPtr layout)
{
    layout->registerDim(Dimension::Id::Intensity);
    m_myDimension =
        layout->registerOrAssignDim("MyDimension", Dimension::Type::Unsigned8);
}

PointViewSet BryceFilter::run(PointViewPtr input)
{
    PointViewSet viewSet;
    viewSet.insert(input);
    return viewSet;
}

} // namespace pdal