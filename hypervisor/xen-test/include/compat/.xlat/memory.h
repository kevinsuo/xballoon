
#define XLAT_add_to_physmap(_d_, _s_) do { \
    (_d_)->domid = (_s_)->domid; \
    (_d_)->size = (_s_)->size; \
    (_d_)->space = (_s_)->space; \
    (_d_)->idx = (_s_)->idx; \
    (_d_)->gpfn = (_s_)->gpfn; \
} while (0)

#define XLAT_add_to_physmap_batch(_d_, _s_) do { \
    (_d_)->domid = (_s_)->domid; \
    (_d_)->space = (_s_)->space; \
    (_d_)->size = (_s_)->size; \
    (_d_)->foreign_domid = (_s_)->foreign_domid; \
    XLAT_add_to_physmap_batch_HNDL_idxs(_d_, _s_); \
    XLAT_add_to_physmap_batch_HNDL_gpfns(_d_, _s_); \
    XLAT_add_to_physmap_batch_HNDL_errs(_d_, _s_); \
} while (0)

#define XLAT_foreign_memory_map(_d_, _s_) do { \
    (_d_)->domid = (_s_)->domid; \
    XLAT_memory_map(&(_d_)->map, &(_s_)->map); \
} while (0)

#define XLAT_memory_exchange(_d_, _s_) do { \
    XLAT_memory_reservation(&(_d_)->in, &(_s_)->in); \
    XLAT_memory_reservation(&(_d_)->out, &(_s_)->out); \
    (_d_)->nr_exchanged = (_s_)->nr_exchanged; \
} while (0)

#define XLAT_memory_map(_d_, _s_) do { \
    (_d_)->nr_entries = (_s_)->nr_entries; \
    XLAT_memory_map_HNDL_buffer(_d_, _s_); \
} while (0)

#define XLAT_memory_reservation(_d_, _s_) do { \
    XLAT_memory_reservation_HNDL_extent_start(_d_, _s_); \
    (_d_)->nr_extents = (_s_)->nr_extents; \
    (_d_)->extent_order = (_s_)->extent_order; \
    (_d_)->mem_flags = (_s_)->mem_flags; \
    (_d_)->domid = (_s_)->domid; \
} while (0)

#define CHECK_mem_access_op \
    CHECK_SIZE_(struct, mem_access_op); \
    CHECK_FIELD_(struct, mem_access_op, op); \
    CHECK_FIELD_(struct, mem_access_op, access); \
    CHECK_FIELD_(struct, mem_access_op, domid); \
    CHECK_FIELD_(struct, mem_access_op, nr); \
    CHECK_FIELD_(struct, mem_access_op, pfn)

#define XLAT_pod_target(_d_, _s_) do { \
    (_d_)->target_pages = (_s_)->target_pages; \
    (_d_)->tot_pages = (_s_)->tot_pages; \
    (_d_)->pod_cache_pages = (_s_)->pod_cache_pages; \
    (_d_)->pod_entries = (_s_)->pod_entries; \
    (_d_)->domid = (_s_)->domid; \
} while (0)

#define XLAT_remove_from_physmap(_d_, _s_) do { \
    (_d_)->domid = (_s_)->domid; \
    (_d_)->gpfn = (_s_)->gpfn; \
} while (0)
