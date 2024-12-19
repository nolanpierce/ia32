#pragma once

#ifndef _IA32_T_H
#define _IA32_T_H
#include <ntddk.h>
#include "types_t.h"

typedef union _virt_addr_t
{
	void* value;
	struct
	{
		u64 offset : 12;
		u64 pt_index : 9;
		u64 pd_index : 9;
		u64 pdpt_index : 9;
		u64 pml4_index : 9;
		u64 reserved : 16;
	};
} virt_addr_t, * pvirt_addr_t;

typedef struct _mi_active_pfn_t
{
	union
	{
		struct
		{
			struct /* bitfield */
			{
				/* 0x0000 */ unsigned __int64 tradable : 1; /* bit position: 0 */
				/* 0x0000 */ unsigned __int64 non_paged_buddy : 43; /* bit position: 1 */
			}; /* bitfield */
		} /* size: 0x0008 */ Leaf;
		struct
		{
			struct /* bitfield */
			{
				/* 0x0000 */ unsigned __int64 tradable : 1; /* bit position: 0 */
				/* 0x0000 */ unsigned __int64 wsle_age : 3; /* bit position: 1 */
				/* 0x0000 */ unsigned __int64 oldest_wsle_leaf_entries : 10; /* bit position: 4 */
				/* 0x0000 */ unsigned __int64 oldest_wsle_leaf_age : 3; /* bit position: 14 */
				/* 0x0000 */ unsigned __int64 non_paged_buddy : 43; /* bit position: 17 */
			}; /* bitfield */
		} /* size: 0x0008 */ page_table;
		/* 0x0000 */ unsigned __int64 entire_active_field;
	}; /* size: 0x0008 */
} mi_active_pfn_t, * pmi_active_pfn_t; /* size: 0x0008 */

typedef struct _mmpte_hardware_t
{
	struct /* bitfield */
	{
		/* 0x0000 */ unsigned __int64 valid : 1; /* bit position: 0 */
		/* 0x0000 */ unsigned __int64 dirty1 : 1; /* bit position: 1 */
		/* 0x0000 */ unsigned __int64 owner : 1; /* bit position: 2 */
		/* 0x0000 */ unsigned __int64 write_through : 1; /* bit position: 3 */
		/* 0x0000 */ unsigned __int64 cache_disable : 1; /* bit position: 4 */
		/* 0x0000 */ unsigned __int64 accessed : 1; /* bit position: 5 */
		/* 0x0000 */ unsigned __int64 dirty : 1; /* bit position: 6 */
		/* 0x0000 */ unsigned __int64 large_page : 1; /* bit position: 7 */
		/* 0x0000 */ unsigned __int64 global : 1; /* bit position: 8 */
		/* 0x0000 */ unsigned __int64 copy_on_write : 1; /* bit position: 9 */
		/* 0x0000 */ unsigned __int64 unused : 1; /* bit position: 10 */
		/* 0x0000 */ unsigned __int64 write : 1; /* bit position: 11 */
		/* 0x0000 */ unsigned __int64 page_frame_number : 40; /* bit position: 12 */
		/* 0x0000 */ unsigned __int64 reserved_for_software : 4; /* bit position: 52 */
		/* 0x0000 */ unsigned __int64 wsle_age : 4; /* bit position: 56 */
		/* 0x0000 */ unsigned __int64 wsle_protection : 3; /* bit position: 60 */
		/* 0x0000 */ unsigned __int64 no_execute : 1; /* bit position: 63 */
	}; /* bitfield */
} mmpte_hardware_t, * pmmpte_hardware_t;

typedef struct _mmpte_prototype_t
{
	struct /* bitfield */
	{
		/* 0x0000 */ unsigned __int64 valid : 1; /* bit position: 0 */
		/* 0x0000 */ unsigned __int64 demand_fill_prototype : 1; /* bit position: 1 */
		/* 0x0000 */ unsigned __int64 hiber_verify_converted : 1; /* bit position: 2 */
		/* 0x0000 */ unsigned __int64 read_only : 1; /* bit position: 3 */
		/* 0x0000 */ unsigned __int64 swizzle_bit : 1; /* bit position: 4 */
		/* 0x0000 */ unsigned __int64 protection : 5; /* bit position: 5 */
		/* 0x0000 */ unsigned __int64 prototype : 1; /* bit position: 10 */
		/* 0x0000 */ unsigned __int64 combined : 1; /* bit position: 11 */
		/* 0x0000 */ unsigned __int64 unused1 : 4; /* bit position: 12 */
		/* 0x0000 */ __int64 prototype_address : 48; /* bit position: 16 */
	}; /* bitfield */
} mmpte_prototype_t, * pmmpte_prototype_t;

