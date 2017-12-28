
enum XLAT_tmem_op_u {
    XLAT_tmem_op_u_creat,
    XLAT_tmem_op_u_ctrl,
    XLAT_tmem_op_u_gen,
};

#define XLAT_tmem_op(_d_, _s_) do { \
    (_d_)->cmd = (_s_)->cmd; \
    (_d_)->pool_id = (_s_)->pool_id; \
    switch (u) { \
    case XLAT_tmem_op_u_creat: \
        { \
            unsigned int i0; \
            for (i0 = 0; i0 <  2; ++i0) { \
                (_d_)->u.creat.uuid[i0] = (_s_)->u.creat.uuid[i0]; \
            } \
        } \
        (_d_)->u.creat.flags = (_s_)->u.creat.flags; \
        (_d_)->u.creat.arg1 = (_s_)->u.creat.arg1; \
        break; \
    case XLAT_tmem_op_u_ctrl: \
        (_d_)->u.ctrl.subop = (_s_)->u.ctrl.subop; \
        (_d_)->u.ctrl.cli_id = (_s_)->u.ctrl.cli_id; \
        (_d_)->u.ctrl.arg1 = (_s_)->u.ctrl.arg1; \
        (_d_)->u.ctrl.arg2 = (_s_)->u.ctrl.arg2; \
        { \
            unsigned int i0; \
            for (i0 = 0; i0 <  3; ++i0) { \
                (_d_)->u.ctrl.oid[i0] = (_s_)->u.ctrl.oid[i0]; \
            } \
        } \
        XLAT_tmem_op_HNDL_u_ctrl_buf(_d_, _s_); \
        break; \
    case XLAT_tmem_op_u_gen: \
        { \
            unsigned int i0; \
            for (i0 = 0; i0 <  3; ++i0) { \
                (_d_)->u.gen.oid[i0] = (_s_)->u.gen.oid[i0]; \
            } \
        } \
        (_d_)->u.gen.index = (_s_)->u.gen.index; \
        (_d_)->u.gen.tmem_offset = (_s_)->u.gen.tmem_offset; \
        (_d_)->u.gen.pfn_offset = (_s_)->u.gen.pfn_offset; \
        (_d_)->u.gen.len = (_s_)->u.gen.len; \
        (_d_)->u.gen.cmfn = (_s_)->u.gen.cmfn; \
        break; \
    } \
} while (0)
