; Function Attrs: uwtable
define internal void @_ZNK11xalanc_1_1014FunctionConcat7executeERNS_21XPathExecutionContextEPNS_9XalanNodeENS_10XObjectPtrES5_PKN11xercesc_2_77LocatorE(ptr noalias nocapture writeonly sret(%"class.xercesc_2_7::XMLMutex") align 8 %agg.result, ptr nocapture nonnull readnone align 8 %this, ptr noundef nonnull align 8 dereferenceable(24) %executionContext, ptr nocapture readnone %0, ptr nocapture noundef readonly %arg1, ptr nocapture noundef readonly %arg2, ptr nocapture readnone %1) unnamed_addr #3 align 2 personality ptr @__gxx_personality_v0 {
entry:
  %theResult.sroa.0.0.vec.insert = insertelement <2 x ptr> undef, ptr %executionContext, i64 0
  %vtable.i = load ptr, ptr %executionContext, align 8, !tbaa !2112
  %2 = getelementptr i8, ptr %vtable.i, i64 184
  %3 = load ptr, ptr %2, align 8
  %call.i = tail call noundef nonnull align 8 dereferenceable(36) ptr %3(ptr noundef nonnull align 8 dereferenceable(24) %executionContext)
  %theResult.sroa.0.8.vec.insert = insertelement <2 x ptr> %theResult.sroa.0.0.vec.insert, ptr %call.i, i64 1
  %4 = load ptr, ptr %arg1, align 8, !tbaa !5095
  %vtable = load ptr, ptr %4, align 8, !tbaa !2112
  %5 = getelementptr i8, ptr %vtable, i64 88
  %6 = load ptr, ptr %5, align 8
  invoke void %6(ptr noundef nonnull align 8 dereferenceable(24) %4, ptr noundef nonnull align 8 dereferenceable(36) %call.i)
          to label %invoke.cont5 unwind label %if.then.i11

invoke.cont5:                                     ; preds = %entry
  %7 = load ptr, ptr %arg2, align 8, !tbaa !5095
  %vtable8 = load ptr, ptr %7, align 8, !tbaa !2112
  %8 = getelementptr i8, ptr %vtable8, i64 88
  %9 = load ptr, ptr %8, align 8
  invoke void %9(ptr noundef nonnull align 8 dereferenceable(24) %7, ptr noundef nonnull align 8 dereferenceable(36) %call.i)
          to label %invoke.cont9 unwind label %if.then.i11

invoke.cont9:                                     ; preds = %invoke.cont5
  %m_xobjectFactory.i = getelementptr inbounds %"class.xalanc_1_10::XPathExecutionContext", ptr %executionContext, i64 0, i32 1
  %10 = load ptr, ptr %m_xobjectFactory.i, align 8, !tbaa !5343
  tail call void @llvm.experimental.noalias.scope.decl(metadata !6666)
  %m_xstringCachedAllocator.i = getelementptr inbounds %"class.xalanc_1_10::XObjectFactoryDefault", ptr %10, i64 0, i32 3
  %call.i.i3 = invoke noundef ptr @_ZN11xalanc_1_1022ReusableArenaAllocatorINS_13XStringCachedEE13allocateBlockEv(ptr noundef nonnull align 8 dereferenceable(41) %m_xstringCachedAllocator.i)
          to label %call.i.i.noexc unwind label %if.then.i11