typedef struct _mmpte_software_t
{
	struct /* bitfield */
	{
		/* 0x0000 */ unsigned __int64 valid : 1; /* bit position: 0 */
		/* 0x0000 */ unsigned __int64 page_file_reserve : 1; /* bit position: 1 */
		/* 0x0000 */ unsigned __int64 page_file_allocated : 1; /* bit position: 2 */
		/* 0x0000 */ unsigned __int64 cold_page : 1; /* bit position: 3 */
		/* 0x0000 */ unsigned __int64 swizzle_bit : 1; /* bit position: 4 */
		/* 0x0000 */ unsigned __int64 protection : 5; /* bit position: 5 */
		/* 0x0000 */ unsigned __int64 prototype : 1; /* bit position: 10 */
		/* 0x0000 */ unsigned __int64 transition : 1; /* bit position: 11 */
		/* 0x0000 */ unsigned __int64 page_file_low : 4; /* bit position: 12 */
		/* 0x0000 */ unsigned __int64 used_page_table_entries : 10; /* bit position: 16 */
		/* 0x0000 */ unsigned __int64 shadow_stack : 1; /* bit position: 26 */
		/* 0x0000 */ unsigned __int64 unused : 5; /* bit position: 27 */
		/* 0x0000 */ unsigned __int64 page_file_high : 32; /* bit position: 32 */
	}; /* bitfield */
} mmpte_software_t, * pmmpte_software_t; /* size: 0x0008 */

typedef struct _mmpte_timestamp_t
{
	struct /* bitfield */
	{
		/* 0x0000 */ unsigned __int64 must_be_zero : 1; /* bit position: 0 */
		/* 0x0000 */ unsigned __int64 unused : 3; /* bit position: 1 */
		/* 0x0000 */ unsigned __int64 swizzle_bit : 1; /* bit position: 4 */
		/* 0x0000 */ unsigned __int64 protection : 5; /* bit position: 5 */
		/* 0x0000 */ unsigned __int64 prototype : 1; /* bit position: 10 */
		/* 0x0000 */ unsigned __int64 transition : 1; /* bit position: 11 */
		/* 0x0000 */ unsigned __int64 page_file_low : 4; /* bit position: 12 */
		/* 0x0000 */ unsigned __int64 reserved : 16; /* bit position: 16 */
		/* 0x0000 */ unsigned __int64 global_time_stamp : 32; /* bit position: 32 */
	}; /* bitfield */
} mmpte_timestamp_t, * pmmpte_timestamp_t; /* size: 0x0008 */

typedef struct _mmpte_transition_t
{
	struct /* bitfield */
	{
		/* 0x0000 */ unsigned __int64 valid : 1; /* bit position: 0 */
		/* 0x0000 */ unsigned __int64 write : 1; /* bit position: 1 */
		/* 0x0000 */ unsigned __int64 spare : 1; /* bit position: 2 */
		/* 0x0000 */ unsigned __int64 io_tracker : 1; /* bit position: 3 */
		/* 0x0000 */ unsigned __int64 swizzle_bit : 1; /* bit position: 4 */
		/* 0x0000 */ unsigned __int64 protection : 5; /* bit position: 5 */
		/* 0x0000 */ unsigned __int64 prototype : 1; /* bit position: 10 */
		/* 0x0000 */ unsigned __int64 transition : 1; /* bit position: 11 */
		/* 0x0000 */ unsigned __int64 page_frame_number : 40; /* bit position: 12 */
		/* 0x0000 */ unsigned __int64 unused : 12; /* bit position: 52 */
	}; /* bitfield */
} mmpte_transition_t, * pmmpte_transition_t; /* size: 0x0008 */

typedef struct _mmpte_subsection_t
{
	struct /* bitfield */
	{
		/* 0x0000 */ unsigned __int64 valid : 1; /* bit position: 0 */
		/* 0x0000 */ unsigned __int64 unused0 : 3; /* bit position: 1 */
		/* 0x0000 */ unsigned __int64 swizzle_bit : 1; /* bit position: 4 */
		/* 0x0000 */ unsigned __int64 protection : 5; /* bit position: 5 */
		/* 0x0000 */ unsigned __int64 prototype : 1; /* bit position: 10 */
		/* 0x0000 */ unsigned __int64 cold_page : 1; /* bit position: 11 */
		/* 0x0000 */ unsigned __int64 unused1 : 3; /* bit position: 12 */
		/* 0x0000 */ unsigned __int64 execute_privilege : 1; /* bit position: 15 */
		/* 0x0000 */ __int64 subsection_address : 48; /* bit position: 16 */
	}; /* bitfield */
} mmpte_subsection_t, * pmmpte_subsection_t; /* size: 0x0008 */

typedef struct _mmpte_list_t
{
	struct /* bitfield */
	{
		/* 0x0000 */ unsigned __int64 valid : 1; /* bit position: 0 */
		/* 0x0000 */ unsigned __int64 one_entry : 1; /* bit position: 1 */
		/* 0x0000 */ unsigned __int64 filler0 : 2; /* bit position: 2 */
		/* 0x0000 */ unsigned __int64 swizzle_bit : 1; /* bit position: 4 */
		/* 0x0000 */ unsigned __int64 protection : 5; /* bit position: 5 */
		/* 0x0000 */ unsigned __int64 prototype : 1; /* bit position: 10 */
		/* 0x0000 */ unsigned __int64 transition : 1; /* bit position: 11 */
		/* 0x0000 */ unsigned __int64 filler1 : 16; /* bit position: 12 */
		/* 0x0000 */ unsigned __int64 next_entry : 36; /* bit position: 28 */
	}; /* bitfield */
} mmpte_list_t, * pmmpte_list_t; /* size: 0x0008 */

typedef struct _mmpte_t
{
	union
	{
		union
		{
			/* 0x0000 */ unsigned __int64 Long;
			/* 0x0000 */ volatile unsigned __int64 volatile_long;
			/* 0x0000 */ struct _mmpte_hardware_t hardware;
			/* 0x0000 */ struct _mmpte_prototype_t prototype;
			/* 0x0000 */ struct _mmpte_software_t software;
			/* 0x0000 */ struct _mmpte_timestamp_t time_stamp;
			/* 0x0000 */ struct _mmpte_transition_t transition;
			/* 0x0000 */ struct _mmpte_subsection_t subsection;
			/* 0x0000 */ struct _mmpte_list_t list;
		}; /* size: 0x0008 */
	} /* size: 0x0008 */ u;
} mmpte_t, * pmmpte_t; /* size: 0x0008 */

typedef struct _mipfn_blink_t
{
	union
	{
		struct /* bitfield */
		{
			/* 0x0000 */ unsigned __int64 blink : 40; /* bit position: 0 */
			/* 0x0000 */ unsigned __int64 node_blink_low : 19; /* bit position: 40 */
			/* 0x0000 */ unsigned __int64 tb_flush_stamp : 3; /* bit position: 59 */
			/* 0x0000 */ unsigned __int64 page_blink_delete_bit : 1; /* bit position: 62 */
			/* 0x0000 */ unsigned __int64 page_blink_lock_bit : 1; /* bit position: 63 */
		}; /* bitfield */
		struct /* bitfield */
		{
			/* 0x0000 */ unsigned __int64 share_count : 62; /* bit position: 0 */
			/* 0x0000 */ unsigned __int64 page_share_count_delete_bit : 1; /* bit position: 62 */
			/* 0x0000 */ unsigned __int64 page_share_count_lock_bit : 1; /* bit position: 63 */
		}; /* bitfield */
		/* 0x0000 */ unsigned __int64 entire_field;
		/* 0x0000 */ volatile __int64 lock;
		struct /* bitfield */
		{
			/* 0x0000 */ unsigned __int64 lock_not_used : 62; /* bit position: 0 */
			/* 0x0000 */ unsigned __int64 delete_bit : 1; /* bit position: 62 */
			/* 0x0000 */ unsigned __int64 lock_bit : 1; /* bit position: 63 */
		}; /* bitfield */
	}; /* size: 0x0008 */
} mipfn_blink_t, * pmipfn_blink_t; /* size: 0x0008 */