call.i.i.noexc:                                   ; preds = %invoke.cont9
  %m_blocks.i.i.i = getelementptr inbounds %"class.xalanc_1_10::XObjectFactoryDefault", ptr %10, i64 0, i32 3, i32 0, i32 0, i32 2
  %11 = load ptr, ptr %m_blocks.i.i.i, align 8, !tbaa !6664, !noalias !6666
  %m_referenceCount.i.i.i.i.i.i = getelementptr inbounds %"class.xercesc_2_7::EndOfEntityException", ptr %call.i.i3, i64 0, i32 1
  store i32 0, ptr %m_referenceCount.i.i.i.i.i.i, align 8, !tbaa !5096, !noalias !6666
  %m_objectType.i.i.i.i.i = getelementptr inbounds %"class.xalanc_1_10::XObject", ptr %call.i.i3, i64 0, i32 1
  store i32 4, ptr %m_objectType.i.i.i.i.i, align 4, !tbaa !5354, !noalias !6666
  %m_factory.i.i.i.i.i = getelementptr inbounds %"class.xalanc_1_10::XObject", ptr %call.i.i3, i64 0, i32 2
  store ptr null, ptr %m_factory.i.i.i.i.i, align 8, !tbaa !6063, !noalias !6666
  %m_cachedNumberValue.i.i.i.i = getelementptr inbounds %"class.xalanc_1_10::XStringBase", ptr %call.i.i3, i64 0, i32 1
  store double 0.000000e+00, ptr %m_cachedNumberValue.i.i.i.i, align 8, !tbaa !6064, !noalias !6666
  %m_resultTreeFrag.i.i.i.i = getelementptr inbounds %"class.xalanc_1_10::XStringBase", ptr %call.i.i3, i64 0, i32 2
  store ptr getelementptr ([31 x ptr], ptr @_ZTVN11xalanc_1_1026XObjectResultTreeFragProxyE.0, i64 0, i64 2), ptr %m_resultTreeFrag.i.i.i.i, align 8, !tbaa !2112, !noalias !6666
  %m_proxy.i.i.i.i.i = getelementptr inbounds %"class.xalanc_1_10::XStringBase", ptr %call.i.i3, i64 0, i32 2, i32 1
  store ptr getelementptr ([39 x ptr], ptr @_ZTVN11xalanc_1_1030XObjectResultTreeFragProxyTextE.0, i64 0, i64 2), ptr %m_proxy.i.i.i.i.i, align 8, !tbaa !2112, !noalias !6666
  %m_value.i.i.i.i.i.i = getelementptr inbounds %"class.xalanc_1_10::XStringBase", ptr %call.i.i3, i64 0, i32 2, i32 1, i32 1
  store ptr %call.i.i3, ptr %m_value.i.i.i.i.i.i, align 8, !tbaa !2161, !noalias !6666
  %m_MemoryManager.i.i.i.i.i.i = getelementptr inbounds %"class.xalanc_1_10::XStringBase", ptr %call.i.i3, i64 0, i32 2, i32 1, i32 2
  store ptr %11, ptr %m_MemoryManager.i.i.i.i.i.i, align 8, !tbaa !2161, !noalias !6666
  store ptr getelementptr inbounds ([19 x ptr], ptr @_ZTVN11xalanc_1_1013XStringCachedE.0, i64 0, i64 2), ptr %call.i.i3, align 8, !tbaa !2112, !noalias !6666
  %m_value.i.i.i = getelementptr inbounds %"class.xalanc_1_10::XStringCached", ptr %call.i.i3, i64 0, i32 1
  store <2 x ptr> %theResult.sroa.0.8.vec.insert, ptr %m_value.i.i.i, align 8, !tbaa !2161, !noalias !6666
  call void @_ZN11xalanc_1_1022ReusableArenaAllocatorINS_13XStringCachedEE16commitAllocationEPS1_(ptr noundef nonnull align 8 dereferenceable(41) %m_xstringCachedAllocator.i, ptr nonnull poison)
  store ptr %10, ptr %m_factory.i.i.i.i.i, align 8, !tbaa !6063, !noalias !6666
  store ptr %call.i.i3, ptr %agg.result, align 8, !tbaa !5095, !alias.scope !6666
  %12 = load i32, ptr %m_referenceCount.i.i.i.i.i.i, align 8, !tbaa !5096, !noalias !6666
  %inc.i.i = add i32 %12, 1
  store i32 %inc.i.i, ptr %m_referenceCount.i.i.i.i.i.i, align 8, !tbaa !5096, !noalias !6666
  ret void

if.then.i11:                                      ; preds = %invoke.cont9, %invoke.cont5, %entry
  %lpad.thr_comm20 = landingpad { ptr, i32 }
          cleanup
  %vtable.i9 = load ptr, ptr %executionContext, align 8, !tbaa !2112
  %13 = getelementptr i8, ptr %vtable.i9, i64 192
  %14 = load ptr, ptr %13, align 8
  %15 = icmp eq ptr %14, @_ZN11xalanc_1_1033StylesheetExecutionContextDefault19releaseCachedStringERNS_14XalanDOMStringE
  br i1 %15, label %16, label %17

16:                                               ; preds = %if.then.i11
  %m_stringCache.i.i9 = getelementptr inbounds %"class.xalanc_1_10::StylesheetExecutionContextDefault", ptr %executionContext, i64 0, i32 1, i32 8
  %call.i.i11 = invoke fastcc noundef zeroext i1 @_ZN11xalanc_1_1019XalanDOMStringCache7releaseERNS_14XalanDOMStringE(ptr noundef nonnull align 8 dereferenceable(120) %m_stringCache.i.i9, ptr noundef nonnull align 8 dereferenceable(36) %call.i)
          to label %_ZN11xalanc_1_1021XPathExecutionContext25GetAndReleaseCachedStringD2Ev.exit13 unwind label %terminate.lpad.i12

17:                                               ; preds = %if.then.i11
  %m_stringCache.i13 = getelementptr inbounds %"class.xalanc_1_10::XPathExecutionContextDefault", ptr %executionContext, i64 0, i32 8
  %call.i1415 = invoke fastcc noundef zeroext i1 @_ZN11xalanc_1_1019XalanDOMStringCache7releaseERNS_14XalanDOMStringE(ptr noundef nonnull align 8 dereferenceable(120) %m_stringCache.i13, ptr noundef nonnull align 8 dereferenceable(36) %call.i)
          to label %_ZN11xalanc_1_1021XPathExecutionContext25GetAndReleaseCachedStringD2Ev.exit13 unwind label %terminate.lpad.i12

terminate.lpad.i12:                               ; preds = %17, %16
  %18 = landingpad { ptr, i32 }
          catch ptr null
  %19 = extractvalue { ptr, i32 } %18, 0
  tail call fastcc void @__clang_call_terminate(ptr %19) #114
  unreachable

_ZN11xalanc_1_1021XPathExecutionContext25GetAndReleaseCachedStringD2Ev.exit13: ; preds = %17, %16
  %lpad.phi25 = phi { ptr, i32 } [ %lpad.thr_comm20, %17 ], [ %lpad.thr_comm20, %16 ]
  resume { ptr, i32 } %lpad.phi25
}