typedef struct _mmpfn_entry1_t
{
	struct /* bitfield */
	{
		/* 0x0000 */ unsigned char page_location : 3; /* bit position: 0 */
		/* 0x0000 */ unsigned char write_in_progress : 1; /* bit position: 3 */
		/* 0x0000 */ unsigned char modified : 1; /* bit position: 4 */
		/* 0x0000 */ unsigned char read_in_progress : 1; /* bit position: 5 */
		/* 0x0000 */ unsigned char cache_attribute : 2; /* bit position: 6 */
	}; /* bitfield */
} mmpfn_entry1_t, * pmmpfn_entry1_t; /* size: 0x0001 */

typedef struct _mmpfn_entry3_t
{
	struct /* bitfield */
	{
		/* 0x0000 */ unsigned char priority : 3; /* bit position: 0 */
		/* 0x0000 */ unsigned char on_protected_standby : 1; /* bit position: 3 */
		/* 0x0000 */ unsigned char in_page_error : 1; /* bit position: 4 l1nky was here*/
		/* 0x0000 */ unsigned char system_charged_page : 1; /* bit position: 5 */
		/* 0x0000 */ unsigned char removal_requested : 1; /* bit position: 6 */
		/* 0x0000 */ unsigned char parity_error : 1; /* bit position: 7 */
	}; /* bitfield */
} mmpfn_entry3_t, * pmmpfn_entry3_t; /* size: 0x0001 */

typedef struct _mipfn_ulong5_t
{
	union
	{
		/* 0x0000 */ unsigned long entire_field;
		struct
		{
			struct /* bitfield */
			{
				/* 0x0000 */ unsigned long node_blink_high : 21; /* bit position: 0 */
				/* 0x0000 */ unsigned long node_flink_middle : 11; /* bit position: 21 */
			}; /* bitfield */
		} /* size: 0x0004 */ standby_list;
		struct
		{
			/* 0x0000 */ unsigned char modified_list_bucket_index : 4; /* bit position: 0 */
		} /* size: 0x0001 */ mapped_page_list;
		struct
		{
			struct /* bitfield */
			{
				/* 0x0000 */ unsigned char anchor_large_page_size : 2; /* bit position: 0 */
				/* 0x0000 */ unsigned char spare1 : 6; /* bit position: 2 */
			}; /* bitfield */
			/* 0x0001 */ unsigned char view_count;
			/* 0x0002 */ unsigned short spare2;
		} /* size: 0x0004 */ active;
	}; /* size: 0x0004 */
} mipfn_ulong5_t, * pmipfn_ulong5_t; /* size: 0x0004 */

typedef struct _mmpfn_t
{
	union
	{
		/* 0x0000 */ struct _LIST_ENTRY list_entry;
		/* 0x0000 */ struct _RTL_BALANCED_NODE tree_node;
		struct
		{
			union
			{
				union
				{
					/* 0x0000 */ struct _SINGLE_LIST_ENTRY next_slist_pfn;
					/* 0x0000 */ void* next;
					struct /* bitfield */
					{
						/* 0x0000 */ unsigned __int64 flink : 40; /* bit position: 0 */
						/* 0x0000 */ unsigned __int64 node_flink_low : 24; /* bit position: 40 */
					}; /* bitfield */
					/* 0x0000 */ struct _mi_active_pfn_t active;
				}; /* size: 0x0008 */
			} /* size: 0x0008 */ u1;
			union
			{
				/* 0x0008 */ struct _mmpte_t* pte_address;
				/* 0x0008 */ unsigned __int64 pte_long;
			}; /* size: 0x0008 */
			/* 0x0010 */ struct _mmpte_t original_pte;
		}; /* size: 0x0018 */
	}; /* size: 0x0018 */
	/* 0x0018 */ struct _mipfn_blink_t u2;
	union
	{
		union
		{
			struct
			{
				/* 0x0020 */ unsigned short reference_count;
				/* 0x0022 */ struct _mmpfn_entry1_t e1;
				/* 0x0023 */ struct _mmpfn_entry3_t e3;
			}; /* size: 0x0004 */
			struct
			{
				/* 0x0020 */ unsigned short reference_count;
			} /* size: 0x0002 */ e2;
			struct
			{
				/* 0x0020 */ unsigned long entire_field;
			} /* size: 0x0004 */ e4;
		}; /* size: 0x0004 */
	} /* size: 0x0004 */ u3;
	/* 0x0024 */ struct _mipfn_ulong5_t u5;
	union
	{
		union
		{
			struct /* bitfield */
			{
				/* 0x0028 */ unsigned __int64 pte_frame : 40; /* bit position: 0 */
				/* 0x0028 */ unsigned __int64 resident_page : 1; /* bit position: 40 */
				/* 0x0028 */ unsigned __int64 unused1 : 1; /* bit position: 41 */
				/* 0x0028 */ unsigned __int64 unused2 : 1; /* bit position: 42 */
				/* 0x0028 */ unsigned __int64 partition : 10; /* bit position: 43 */
				/* 0x0028 */ unsigned __int64 file_only : 1; /* bit position: 53 */
				/* 0x0028 */ unsigned __int64 pfn_exists : 1; /* bit position: 54 */
				/* 0x0028 */ unsigned __int64 node_flink_high : 5; /* bit position: 55 */
				/* 0x0028 */ unsigned __int64 page_identity : 3; /* bit position: 60 */
				/* 0x0028 */ unsigned __int64 prototype_pte : 1; /* bit position: 63 */
			}; /* bitfield */
			/* 0x0028 */ unsigned __int64 entire_field;
		}; /* size: 0x0008 */
	} /* size: 0x0008 */ u4;
} mmpfn_t, * pmmpfn_t; /* size: 0x0030 */

typedef union _pte_t
{
	unsigned __int64 value;
	struct
	{
		unsigned __int64 present : 1;          // Must be 1, region invalid if 0.
		unsigned __int64 rw : 1;               // If 0, writes not allowed.
		unsigned __int64 user_supervisor : 1;  // If 0, user-mode accesses not allowed. 
		unsigned __int64 page_write : 1;        // Determines the memory type used to access the memory.
		unsigned __int64 page_cache : 1;       // Determines the memory type used to access the memory.
		unsigned __int64 accessed : 1;         // If 0, this entry has not been used for translation.
		unsigned __int64 dirty : 1;             // If 0, the memory backing this page has not been written to.
		unsigned __int64 page_access_type : 1;  // Determines the memory type used to access the memory.
		unsigned __int64 global : 1;            // If 1 and the PGE bit of CR4 is set, translations are global.
		unsigned __int64 ignored2 : 3;
		unsigned __int64 pfn : 36;             // The page frame number of the backing physical page.
		unsigned __int64 reserved : 4;
		unsigned __int64 ignored3 : 7;
		unsigned __int64 protect_key : 4;       // If the PKE bit of CR4 is set, determines the protection key.
		unsigned __int64 nx : 1;               // If 1, instruction fetches not allowed.
	};
} pte_t, * ppte_t;

typedef struct _dbkd_debug_data_header_t {
	LIST_ENTRY64    list;
	ULONG           owner_tag;
	ULONG           size;
} dbkd_debug_data_header_t, * pdbkd_debug_data_header_t;

typedef struct _kd_debugger_data_t {

	dbkd_debug_data_header_t header;

	//
	// Base address of kernel image
	//

	ULONG64 kernel_base;

	//
	// DbgBreakPointWithStatus is a function which takes an argument
	// and hits a breakpoint. This field contains the address of the
	// breakpoint instruction. When the debugger sees a breakpoint
	// at this address, it may retrieve the argument from the first
	// argument register, or on x86 the eax register.
	//

	ULONG64 breakpoint_with_status; // address of breakpoint

	//
	// Address of the saved context record during a bugcheck
	//
	// N.B. This is an automatic in KeBugcheckEx's frame, and
	// is only valid after a bugcheck.
	//

	ULONG64 saved_context;

	//
	// help for walking stacks with user callbacks:
	//

	//
	// The address of the thread structure is provided in the
	// WAIT_STATE_CHANGE packet. This is the offset from the base of
	// the thread structure to the pointer to the kernel stack frame
	// for the currently active usermode callback.
	//

	USHORT thread_callback_stack; // offset in thread data

	//
	// these values are offsets into that frame:
	//

	USHORT next_callback;           // saved pointer to next callback frame
	USHORT frame_pointer;           // saved frame pointer

	//
	// pad to a quad boundary
	//
	USHORT pae_enabled : 1;
	USHORT ki_bug_check_recovery_active : 1; // Windows 10 Manganese Addition
	USHORT paging_levels : 4;

	//
	// Address of the kernel callout routine.
	//

	ULONG64 ki_call_user_mode; // kernel routine

	//
	// Address of the usermode entry point for callbacks.
	//

	ULONG64 ke_user_callback_dispatcher; // address in ntdll

	//
	// Addresses of various kernel data structures and lists
	// that are of interest to the kernel debugger.
	//

	ULONG64 ps_loaded_module_list;
	ULONG64 ps_active_process_head;
	ULONG64 psp_cid_table;

	ULONG64 exp_system_resources_list;
	ULONG64 exp_paged_pool_descriptor;
	ULONG64 exp_number_of_paged_pools;

	ULONG64 ke_time_increment;
	ULONG64 ke_bug_check_callback_list_head;
	ULONG64 ki_bugcheck_data;

	ULONG64 iop_error_log_list_head;

	ULONG64 obp_root_directory_object;
	ULONG64 obp_type_object_type;

	ULONG64 mm_system_cache_start;
	ULONG64 mm_system_cache_end;
	ULONG64 mm_system_cache_ws;

	ULONG64 mm_pfn_database;
	ULONG64 mm_system_ptes_start;
	ULONG64 mm_system_ptes_end;
	ULONG64 mm_subsection_base;
	ULONG64 mm_number_of_paging_files;

	ULONG64 mm_lowest_physical_page;
	ULONG64 mm_highest_physical_page;
	ULONG64 mm_number_of_physical_pages;

	ULONG64 mm_maximum_non_paged_pool_in_bytes;
	ULONG64 mm_non_paged_system_start;
	ULONG64 mm_non_paged_pool_start;
	ULONG64 mm_non_paged_pool_end;

	ULONG64 mm_paged_pool_start;
	ULONG64 mm_paged_pool_end;
	ULONG64 mm_paged_pool_information;
	ULONG64 mm_page_size;

	ULONG64 mm_size_of_paged_pool_in_bytes;

	ULONG64 mm_total_commit_limit;
	ULONG64 mm_total_committed_pages;
	ULONG64 mm_shared_commit;
	ULONG64 mm_driver_commit;
	ULONG64 mm_process_commit;
	ULONG64 mm_paged_pool_commit;
	ULONG64 mm_extended_commit;

	ULONG64 mm_zeroed_page_list_head;
	ULONG64 mm_free_page_list_head;
	ULONG64 mm_standby_page_list_head;
	ULONG64 mm_modified_page_list_head;
	ULONG64 mm_modified_no_write_page_list_head;
	ULONG64 mm_available_pages;
	ULONG64 mm_resident_available_pages;

	ULONG64 pool_track_table;
	ULONG64 non_paged_pool_descriptor;

	ULONG64 mm_highest_user_address;
	ULONG64 mm_system_range_start;
	ULONG64 mm_user_probe_address;

	ULONG64 kd_print_circular_buffer;
	ULONG64 kd_print_circular_buffer_end;
	ULONG64 kd_print_write_pointer;
	ULONG64 kd_print_rollover_count;

	ULONG64 mm_loaded_user_image_list;

	// NT 5.1 Addition

	ULONG64 nt_build_lab;
	ULONG64 ki_normal_system_call;

	// NT 5.0 hotfix addition

	ULONG64 ki_processor_block;
	ULONG64 mm_unloaded_drivers;
	ULONG64 mm_last_unloaded_driver;
	ULONG64 mm_triage_action_taken;
	ULONG64 mm_special_pool_tag;
	ULONG64 kernel_verifier;
	ULONG64 mm_verifier_data;
	ULONG64 mm_allocated_non_paged_pool;
	ULONG64 mm_peak_commitment;
	ULONG64 mm_total_commit_limit_maximum;
	ULONG64 cm_nt_csd_version;

	// NT 5.1 Addition

	ULONG64 mm_physical_memory_block;
	ULONG64 mm_session_base;
	ULONG64 mm_session_size;
	ULONG64 mm_system_parent_table_page;

	// Server 2003 addition

	ULONG64 mm_virtual_translation_base;

	USHORT offset_k_thread_next_processor;
	USHORT offset_k_thread_teb;
	USHORT offset_k_thread_kernel_stack;
	USHORT offset_k_thread_initial_stack;

	USHORT offset_k_thread_apc_process;
	USHORT offset_k_thread_state;
	USHORT offset_k_thread_b_store;
	USHORT offset_k_thread_b_store_limit;

	USHORT size_e_process;
	USHORT offset_e_process_peb;
	USHORT offset_e_process_parent_cid;
	USHORT offset_e_process_directory_table_base;

	USHORT size_prcb;
	USHORT offset_prcb_dpc_routine;
	USHORT offset_prcb_current_thread;
	USHORT offset_prcb_mhz;

	USHORT offset_prcb_cpu_type;
	USHORT offset_prcb_vendor_string;
	USHORT offset_prcb_proc_state_context;
	USHORT offset_prcb_number;

	USHORT size_e_thread;

	UCHAR l1tf_high_physical_bit_index; // Windows 10 19H1 Addition
	UCHAR l1tf_swizzle_bit_index;      // Windows 10 19H1 Addition

	ULONG padding_0;

	ULONG64 kd_print_circular_buffer_ptr;
	ULONG64 kd_print_buffer_size;

	ULONG64 ke_loader_block;

	USHORT size_pcr;
	USHORT offset_pcr_self_pcr;
	USHORT offset_pcr_current_prcb;
	USHORT offset_pcr_contained_prcb;

	USHORT offset_pcr_initial_b_store;
	USHORT offset_pcr_b_store_limit;
	USHORT offset_pcr_initial_stack;
	USHORT offset_pcr_stack_limit;

	USHORT offset_prcb_pcr_page;
	USHORT offset_prcb_proc_state_special_reg;
	USHORT gdt_r0_code;
	USHORT gdt_r0_data;

	USHORT gdt_r0_pcr;
	USHORT gdt_r3_code;
	USHORT gdt_r3_data;
	USHORT gdt_r3_teb;

	USHORT gdt_ldt;
	USHORT gdt_tss;
	USHORT gdt_64_r3_cm_code;
	USHORT gdt_64_r3_cm_teb;

	ULONG64 iop_num_triage_dump_data_blocks;
	ULONG64 iop_triage_dump_data_blocks;

	// Longhorn addition

	ULONG64 vf_crash_data_block;
	ULONG64 mm_bad_pages_detected;
	ULONG64 mm_zeroed_page_single_bit_errors_detected;

	// Windows 7 addition

	ULONG64 etwp_debugger_data;
	USHORT offset_prcb_context;

	// Windows 8 addition

	USHORT offset_prcb_max_breakpoints;
	USHORT offset_prcb_max_watchpoints;

	ULONG offset_k_thread_stack_limit;
	ULONG offset_k_thread_stack_base;
	ULONG offset_k_thread_queue_list_entry;
	ULONG offset_e_thread_irp_list;

	USHORT offset_prcb_idle_thread;
	USHORT offset_prcb_normal_dpc_state;
	USHORT offset_prcb_dpc_stack;
	USHORT offset_prcb_isr_stack;

	USHORT size_kdpc_stack_frame;

	// Windows 8.1 Addition

	USHORT offset_k_pri_queue_thread_list_head;
	USHORT offset_k_thread_wait_reason;

	// Windows 10 RS1 Addition

	USHORT padding_1;
	ULONG64 pte_base;

	// Windows 10 RS5 Addition

	ULONG64 retpoline_stub_function_table;
	ULONG retpoline_stub_function_table_size;
	ULONG retpoline_stub_offset;
	ULONG retpoline_stub_size;

	// Windows 10 Iron Addition

	USHORT offset_e_process_mm_hot_patch_context;

	// Windows 11 Cobalt Addition

	ULONG offset_k_thread_shadow_stack_limit;
	ULONG offset_k_thread_shadow_stack_base;
	ULONG64 shadow_stack_enabled;

	// Windows 11 Nickel Addition

	ULONG64 pointer_auth_mask;
	USHORT offset_prcb_exception_stack;

} kd_debugger_data_t, * pkd_debugger_data_t;

typedef struct _dump_header_t
{
	ULONG signature;
	ULONG valid_dump;
	ULONG major_version;
	ULONG minor_version;
	ULONG_PTR directory_table_base;
	ULONG_PTR pfn_data_base;
	PLIST_ENTRY ps_loaded_module_list;
	PLIST_ENTRY ps_active_process_head;
	ULONG machine_image_type;
	ULONG number_processors;
	ULONG bug_check_code;
	ULONG_PTR bug_check_parameter1;
	ULONG_PTR bug_check_parameter2;
	ULONG_PTR bug_check_parameter3;
	ULONG_PTR bug_check_parameter4;
	CHAR version_user[32];
	struct _kd_debugger_data_t* kd_debugger_data_block;
} dump_header_t, * pdump_header_t;

#ifndef _WIN64
#define KDDEBUGGER_DATA_OFFSET 0x1068
#else
#define KDDEBUGGER_DATA_OFFSET 0x2080
#endif

#ifndef _WIN64
#define DUMP_BLOCK_SIZE 0x20000
#else
#define DUMP_BLOCK_SIZE 0x40000
#endif

typedef union
{
	struct
	{
		UINT64 reserved1 : 3;

		/**
		 * @brief Page-level Write-Through
		 *
		 * [Bit 3] Controls the memory type used to access the first paging structure of the current paging-structure hierarchy.
		 * This bit is not used if paging is disabled, with PAE paging, or with 4-level paging if CR4.PCIDE=1.
		 *
		 * @see Vol3A[4.9(PAGING AND MEMORY TYPING)]
		 */
		UINT64 page_level_write_through : 1;
#define CR3_PAGE_LEVEL_WRITE_THROUGH_BIT                             3
#define CR3_PAGE_LEVEL_WRITE_THROUGH_FLAG                            0x08
#define CR3_PAGE_LEVEL_WRITE_THROUGH_MASK                            0x01
#define CR3_PAGE_LEVEL_WRITE_THROUGH(_)                              (((_) >> 3) & 0x01)

		/**
		 * @brief Page-level Cache Disable
		 *
		 * [Bit 4] Controls the memory type used to access the first paging structure of the current paging-structure hierarchy.
		 * This bit is not used if paging is disabled, with PAE paging, or with 4-level paging2 if CR4.PCIDE=1.
		 *
		 * @see Vol3A[4.9(PAGING AND MEMORY TYPING)]
		 */
		UINT64 page_level_cache_disable : 1;
#define CR3_PAGE_LEVEL_CACHE_DISABLE_BIT                             4
#define CR3_PAGE_LEVEL_CACHE_DISABLE_FLAG                            0x10
#define CR3_PAGE_LEVEL_CACHE_DISABLE_MASK                            0x01
#define CR3_PAGE_LEVEL_CACHE_DISABLE(_)                              (((_) >> 4) & 0x01)
		UINT64 reserved2 : 7;

		/**
		 * @brief Address of page directory
		 *
		 * [Bits 47:12] Physical address of the 4-KByte aligned page directory (32-bit paging) or PML4 table (64-bit paging) used
		 * for linear-address translation.
		 *
		 * @see Vol3A[4.3(32-BIT PAGING)]
		 * @see Vol3A[4.5(4-LEVEL PAGING)]
		 */
		UINT64 address_of_page_directory : 36;
#define CR3_ADDRESS_OF_PAGE_DIRECTORY_BIT                            12
#define CR3_ADDRESS_OF_PAGE_DIRECTORY_FLAG                           0xFFFFFFFFF000
#define CR3_ADDRESS_OF_PAGE_DIRECTORY_MASK                           0xFFFFFFFFF
#define CR3_ADDRESS_OF_PAGE_DIRECTORY(_)                             (((_) >> 12) & 0xFFFFFFFFF)
		UINT64 reserved3 : 16;
	};

	UINT64 flags;
} cr3_t;

typedef struct _mmpfn {
	u64 flags;
	u64 pte_address;
	u64 Unused_1;
	u64 Unused_2;
	u64 Unused_3;
	u64 Unused_4;
} _mmpfn;

typedef struct _cache_t {
	u64 address;
	u64 value;
}cache_t;

#endif